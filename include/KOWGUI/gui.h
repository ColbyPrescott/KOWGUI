#ifndef KOWGUI_GUI_H
#define KOWGUI_GUI_H

#include "KOWGUI/globalSystems.h"

#include "KOWGUI/color.h"

#include "KOWGUI/BaseNodes/baseNode.h"
#include "KOWGUI/BaseNodes/interactableBaseNode.h"
#include "KOWGUI/BaseNodes/visibleBaseNode.h"
#include "KOWGUI/Nodes/group.h"
#include "KOWGUI/Nodes/clickable.h"
#include "KOWGUI/Nodes/rectangle.h"


#include "v5.h"
#include "v5_vcs.h"

namespace KOWGUI {

    class GUI {
        private:
            vex::brain* mpVexBrain = nullptr;

            bool mPrevTickScreenPressed = false;
            BaseNode* mpSelectedNode = nullptr;
            bool mPrevTickFocusedNode = false;

        public:
            Group* root = new Group;

            GUI(vex::brain& vexBrain);

            void Tick();

            friend class BaseNode;
    };

}

#endif