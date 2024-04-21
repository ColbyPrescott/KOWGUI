#ifndef KOWGUI_VISIBLE_BASE_NODE_H
#define KOWGUI_VISIBLE_BASE_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

#include "v5.h"
#include "v5_vcs.h"

namespace KOWGUI {

    class VisibleBaseNode : public BaseNode {
        public:
            virtual void Draw(vex::brain::lcd& rScreen) {}
    };

}

#endif