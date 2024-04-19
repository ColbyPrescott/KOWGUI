#ifndef KOWGUI_VISIBLE_NODE_H
#define KOWGUI_VISIBLE_NODE_H

#include "v5.h"
#include "v5_vcs.h"

namespace KOWGUI {

    class Visibility {
        public:
            virtual void Draw(vex::brain::lcd& rScreen) {}
    };

}

#endif