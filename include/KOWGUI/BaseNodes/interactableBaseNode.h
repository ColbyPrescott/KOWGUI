#ifndef KOWGUI_INTERACTABILITY_H
#define KOWGUI_INTERACTABILITY_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    class InteractableBaseNode : public BaseNode {
        public:
            bool TestCollision(int x, int y);
    };

}

#endif