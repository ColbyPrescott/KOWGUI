#ifndef KOWGUI_INTERACTABILITY_H
#define KOWGUI_INTERACTABILITY_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    class GUI;

    class InteractableBaseNode : public BaseNode {
        private:
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

        public:
            virtual InteractableBaseNode* SetPress(void (*callback)());
            virtual InteractableBaseNode* SetRelease(void (*callback)());
            virtual InteractableBaseNode* SetFocus(void (*callback)());
            virtual InteractableBaseNode* SetUnfocus(void (*callback)());

            virtual InteractableBaseNode* ClearPress();
            virtual InteractableBaseNode* ClearRelease();
            virtual InteractableBaseNode* ClearFocus();
            virtual InteractableBaseNode* ClearUnfocus();

            bool TestCollision(int x, int y);

            friend class GUI;
    };

}

#endif