#include "KOWGUI/Nodes/baseNode.h"

#include "KOWGUI/Nodes/group.h"
#include "KOWGUI/Nodes/rectangle.h"

using namespace KOWGUI;

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

BaseNode* BaseNode::SetId(std::string id) {
    mId = id;
    return this;
}

BaseNode* BaseNode::AddChildren(std::vector<void*> newChildren) {
    for(int i = 0; i < newChildren.size(); i++) {
        switch(((BaseNode*)newChildren[i])->mType) {
            case NodeType::group:
                AddChild((Group*)newChildren[i]);
                break;
            case NodeType::rectangle:
                AddChild((Rectangle*)newChildren[i]);
                break;
        }
    }

    return this;
}

int BaseNode::GetX() {
    return mX;
}

// Get screen X coordinate by adding X coordinates up the parent tree
int BaseNode::CalculateX() {
    int sumX = GetX();

    BaseNode* currentNode = (BaseNode*)this;

    while(currentNode->parent != nullptr) {
        currentNode = (BaseNode*)currentNode->parent;
        sumX += currentNode->GetX();
    }

    return sumX;
}

int BaseNode::GetY() {
    return mY;
}

// Get screen Y coordinate by adding Y coordinates up the parent tree
int BaseNode::CalculateY() {
    int sumY = GetY();

    BaseNode* currentNode = (BaseNode*)this;

    while(currentNode->parent != nullptr) {
        currentNode = (BaseNode*)currentNode->parent;
        sumY += currentNode->GetY();
    }

    return sumY;
}

int BaseNode::GetWidth() {
    return mWidth;
}

int BaseNode::GetHeight() {
    return mHeight;
}