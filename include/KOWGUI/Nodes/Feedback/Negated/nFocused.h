#ifndef KOWGUI_N_FOCUSED_NODE_H
#define KOWGUI_N_FOCUSED_NODE_H

#include "KOWGUI/Nodes/Feedback/focused.h"

namespace KOWGUI {

    class NFocused : public Focused {
        public:
            NFocused* SetX(int x) {BaseNode::SetX(x); return this;}
            NFocused* SetY(int y) {BaseNode::SetY(y); return this;}
            NFocused* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            NFocused* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            NFocused* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            NFocused* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            NFocused* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            NFocused* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            NFocused* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            NFocused* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            NFocused* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            NFocused* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            bool GetFeedbackState() {return !Focused::GetFeedbackState();}
    };

}

#endif