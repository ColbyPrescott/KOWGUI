#include "KOWGUI/BaseNodes/baseNode.h"

#include "KOWGUI/General/gui.h"

#include <iostream>

using namespace KOWGUI;

// Call internal preTick function if it's not nullptr
void BaseNode::CallPreTick() {
    if(mpPreTickFunc != nullptr) mpPreTickFunc(this);
}

// Hook up connections between a new child node, its parent, and the GUI object
void BaseNode::LinkChild(BaseNode* child) {
    // TO DO Add check to prevent linking a node that is already linked. Should this throw an error or attempt to duplicate the node?

    // Link pointers between child and parent
    child->parent = this;
    children.push_back(child);

    // If this node has containing GUI, pass it to children recursivley
    if(mpContainingGUI != nullptr) {
        std::vector<BaseNode*> remainingNodes = {child};
        while(remainingNodes.size() > 0) {
            // Push children nodes of current node into remainingNodes
            for(int i = 0; i < remainingNodes[0]->children.size(); i++) remainingNodes.push_back(remainingNodes[0]->children[i]);
            // Set containingGUI on current node
            remainingNodes[0]->mpContainingGUI = mpContainingGUI;
            // Inform GUI object about the new node, setting up its ID
            if(remainingNodes[0]->mID != "") mpContainingGUI->AddIDMap(remainingNodes[0]);
            // Finished with current node, remove it from remainingNodes
            remainingNodes.erase(remainingNodes.begin()); 
        }
    }
}



// Set the X coordinate
BaseNode* BaseNode::SetX(int x) {
    mX = x;
    return this;
}

// Set the Y coordinate
BaseNode* BaseNode::SetY(int y) {
    mY = y;
    return this;
}

// Set both the X and Y coordinates
BaseNode* BaseNode::SetPosition(int x, int y) {
    SetX(x);
    SetY(y);
    return this;
}

// Set the width
BaseNode* BaseNode::SetWidth(int width) {
    mWidth = width;
    return this;
}

// Set the height
BaseNode* BaseNode::SetHeight(int height) {
    mHeight = height;
    return this;
}

// Set both the width and the height
BaseNode* BaseNode::SetSize(int width, int height) {
    SetWidth(width);
    SetHeight(height);
    return this;
}

// Set identifier for this node so it can be referenced later more easily
BaseNode* BaseNode::SetID(std::string iD) {
    // TO DO Remove previous ID
    mID = iD;
    return this;
}

// Set the multi-use identifier. Must be accessed from calling FindShallowID on a parent node
BaseNode* BaseNode::SetShallowID(std::string shallowID) {
    mShallowID = shallowID;
    return this;
}

// Set the function to be called in GUI::Tick() before rest of node is processed
BaseNode* BaseNode::SetPreTick(void (*callback)(BaseNode*)) {
    mpPreTickFunc = callback;
    return this;
}

// Set whether or not this and child nodes should be processed
BaseNode* BaseNode::SetDisabled(bool disabled) {
    mDisabled = disabled;
    return this;
}



// Remove the function that would get called in GUI::Tick() before rest of node is processed
BaseNode* BaseNode::ClearPreTick() {
    mpPreTickFunc = nullptr;
    return this;
}



// Add a vector of new nodes under this node, returning this node
BaseNode* BaseNode::AddChildren(std::vector<BaseNode*> newChildren) {
    for(int i = 0; i < newChildren.size(); i++) {
        LinkChild(newChildren[i]);
    }

    return this;
}



// Get internal X coordinate
int BaseNode::GetX() {
    return mX;
}

// Get screen X coordinate by adding X coordinates up the parent tree
int BaseNode::CalculateX() {
    int sumX = GetX();

    BaseNode* currentNode = this;

    while(currentNode->parent != nullptr) {
        currentNode = currentNode->parent;
        sumX += currentNode->GetX();
    }

    return sumX;
}

// Get internal Y coordinate
int BaseNode::GetY() {
    return mY;
}

// Get screen Y coordinate by adding Y coordinates up the parent tree
int BaseNode::CalculateY() {
    int sumY = GetY();

    BaseNode* currentNode = this;

    while(currentNode->parent != nullptr) {
        currentNode = currentNode->parent;
        sumY += currentNode->GetY();
    }

    return sumY;
}

// Get internal width
int BaseNode::GetWidth() {
    return mWidth;
}

// Climb tree until a node's width is defined
int BaseNode::CalculateWidth() {
    BaseNode* currentNode = this;

    while(currentNode->GetWidth() == undefinedNumber && currentNode->parent != nullptr) {
        currentNode = currentNode->parent;
    }

    return currentNode->GetWidth();
}

// Get internal height
int BaseNode::GetHeight() {
    return mHeight;
}

// Climb tree until a node's height is defined
int BaseNode::CalculateHeight() {
    BaseNode* currentNode = this;

    while(currentNode->GetHeight() == undefinedNumber && currentNode->parent != nullptr) {
        currentNode = currentNode->parent;
    }

    return currentNode->GetHeight();
}

// Get internal ID
std::string BaseNode::GetID() {
    return mID;
}

// Get internal shallow ID
std::string BaseNode::GetShallowID() {
    return mShallowID;
}

// Get internal disabled state
bool BaseNode::GetDisabled() {
    return mDisabled;
}



BaseNode* BaseNode::FindShallowID(std::string shallowID) {
    std::vector<BaseNode*> remainingNodes = {this};

    while(remainingNodes.size() > 0) {
        // Return node if the shallow ID was found
        if(remainingNodes[0]->mShallowID == shallowID) return remainingNodes[0];

        // Add child nodes to back of search. Deepest children will be explored last
        for(int i = 0; i < remainingNodes[0]->children.size(); i++) remainingNodes.push_back(remainingNodes[0]->children[i]);
        // This node has been explored
        remainingNodes.erase(remainingNodes.begin());
    }

    // Shallow ID was not found
    std::cerr << "KOWGUI: Could not find shallow ID " << shallowID << std::endl;
    vex::this_thread::sleep_for(5);
    return nullptr;
}