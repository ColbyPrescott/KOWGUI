#include "KOWGUI/gui.h"

#include <vector>

using namespace KOWGUI;

GUI::GUI(vex::brain& vexBrain) {
    mpVexBrain = &vexBrain;

    root->SetSize(480, 240);
    root->mpContainingGUI = this;
}

// Render screen and detect inputs
void GUI::Tick() {
    // Clear screen for new frame
    mpVexBrain->Screen.clearScreen();

    // Nodes that still need exploring to filly recurse through tree
    std::vector<void*> remainingNodes = {root};
    // Collect pointers to every node in order of priority
    std::vector<void*> allNodes = {};



    // Draw and collect all nodes back to front
    while(remainingNodes.size() != 0) {
        // Get current node in a form where mType can be accessed
        BaseNode* currentNode = (BaseNode*)remainingNodes[0];

        // Insert currentNode children into the remainingNodes vector, back to front into index 1 to keep priority order of tree
        for(int i = currentNode->children.size() - 1; i >= 0; i--) remainingNodes.insert(remainingNodes.begin() + 1, currentNode->children[i]);

        // Run drawing functions associated with node
        VisibleBaseNode* visibleNode = dynamic_cast<VisibleBaseNode*>(currentNode);
        if(visibleNode != nullptr) visibleNode->Draw(mpVexBrain->Screen);

        // Move currentNode from remainingNodes into the allNodes vector
        allNodes.push_back(remainingNodes[0]);
        remainingNodes.erase(remainingNodes.begin());
    }



    // Loop through all nodes front to back to run input functions
    bool screenPressed = mpVexBrain->Screen.pressing();
    int screenX = mpVexBrain->Screen.xPosition();
    int screenY = mpVexBrain->Screen.yPosition();

    // If input just started, look for a node front to back to select
    if(screenPressed && !mPrevTickScreenPressed) 
    for(int i = allNodes.size() - 1; i >= 0; i--) {
        // Get current node in a form where mType can be accessed
        BaseNode* currentNode = (BaseNode*)allNodes[i];

        // Set selected and run input functions associated with interactable nodes
        InteractableBaseNode* interactableNode = dynamic_cast<InteractableBaseNode*>(currentNode);
        if(interactableNode != nullptr) {
            if(!interactableNode->TestCollision(screenX, screenY)) continue;
            mpSelectedNode = currentNode;
            mPrevTickFocusedNode = true;
            ((Clickable*)currentNode)->CallPress();
            ((Clickable*)currentNode)->CallFocus();
        }
        // switch(currentNode->mType) {
        //     case NodeType::clickable:
        //         if(!((Clickable*)currentNode)->TestCollision(screenX, screenY)) continue;
        //         mpSelectedNode = currentNode;
        //         mPrevTickFocusedNode = true;
        //         ((Clickable*)currentNode)->CallPress();
        //         ((Clickable*)currentNode)->CallFocus();
        //         break;
        //     default:
        //         break;
        // }

        // Stop searching through nodes if one got selected
        if(mpSelectedNode != nullptr) break;
    }

    // If node is selected, just process that
    // TO DO Should this ticking be moved to a function in an interactable class that interactables inherit and override?
    if(mpSelectedNode != nullptr) switch(mpSelectedNode->mType) {
        case NodeType::clickable: {
            if(((Clickable*)mpSelectedNode)->GetID() == "hackedDraggable") {
                ((Clickable*)mpSelectedNode)->SetX(screenX);
                ((Clickable*)mpSelectedNode)->SetY(screenY);
            }
            bool focused = ((Clickable*)mpSelectedNode)->TestCollision(screenX, screenY);
            if(!mPrevTickFocusedNode && focused) ((Clickable*)mpSelectedNode)->CallFocus();
            if(mPrevTickFocusedNode && !focused) ((Clickable*)mpSelectedNode)->CallUnfocus();
            mPrevTickFocusedNode = focused;
            break;
        }
        default:
            break;
    }

    // If input ended, run functions and remove selection
    if(mpSelectedNode != nullptr && !screenPressed && mPrevTickScreenPressed) switch(mpSelectedNode->mType) {
        case NodeType::clickable:
            if(((Clickable*)mpSelectedNode)->TestCollision(screenX, screenY)) {
                ((Clickable*)mpSelectedNode)->CallUnfocus();
                ((Clickable*)mpSelectedNode)->CallRelease();
            }
            mpSelectedNode = nullptr;
            mPrevTickFocusedNode = false;
            break;
        default:
            break;
    }

    mPrevTickScreenPressed = screenPressed;



    // Render screen to stop flickering
    mpVexBrain->Screen.render();
}