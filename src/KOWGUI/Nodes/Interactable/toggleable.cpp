#include "KOWGUI/Nodes/Interactable/toggleable.h"

using namespace KOWGUI;

// Increment the click counter when a full press and release is registered
void Toggleable::TickRelease(int x, int y) {
    if(!TestCollision(x, y)) return;
    mClicks++;
}



// Set the click counter
Toggleable* Toggleable::SetClicks(int clicks) {
    mClicks = clicks;
    return this;
}

// Set the click counter to 0 or 1, off or on
Toggleable* Toggleable::SetActivated(bool activated) {
    mClicks = activated;
    return this;
}



// Get internal click counter
int Toggleable::GetClicks() {
    return mClicks;
}

// Get an on or off state from the internal click counter
bool Toggleable::GetActivated() {
    return mClicks % 2;
}