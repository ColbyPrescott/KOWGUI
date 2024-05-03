#ifndef KOWGUI_GUI_H
#define KOWGUI_GUI_H

#include "KOWGUI/Nodes/Basic/group.h"

#include "v5.h"
#include "v5_vcs.h"

#include <string>
#include <map>

namespace KOWGUI {

    class BaseNode;
    class InteractableBaseNode;

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

            // Store a map of ID names to their node for quick retrieval
            std::map<std::string, BaseNode*> mpIDs;

            void AddIDMap(BaseNode* node);

        public:
            // Group node that every other node must be connected to for it to get processed
            Group* root = new Group;

            GUI(vex::brain& vexBrain);

            BaseNode* FindID(std::string iD);

            void Tick();

            friend class BaseNode;
            friend class Focused;
    };

}

#endif