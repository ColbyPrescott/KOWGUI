#ifndef KOWGUI_INTERACTABLE_BASE_NODE_H
#define KOWGUI_INTERACTABLE_BASE_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    class InteractableBaseNode : public BaseNode {
        protected:
            // Called when input starts on node area
            void (*mpPressFunc)(BaseNode*) = nullptr;
            // Called when input ends in node area
            void (*mpReleaseFunc)(BaseNode*) = nullptr;
            // Called when continuous input re-enters node area
            void (*mpFocusFunc)(BaseNode*) = nullptr;
            // Called when continuous input leaves node area
            void (*mpUnfocusFunc)(BaseNode*) = nullptr;

            void CallPress();
            void CallRelease();
            void CallFocus();
            void CallUnfocus();

            // Derived node may do something unique with the press position
            virtual void TickPress(int x, int y) {};
            // Derived node may do something unique while input is being moved
            virtual void TickDrag(int x, int y) {};
            // Derived node may do something unique with the release position. Executes even if selected node wasn't focused. TO DO Rename this function to reflect that fact
            virtual void TickRelease(int x, int y) {};

        public:
            virtual InteractableBaseNode* SetPress(void (*callback)(BaseNode*));
            virtual InteractableBaseNode* SetRelease(void (*callback)(BaseNode*));
            virtual InteractableBaseNode* SetFocus(void (*callback)(BaseNode*));
            virtual InteractableBaseNode* SetUnfocus(void (*callback)(BaseNode*));

            // TO DO SetHover, gets called every tick that the node is in focus

            virtual InteractableBaseNode* ClearPress();
            virtual InteractableBaseNode* ClearRelease();
            virtual InteractableBaseNode* ClearFocus();
            virtual InteractableBaseNode* ClearUnfocus();

            bool TestCollision(int x, int y);

            friend class GUI;
    };

}

#endif