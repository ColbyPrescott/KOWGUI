#ifndef KOWGUI_SELECTED_NODE_H
#define KOWGUI_SELECTED_NODE_H

#include "KOWGUI/BaseNodes/feedbackBaseNode.h"

namespace KOWGUI {

    class Selected : public FeedbackBaseNode {
        public:
            Selected* SetX(int x) {BaseNode::SetX(x); return this;}
            Selected* SetY(int y) {BaseNode::SetY(y); return this;}
            Selected* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Selected* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Selected* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Selected* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Selected* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Selected* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Selected* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Selected* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Selected* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Selected* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            bool GetFeedbackState();
    };

}

#endif