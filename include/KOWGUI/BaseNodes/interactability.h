#ifndef KOWGUI_INTERACTABILITY_H
#define KOWGUI_INTERACTABILITY_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    class Interactability {
        public:
            // TO DO Do NOT define any variables here. Interactability::TestCollision is REAL SCUFFED with the BaseNode cast

            bool TestCollision(int x, int y);
    };

}

#endif