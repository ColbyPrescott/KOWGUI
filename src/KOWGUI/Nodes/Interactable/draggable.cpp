#include "KOWGUI/Nodes/Interactable/draggable.h"

using namespace KOWGUI;

// Save where input started so it can be used as an offset while updating position
void Draggable::TickPress(int x, int y) {
    mOffsetX = x - mX;
    mOffsetY = y - mY;
}

// Move node around while it's being dragged
void Draggable::TickDrag(int x, int y) {
    // Turn raw input coordinates into a form that considers parenting and initial press coordinate
    int newX = x - mOffsetX;
    int newY = y - mOffsetY;

    // Constrain position to be within set range
    if(mMinX != undefinedNumber && newX < mMinX) newX = mMinX;
    if(mMinY != undefinedNumber && newY < mMinY) newY = mMinY;
    if(mMaxX != undefinedNumber && newX > mMaxX - mWidth) newX = mMaxX - mWidth;
    if(mMaxY != undefinedNumber && newY > mMaxY - mHeight) newY = mMaxY - mHeight;

    // Update to new position
    SetPosition(newX, newY);
}



// Set the minimum X coordinate that the node can be dragged to
Draggable* Draggable::SetMinX(int x) {
    mMinX = x;
    return this;
}

// Set the minimum Y coordinate that the node can be dragged to
Draggable* Draggable::SetMinY(int y) {
    mMinY = y;
    return this;
}

// Set the maximum X coordinate that the right edge of the node can be dragged to
Draggable* Draggable::SetMaxX(int x) {
    mMaxX = x;
    return this;
}

// Set the maximum Y coordinate that the bottom edge of the node can be dragged to
Draggable* Draggable::SetMaxY(int y) {
    mMaxY = y;
    return this;
}

// Set region that node may be dragged within
Draggable* Draggable::SetRange(int minX, int minY, int maxX, int maxY) {
    SetMinX(minX);
    SetMinY(minY);
    SetMaxX(maxX);
    SetMaxY(maxY);
    return this;
}



// Return value 0 - 1 how far the node is from min and max X coordinate
double Draggable::GetPercentX() {
    if(mMinX == undefinedNumber || mMaxX == undefinedNumber) return 0;
    return (double)(mX - mMinX) / (mMaxX - mWidth - mMinX);
}

// Return value 0 - 1 how far the node is from min and max Y coordinate
double Draggable::GetPercentY() {
    if(mMinY == undefinedNumber || mMaxY == undefinedNumber) return 0;
    return (double)(mY - mMinY) / (mMaxY - mHeight - mMinY);
}