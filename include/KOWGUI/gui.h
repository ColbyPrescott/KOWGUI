#ifndef KOWGUI_GUI_H
#define KOWGUI_GUI_H

#include "KOWGUI/globalSystems.h"

#include "KOWGUI/color.h"

#include "KOWGUI/BaseNodes/baseNode.h"
#include "KOWGUI/BaseNodes/interactableBaseNode.h"
#include "KOWGUI/BaseNodes/visibleBaseNode.h"
#include "KOWGUI/Nodes/group.h"
#include "KOWGUI/Nodes/clickable.h"
#include "KOWGUI/Nodes/draggable.h"
#include "KOWGUI/Nodes/rectangle.h"


#include "v5.h"
#include "v5_vcs.h"

namespace KOWGUI {

    class GUI {
        private:
            vex::brain* mpVexBrain = nullptr;

            // Variables for processing screen input
            // Whether or not the screen was pressed in the last call of Tick()
            bool mPrevTickScreenPressed = false;
            // Whether or not input was inside the selected node in the last call of Tick()
            bool mPrevTickFocusedNode = false;
            // The node that continuing input had started on
            InteractableBaseNode* mpSelectedNode = nullptr;
            // Note the difference: A node can lose and regain "focus" as input moves around, but 
            // which node in particular is tracked by the currently "selected" or target node

        public:
            // Group node that every other node must be connected to for it to get processed
            Group* root = new Group;

            GUI(vex::brain& vexBrain);

            void Tick();

            friend class BaseNode;
    };

}

#endif