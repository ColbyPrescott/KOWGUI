#ifndef KOWGUI_CLICKABLE_NODE_H
#define KOWGUI_CLICKABLE_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"
#include "KOWGUI/BaseNodes/interactability.h"

namespace KOWGUI {

    class Clickable : public BaseNode, public Interactability {
        private:
            // Called when input starts on node area
            void (*mpPressFunc)() = nullptr;
            // Called when input ends in node area
            void (*mpReleaseFunc)() = nullptr;
            // Called when continuous input re-enters node area
            void (*mpFocusFunc)() = nullptr;
            // Called when continuous input leaves node area
            void (*mpUnfocusFunc)() = nullptr;

            // Wait, everything about Clickable is base Interactability functionality, I'M GONNA NEED TO ADD VARIABLES TO THE SCUFFED UP interactability.h!!

            void CallPress();
            void CallRelease();
            void CallFocus();
            void CallUnfocus();

        public:
            Clickable() {mType = NodeType::clickable;}

            Clickable* SetX(int x) {BaseNode::SetX(x); return this;}
            Clickable* SetY(int y) {BaseNode::SetY(y); return this;}
            Clickable* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Clickable* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Clickable* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Clickable* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Clickable* SetId(std::string id) {BaseNode::SetId(id); return this;}
            Clickable* AddChildren(std::vector<void*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Clickable* SetPress(void (*callback)());
            Clickable* SetRelease(void (*callback)());
            Clickable* SetFocus(void (*callback)());
            Clickable* SetUnfocus(void (*callback)());

            Clickable* ClearPress();
            Clickable* ClearRelease();
            Clickable* ClearFocus();
            Clickable* ClearUnfocus();

            friend class GUI;
    };

}

#endif