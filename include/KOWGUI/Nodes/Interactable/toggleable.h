#ifndef KOWGUI_TOGGLEABLE_NODE_H
#define KOWGUI_TOGGLEABLE_NODE_H

#include "KOWGUI/BaseNodes/interactableBaseNode.h"

namespace KOWGUI {

    class Toggleable : public InteractableBaseNode {
        private:
            // How many times the node has been clicked
            int mClicks = 0;

            void TickRelease(int x, int y);

        public:
            Toggleable* SetX(int x) {BaseNode::SetX(x); return this;}
            Toggleable* SetY(int y) {BaseNode::SetY(y); return this;}
            Toggleable* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Toggleable* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Toggleable* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Toggleable* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Toggleable* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Toggleable* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Toggleable* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Toggleable* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Toggleable* SetPress(void (*callback)()) {InteractableBaseNode::SetPress(callback); return this;}
            Toggleable* SetRelease(void (*callback)()) {InteractableBaseNode::SetRelease(callback); return this;}
            Toggleable* SetFocus(void (*callback)()) {InteractableBaseNode::SetFocus(callback); return this;}
            Toggleable* SetUnfocus(void (*callback)()) {InteractableBaseNode::SetUnfocus(callback); return this;}
            Toggleable* ClearPress() {InteractableBaseNode::ClearPress(); return this;}
            Toggleable* ClearRelease() {InteractableBaseNode::ClearRelease(); return this;}
            Toggleable* ClearFocus() {InteractableBaseNode::ClearFocus(); return this;}
            Toggleable* ClearUnfocus() {InteractableBaseNode::ClearUnfocus(); return this;}

            Toggleable* SetClicks(int clicks);
            Toggleable* SetActivated(bool activated);

            int GetClicks();
            bool GetActivated();
    };

}

#endif