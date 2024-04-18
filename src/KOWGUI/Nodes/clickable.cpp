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

// Set the function to be called upon input sliding back onto node
Clickable* Clickable::SetFocus(void (*callback)()) {
    mpFocusFunc = callback;
    return this;
}

// Set the function to be called upon input sliding off of node
Clickable* Clickable::SetUnfocus(void (*callback)()) {
    mpUnfocusFunc = callback;
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

// Remove the function that would get called upon input sliding back onto node
Clickable* Clickable::ClearFocus() {
    mpFocusFunc = nullptr;
    return this;
}

// Remove the function that would get called upon input sliding off of node
Clickable* Clickable::ClearUnfocus() {
    mpUnfocusFunc = nullptr;
    return this;
}



// Get whether or not a screen coordinate intersects the node
bool Clickable::TestCollision(int x, int y) {
    return x > CalculateX() &&
           x < CalculateX() + CalculateWidth() &&
           y > CalculateY() &&
           y < CalculateY() + CalculateHeight();
}

void Clickable::CallPress() {
    if(mpPressFunc != nullptr) mpPressFunc();
}

void Clickable::CallRelease() {
    if(mpReleaseFunc != nullptr) mpReleaseFunc();
}

void Clickable::CallFocus() {
    if(mpFocusFunc != nullptr) mpFocusFunc();
}

void Clickable::CallUnfocus() {
    if(mpUnfocusFunc != nullptr) mpUnfocusFunc();
}