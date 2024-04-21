#include "KOWGUI/Nodes/focused.h"

#include "KOWGUI/BaseNodes/interactableBaseNode.h"
#include "KOWGUI/gui.h"

using namespace KOWGUI;

// Get whether or not this node should soft disable itself based on whether a higher interactable is focused
bool Focused::GetFeedbackState() {
    // Climb tree until an interactable node is found
    BaseNode* currentNode = this;
    while(dynamic_cast<InteractableBaseNode*>(currentNode) == nullptr) {
        // Return default if top of tree was reached
        if(currentNode->parent == nullptr) return FeedbackBaseNode::GetFeedbackState();
        currentNode = (BaseNode*)currentNode->parent; 
    }

    // Return whether or not the interactable node is currently selected and focused
    return (GetContainingGUI()->mpSelectedNode == (InteractableBaseNode*)currentNode && GetContainingGUI()->mPrevTickFocusedNode) ^ mReversed;
}