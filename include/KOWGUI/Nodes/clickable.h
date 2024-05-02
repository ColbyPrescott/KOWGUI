#ifndef KOWGUI_CLICKABLE_NODE_H
#define KOWGUI_CLICKABLE_NODE_H

#include "KOWGUI/BaseNodes/interactableBaseNode.h"

namespace KOWGUI {

    class Clickable : public InteractableBaseNode {
        public:
            Clickable() {mType = NodeType::clickable;}

            // TO DO Okay these bulky virtual functions are getting a tad bit out of hand... Surely there's SOME way to fix this, right?
            Clickable* SetX(int x) {BaseNode::SetX(x); return this;}
            Clickable* SetY(int y) {BaseNode::SetY(y); return this;}
            Clickable* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Clickable* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Clickable* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Clickable* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Clickable* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Clickable* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Clickable* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Clickable* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Clickable* SetPress(void (*callback)()) {InteractableBaseNode::SetPress(callback); return this;}
            Clickable* SetRelease(void (*callback)()) {InteractableBaseNode::SetRelease(callback); return this;}
            Clickable* SetFocus(void (*callback)()) {InteractableBaseNode::SetFocus(callback); return this;}
            Clickable* SetUnfocus(void (*callback)()) {InteractableBaseNode::SetUnfocus(callback); return this;}
            Clickable* ClearPress() {InteractableBaseNode::ClearPress(); return this;}
            Clickable* ClearRelease() {InteractableBaseNode::ClearRelease(); return this;}
            Clickable* ClearFocus() {InteractableBaseNode::ClearFocus(); return this;}
            Clickable* ClearUnfocus() {InteractableBaseNode::ClearUnfocus(); return this;}
    };

}

#endif