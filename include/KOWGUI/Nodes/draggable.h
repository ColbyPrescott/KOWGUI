#ifndef KOWGUI_DRAGGABLE_NODE_H
#define KOWGUI_DRAGGABLE_NODE_H

#include "KOWGUI/BaseNodes/interactableBaseNode.h"

namespace KOWGUI {

    class Draggable : public InteractableBaseNode {
        private:
            // Where on the node X input starts
            int mOffsetX = 0;
            // Where on the node Y input starts
            int mOffsetY = 0;

            int mMinX = undefinedNumber;
            int mMinY = undefinedNumber;
            int mMaxX = undefinedNumber;
            int mMaxY = undefinedNumber;

            void TickPress(int x, int y);
            void TickDrag(int x, int y);

        public:
            Draggable() {mType = NodeType::draggable;}

            Draggable* SetX(int x) {BaseNode::SetX(x); return this;}
            Draggable* SetY(int y) {BaseNode::SetY(y); return this;}
            Draggable* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Draggable* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Draggable* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Draggable* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Draggable* SetId(std::string id) {BaseNode::SetId(id); return this;}
            Draggable* AddChildren(std::vector<void*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Draggable* SetPress(void (*callback)()) {InteractableBaseNode::SetPress(callback); return this;}
            Draggable* SetRelease(void (*callback)()) {InteractableBaseNode::SetRelease(callback); return this;}
            Draggable* SetFocus(void (*callback)()) {InteractableBaseNode::SetFocus(callback); return this;}
            Draggable* SetUnfocus(void (*callback)()) {InteractableBaseNode::SetUnfocus(callback); return this;}
            Draggable* ClearPress() {InteractableBaseNode::ClearPress(); return this;}
            Draggable* ClearRelease() {InteractableBaseNode::ClearRelease(); return this;}
            Draggable* ClearFocus() {InteractableBaseNode::ClearFocus(); return this;}
            Draggable* ClearUnfocus() {InteractableBaseNode::ClearUnfocus(); return this;}

            Draggable* SetMinX(int x);
            Draggable* SetMinY(int y);
            Draggable* SetMaxX(int x);
            Draggable* SetMaxY(int y);
            Draggable* SetRange(int minX, int minY, int maxX, int maxY);
    };

}

#endif