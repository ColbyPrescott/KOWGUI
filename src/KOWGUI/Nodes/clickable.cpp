#include "KOWGUI/Nodes/clickable.h"

using namespace KOWGUI;

// Set the function to be called upon pressing down on the node
Clickable* Clickable::SetPress(void (*callback)()) {
    mpPressFunc = callback;
    return this;
}

// Set the function to be called upon releasing input from the node
Clickable* Clickable::SetRelease(void (*callback)()) {
    mpReleaseFunc = callback;
    return this;
}

// Remove the function that would get called upon pressing down on the node
Clickable* Clickable::ClearPress() {
    mpPressFunc = nullptr;
    return this;
}

// Remove the function that would get called upon releasing input from the node
Clickable* Clickable::ClearRelease() {
    mpReleaseFunc = nullptr;
    return this;
}



// Get whether or not a screen coordinate intersects the node
bool Clickable::TestCollision(int x, int y) {
    return x > CalculateX() &&
           x < CalculateX() + CalculateWidth() &&
           y > CalculateY() &&
           y < CalculateY() + CalculateHeight();
}

bool Clickable::TryPress(int x, int y) {
    if(!TestCollision(x, y)) return false;
    if(mpPressFunc != nullptr) mpPressFunc();
    return true;
}

bool Clickable::TryRelease(int x, int y) {
    if(!TestCollision(x, y)) return false;
    if(mpReleaseFunc != nullptr) mpReleaseFunc();
    return true;
}