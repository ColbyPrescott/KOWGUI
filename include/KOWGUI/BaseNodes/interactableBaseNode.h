#ifndef KOWGUI_INTERACTABLE_BASE_NODE_H
#define KOWGUI_INTERACTABLE_BASE_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    class InteractableBaseNode : public BaseNode {
        protected:
            // Called when input starts on node area
            void (*mpPressFunc)() = nullptr;
            // Called when input ends in node area
            void (*mpReleaseFunc)() = nullptr;
            // Called when continuous input re-enters node area
            void (*mpFocusFunc)() = nullptr;
            // Called when continuous input leaves node area
            void (*mpUnfocusFunc)() = nullptr;

            void CallPress();
            void CallRelease();
            void CallFocus();
            void CallUnfocus();

            // Derived node may do something unique with the press position
            virtual void TickPress(int x, int y) {};
            // Derived node may do something unique while input is being moved
            virtual void TickDrag(int x, int y) {};
            // Derived node may do something unique with the release position. Executes even if selected node wasn't focused
            virtual void TickRelease(int x, int y) {};

        public:
            virtual InteractableBaseNode* SetPress(void (*callback)());
            virtual InteractableBaseNode* SetRelease(void (*callback)());
            virtual InteractableBaseNode* SetFocus(void (*callback)());
            virtual InteractableBaseNode* SetUnfocus(void (*callback)());

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