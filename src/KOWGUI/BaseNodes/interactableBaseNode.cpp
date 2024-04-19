#include "KOWGUI/BaseNodes/interactableBaseNode.h"

using namespace KOWGUI;

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