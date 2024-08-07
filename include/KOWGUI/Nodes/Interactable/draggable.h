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

            // Local minimum that the left edge can move
            int mMinX = undefinedNumber;
            // Local minumum that the top edge can move
            int mMinY = undefinedNumber;
            // Local maximum that the right edge can move
            int mMaxX = undefinedNumber;
            // Local maximum that the botton edge can move
            int mMaxY = undefinedNumber;

            void TickPress(int x, int y);
            void TickDrag(int x, int y);

        public:
            Draggable* SetX(int x) {BaseNode::SetX(x); return this;}
            Draggable* SetY(int y) {BaseNode::SetY(y); return this;}
            Draggable* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Draggable* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Draggable* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Draggable* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Draggable* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Draggable* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Draggable* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Draggable* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Draggable* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Draggable* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Draggable* SetPress(void (*callback)(BaseNode*)) {InteractableBaseNode::SetPress(callback); return this;}
            Draggable* SetRelease(void (*callback)(BaseNode*)) {InteractableBaseNode::SetRelease(callback); return this;}
            Draggable* SetFocus(void (*callback)(BaseNode*)) {InteractableBaseNode::SetFocus(callback); return this;}
            Draggable* SetUnfocus(void (*callback)(BaseNode*)) {InteractableBaseNode::SetUnfocus(callback); return this;}
            Draggable* ClearPress() {InteractableBaseNode::ClearPress(); return this;}
            Draggable* ClearRelease() {InteractableBaseNode::ClearRelease(); return this;}
            Draggable* ClearFocus() {InteractableBaseNode::ClearFocus(); return this;}
            Draggable* ClearUnfocus() {InteractableBaseNode::ClearUnfocus(); return this;}

            Draggable* SetMinX(int x);
            Draggable* SetMinY(int y);
            Draggable* SetMaxX(int x);
            Draggable* SetMaxY(int y);
            Draggable* SetRange(int minX, int minY, int maxX, int maxY);

            double GetPercentX();
            double GetPercentY();
    };

}

#endif