#include "KOWGUI/Nodes/Feedback/focused.h"

#include "KOWGUI/BaseNodes/interactableBaseNode.h"
#include "KOWGUI/General/gui.h"

using namespace KOWGUI;

// Get whether or not this node should soft disable itself based on whether a higher interactable is focused
bool Focused::GetFeedbackState() {
    // Climb tree until an interactable node is found
    BaseNode* currentNode = this;
    while(dynamic_cast<InteractableBaseNode*>(currentNode) == nullptr) {
        // Return default if top of tree was reached
        if(currentNode->parent == nullptr) return FeedbackBaseNode::GetFeedbackState();
        // Climb to parent node
        currentNode = currentNode->parent; 
    }

    // Return whether or not the interactable node is currently selected and focused
    return (mpContainingGUI->mpSelectedNode == (InteractableBaseNode*)currentNode && mpContainingGUI->mPrevTickFocusedNode) ^ mReversed;
}