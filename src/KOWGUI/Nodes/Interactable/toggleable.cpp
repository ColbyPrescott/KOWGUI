#include "KOWGUI/Nodes/Interactable/toggleable.h"

using namespace KOWGUI;

void Toggleable::TickRelease(int x, int y) {
    if(!TestCollision(x, y)) return;
    mClicks++;
}



Toggleable* Toggleable::SetClicks(int clicks) {
    mClicks = clicks;
    return this;
}

Toggleable* Toggleable::SetActivated(bool activated) {
    mClicks = activated;
    return this;
}



int Toggleable::GetClicks() {
    return mClicks;
}

bool Toggleable::GetActivated() {
    return mClicks % 2;
}