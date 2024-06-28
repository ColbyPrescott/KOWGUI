#ifndef KOWGUI_N_SELECTED_NODE_H
#define KOWGUI_N_SELECTED_NODE_H

#include "KOWGUI/Nodes/Feedback/selected.h"

namespace KOWGUI {

    class NSelected : public Selected {
        public:
            NSelected* SetX(int x) {BaseNode::SetX(x); return this;}
            NSelected* SetY(int y) {BaseNode::SetY(y); return this;}
            NSelected* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            NSelected* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            NSelected* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            NSelected* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            NSelected* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            NSelected* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            NSelected* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            NSelected* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            NSelected* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            NSelected* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            bool GetFeedbackState() {return !Selected::GetFeedbackState();}
    };

}

#endif