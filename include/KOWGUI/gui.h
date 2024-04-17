#ifndef KOWGUI_GUI_H
#define KOWGUI_GUI_H

#include "KOWGUI/globalSystems.h"

#include "KOWGUI/color.h"

#include "KOWGUI/Nodes/baseNode.h"
#include "KOWGUI/Nodes/group.h"
#include "KOWGUI/Nodes/rectangle.h"


#include "v5.h"
#include "v5_vcs.h"

namespace KOWGUI {

    class GUI {
        private:
            vex::brain* mpVexBrain = nullptr;

        public:
            Group* root = new Group;

            GUI(vex::brain& vexBrain);

            void Tick();
    };

}

#endif