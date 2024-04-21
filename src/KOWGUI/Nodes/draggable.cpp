#include "KOWGUI/Nodes/draggable.h"

using namespace KOWGUI;

// Save where input started so it can be used as an offset while updating position
void Draggable::TickPress(int x, int y) {
    mOffsetX = x - mX;
    mOffsetY = y - mY;
}

// Move node around while it's being dragged
void Draggable::TickDrag(int x, int y) {
    SetPosition(x - mOffsetX, y - mOffsetY);
}