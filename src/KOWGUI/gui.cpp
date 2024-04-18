#include "KOWGUI/gui.h"

#include <stdio.h>
#include <vector>

using namespace KOWGUI;

GUI::GUI(vex::brain& vexBrain) {
    mpVexBrain = &vexBrain;

    root->SetSize(480, 240);
    // Try using friend keyword
    // Stop working on the focusing here though and make a commit for working press function
    // root->mpContainingGUI = this;
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
        switch(currentNode->mType) {
            case NodeType::rectangle:
                ((Rectangle*)currentNode)->Draw(mpVexBrain->Screen);
                break;
            default:
                break;
        }

        // Move currentNode from remainingNodes into the allNodes vector
        allNodes.push_back(remainingNodes[0]);
        remainingNodes.erase(remainingNodes.begin());
    }

    // Write input code n stuff. 
    // Iterate through allNodes backwards to achieve front to back order
    // Copy KOWController button ticking here to detect press and release
    bool screenPressed = mpVexBrain->Screen.pressing();
    int screenX = mpVexBrain->Screen.xPosition();
    int screenY = mpVexBrain->Screen.yPosition();

    for(int i = allNodes.size() - 1; i >= 0; i--) {
        // Get current node in a form where mType can be accessed
        BaseNode* currentNode = (BaseNode*)allNodes[i];

        // Run input functions associated with node
        switch(currentNode->mType) {
            case NodeType::clickable:
                if(screenPressed && !mPrevTickScreenPressed) ((Clickable*)currentNode)->TryPress(screenX, screenY);
                if(!screenPressed && mPrevTickScreenPressed) ((Clickable*)currentNode)->TryRelease(screenX, screenY);
                break;
            default:
                break;
        }
    }

    mPrevTickScreenPressed = screenPressed;

    // Render screen to stop flickering
    mpVexBrain->Screen.render();
}