#ifndef KOWGUI_FOCUSED_NODE_H
#define KOWGUI_FOCUSED_NODE_H

#include "KOWGUI/BaseNodes/feedbackBaseNode.h"

namespace KOWGUI {

    class Focused : public FeedbackBaseNode {
        public:
            Focused* SetX(int x) {BaseNode::SetX(x); return this;}
            Focused* SetY(int y) {BaseNode::SetY(y); return this;}
            Focused* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Focused* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Focused* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Focused* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Focused* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Focused* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Focused* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Focused* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Focused* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Focused* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            bool GetFeedbackState();
    };

}

#endif