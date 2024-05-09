#include "KOWGUI/Nodes/Feedback/activated.h"

#include "KOWGUI/Nodes/Interactable/toggleable.h"

using namespace KOWGUI;

// Get whether or not this node should soft disable itself based on whether a higher toggleable is activated
bool Activated::GetFeedbackState() {
    // Climb tree until a Toggleable node is found
    BaseNode* currentNode = this;
    while(dynamic_cast<Toggleable*>(currentNode) == nullptr) {
        // Return default if top of tree was reached
        if(currentNode->parent == nullptr) return false;
        // Climb to parent node
        currentNode = currentNode->parent; 
    }

    // Return whether or not the toggleable node is activated
    return ((Toggleable*)currentNode)->GetActivated();
}