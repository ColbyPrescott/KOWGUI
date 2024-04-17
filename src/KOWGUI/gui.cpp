#include "KOWGUI/gui.h"

#include <stdio.h>
#include <vector>

using namespace KOWGUI;

GUI::GUI(vex::brain& vexBrain) {
    mpVexBrain = &vexBrain;
}

// Render screen and detect inputs
void GUI::Tick() {
    // Recurse through tree
    std::vector<void*> remainingNodes = {root};

    while(remainingNodes.size() != 0) {
        // Get the highest priority node
        BaseNode* currentNode = (BaseNode*)remainingNodes[0];

        // Insert currentNode children into the remainingNodes vector
        // Insert back to front into index 1 to keep priority order of tree
        for(int i = currentNode->children.size() - 1; i >= 0; i--) {
            remainingNodes.insert(remainingNodes.begin() + 1, currentNode->children[i]);
        }

        // Run functionality associated with node
        switch(currentNode->mType) {
            case NodeType::group:
                break;
                
            case NodeType::rectangle:
                Rectangle* node = (Rectangle*)currentNode;
                node->Draw(mpVexBrain->Screen);
                break;
        }
        
        // Remove node from remainingNodes
        remainingNodes.erase(remainingNodes.begin());
    }
}