#include "KOWGUI/BaseNodes/interactability.h"

using namespace KOWGUI;

bool Interactability::TestCollision(int x, int y) {
    BaseNode* pScuff = (BaseNode*)this; // TO DO This assumes that the derived class inheriting this function first inherits BaseNode too. This sketchy cast is waiting to explode
    int xPos = pScuff->CalculateX();
    int yPos = pScuff->CalculateY();
    int width = pScuff->CalculateWidth();
    int height = pScuff->CalculateHeight();
    return x >= xPos &&
           x < xPos + width &&
           y >= yPos &&
           y < yPos + height;
}