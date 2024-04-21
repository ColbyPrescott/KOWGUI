#include "KOWGUI/Nodes/draggable.h"

using namespace KOWGUI;

// Move node around when it's being dragged
void Draggable::TickDrag(int x, int y) {
    SetPosition(x, y);
}