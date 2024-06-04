#include "KOWGUI/BaseNodes/interactableBaseNode.h"

using namespace KOWGUI;

// Call internal press function if it's not nullptr
void InteractableBaseNode::CallPress() {
    if(mpPressFunc != nullptr) mpPressFunc(this);
}

// Call internal release function if it's not nullptr
void InteractableBaseNode::CallRelease() {
    if(mpReleaseFunc != nullptr) mpReleaseFunc(this);
}

// Call internal focus function if it's not nullptr
void InteractableBaseNode::CallFocus() {
    if(mpFocusFunc != nullptr) mpFocusFunc(this);
}

// Call internal unfocus function if it's not nullptr
void InteractableBaseNode::CallUnfocus() {
    if(mpUnfocusFunc != nullptr) mpUnfocusFunc(this);
}



// Set the function to be called upon pressing down on the node
InteractableBaseNode* InteractableBaseNode::SetPress(void (*callback)(BaseNode*)) {
    mpPressFunc = callback;
    return this;
}

// Set the function to be called upon releasing input from the node
InteractableBaseNode* InteractableBaseNode::SetRelease(void (*callback)(BaseNode*)) {
    mpReleaseFunc = callback;
    return this;
}

// Set the function to be called upon input sliding back onto node
InteractableBaseNode* InteractableBaseNode::SetFocus(void (*callback)(BaseNode*)) {
    mpFocusFunc = callback;
    return this;
}

// Set the function to be called upon input sliding off of node
InteractableBaseNode* InteractableBaseNode::SetUnfocus(void (*callback)(BaseNode*)) {
    mpUnfocusFunc = callback;
    return this;
}

// Remove the function that would get called upon pressing down on the node
InteractableBaseNode* InteractableBaseNode::ClearPress() {
    mpPressFunc = nullptr;
    return this;
}

// Remove the function that would get called upon releasing input from the node
InteractableBaseNode* InteractableBaseNode::ClearRelease() {
    mpReleaseFunc = nullptr;
    return this;
}

// Remove the function that would get called upon input sliding back onto node
InteractableBaseNode* InteractableBaseNode::ClearFocus() {
    mpFocusFunc = nullptr;
    return this;
}

// Remove the function that would get called upon input sliding off of node
InteractableBaseNode* InteractableBaseNode::ClearUnfocus() {
    mpUnfocusFunc = nullptr;
    return this;
}



// Get whether or not a coordinate lies inside the node's area
bool InteractableBaseNode::TestCollision(int x, int y) {
    int xPos = CalculateX();
    int yPos = CalculateY();
    int width = CalculateWidth();
    int height = CalculateHeight();
    return x >= xPos &&
           x < xPos + width &&
           y >= yPos &&
           y < yPos + height;
}