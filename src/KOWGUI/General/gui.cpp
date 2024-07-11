#include "KOWGUI/General/gui.h"

#include "KOWGUI/BaseNodes/baseNode.h"
#include "KOWGUI/BaseNodes/visibleBaseNode.h"
#include "KOWGUI/BaseNodes/interactableBaseNode.h"
#include "KOWGUI/BaseNodes/feedbackBaseNode.h"

#include <iostream>
#include <vector>

using namespace KOWGUI;

// GUI constructor. Initializes pointers and root node
GUI::GUI(vex::brain& vexBrain) {
    mpVexBrain = &vexBrain;

    root->SetSize(480, 240);
    root->mpContainingGUI = this;
}



// Add a node into the ID system
void GUI::AddIDMap(BaseNode* node) {
    // If ID name is already in map, throw a warning
    if(mpIDs.find(node->mID) != mpIDs.end()) {
        std::cerr << "KOWGUI: Could not set node to ID " << node->mID << " because another node already uses it. Consider ShallowID instead" << std::endl;
        vex::this_thread::sleep_for(5);
        return;
    }
    // Add ID to the map
    mpIDs[node->mID] = node;
}

// Remove a node from the ID system
void GUI::RemoveIDMap(std::string iD) {
    // If ID name isn't in map, throw a warning
    if(mpIDs.find(iD) == mpIDs.end()) {
        std::cerr << "KOWGUI: Could not remove non-existent ID " << iD << std::endl;
        vex::this_thread::sleep_for(5);
        return;
    }
    // Remove ID from the map
    mpIDs.erase(iD);
}



// Look up an ID in the ID system
BaseNode* GUI::FindID(std::string iD) {
    // If ID can be found in the map, return the node that the name is paired with
    if(mpIDs.find(iD) != mpIDs.end()) return mpIDs[iD];
    // Otherwise, throw warning
    std::cerr << "KOWGUI: Could not find ID " << iD << std::endl;
    vex::this_thread::sleep_for(5);
    return nullptr;
}

// TO DO Split this function into separate functions. The x3 empty line aren't helping much
// Render screen and detect inputs
void GUI::Tick() {
    // Clear screen for new frame
    mpVexBrain->Screen.clearScreen();

    // Nodes that still need exploring to fully recurse through tree
    std::vector<BaseNode*> remainingNodes = {root};
    // Collect pointers to every node in order of priority
    std::vector<BaseNode*> allNodes = {};



    // Forward process, preTick and draw, and collect all nodes back to front
    while(remainingNodes.size() != 0) {
        // Give the current node in the loop a name
        BaseNode* currentNode = remainingNodes[0];

        // Delete and skip current node if scheduled for deletion
        if(currentNode->mDeletionScheduled) {
            // Remove currentNode from remainingNodes vector
            remainingNodes.erase(remainingNodes.begin());
            // Clean up screen input variables
            if(mpSelectedNode == currentNode) {
                mpSelectedNode = nullptr;
                mPrevTickFocusedNode = false;
            }
            // Free memory
            delete currentNode;
            // Skip rest of node processing
            continue;
        }

        // Skip current node if disabled or soft disabled
        if(currentNode->GetDisabled() ||
          (dynamic_cast<FeedbackBaseNode*>(currentNode) != nullptr && !((FeedbackBaseNode*)currentNode)->GetFeedbackState())) {
            remainingNodes.erase(remainingNodes.begin());
            continue;
        }

        // Insert currentNode children into the remainingNodes vector, back to front into index 1 to keep priority order of tree
        for(int i = currentNode->children.size() - 1; i >= 0; i--) remainingNodes.insert(remainingNodes.begin() + 1, currentNode->children[i]);


        // Give node the chance to execute its own user defined code first, call preTick
        currentNode->CallPreTick();
        // Execute any code defined by the node's type
        currentNode->Tick();
        // Run drawing functions associated with node
        VisibleBaseNode* visibleNode = dynamic_cast<VisibleBaseNode*>(currentNode);
        if(visibleNode != nullptr) visibleNode->Draw(mpVexBrain->Screen);


        // Move currentNode from remainingNodes into the allNodes vector
        allNodes.push_back(remainingNodes[0]);
        remainingNodes.erase(remainingNodes.begin());
    }

    // All draw functions have been called back to front. Render screen to stop flickering
    mpVexBrain->Screen.render();



    // Process screen input on nodes front to back
    bool screenPressed = mpVexBrain->Screen.pressing();
    int screenX = mpVexBrain->Screen.xPosition();
    int screenY = mpVexBrain->Screen.yPosition();

    // If input just started, search front to back for a node to select
    if(screenPressed && !mPrevTickScreenPressed) for(int i = allNodes.size() - 1; i >= 0; i--) {
        // Give the current node in the loop a name
        BaseNode* currentNode = allNodes[i];

        // Skip and continue search if currentNode isn't interactable
        InteractableBaseNode* interactableNode = dynamic_cast<InteractableBaseNode*>(currentNode);
        if(interactableNode == nullptr) continue;

        // Skip and continue search if currentNode isn't the one being touched
        if(!interactableNode->TestCollision(screenX, screenY)) continue;


        // The current node has been selected! Store this information
        mpSelectedNode = interactableNode;
        // Focus function is getting called now, no need to do it again later
        mPrevTickFocusedNode = true;
        // Node is getting pressed and brought into focus, so execute the respective callback functions
        // Ensure TickPress is first function to know about the starting input
        interactableNode->TickPress(screenX, screenY);
        interactableNode->CallPress();
        interactableNode->CallFocus();
        // Search is complete, no need to do any more
        break;
    }

    // If a node is selected, process its moving and ending input
    if(mpSelectedNode != nullptr) {
        // Ensure TickDrag is first function to know about the moving input
        mpSelectedNode->TickDrag(screenX, screenY);

        // Get whether or not the selected node currently has input on it
        bool focused = mpSelectedNode->TestCollision(screenX, screenY);
        // If this is different from last call of Tick(), execute the respective callback
        if(!mPrevTickFocusedNode && focused) mpSelectedNode->CallFocus();
        if(mPrevTickFocusedNode && !focused) mpSelectedNode->CallUnfocus();
        // Push current focus state into memory so the comparison can be made again in next call of Tick()
        mPrevTickFocusedNode = focused;

        // If input ended, run functions and remove selection. Opposite order from how input begins, except for TickRelease
        if(!screenPressed && mPrevTickScreenPressed) {
            // Ensure TickRelease is first function to know about ending input
            mpSelectedNode->TickRelease(screenX, screenY);
            // If the node is currently focused, execute the appropriate callbacks to undo that
            if(focused) {
                mpSelectedNode->CallUnfocus();
                mpSelectedNode->CallRelease();
            }
            // The current node has been deselected so remove the pointer
            mpSelectedNode = nullptr;
            // Unfocus function was already called, no need to do it again later
            mPrevTickFocusedNode = false;
        }
    }

    // Push current screen press state into memory so the comparison can be made again in next call of Tick()
    mPrevTickScreenPressed = screenPressed;
}