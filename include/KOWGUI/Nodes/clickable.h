#ifndef KOWGUI_CLICKABLE_NODE_H
#define KOWGUI_CLICKABLE_NODE_H

#include "KOWGUI/Nodes/baseNode.h"

namespace KOWGUI {

    class Clickable : public BaseNode {
        private:
            // Called when input starts on node area
            void (*mpPressFunc)() = nullptr;
            // Called when input ends in node area
            void (*mpReleaseFunc)() = nullptr;
            // Called when continuous input leaves node area
            void (*mpFocusFunc)() = nullptr;
            // Called when continuous input re-enters node area
            void (*mpUnfocusFunc)() = nullptr;

        public:
            Clickable() {mType = NodeType::clickable;}

            Clickable* SetX(int x) {BaseNode::SetX(x); return this;}
            Clickable* SetY(int y) {BaseNode::SetY(y); return this;}
            Clickable* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Clickable* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Clickable* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Clickable* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Clickable* AddChildren(std::vector<void*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Clickable* SetPress(void (*callback)());
            Clickable* SetRelease(void (*callback)());

            Clickable* ClearPress();
            Clickable* ClearRelease();

            bool TestCollision(int x, int y);
            bool TryPress(int x, int y);
            bool TryRelease(int x, int y);
    };

}

#endif