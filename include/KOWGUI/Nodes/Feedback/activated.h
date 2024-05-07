#ifndef KOWGUI_ACTIVATED_NODE_H
#define KOWGUI_ACTIVATED_NODE_H

#include "KOWGUI/BaseNodes/feedbackBaseNode.h"

namespace KOWGUI {

    class Activated : public FeedbackBaseNode {
        public:
            Activated* SetX(int x) {BaseNode::SetX(x); return this;}
            Activated* SetY(int y) {BaseNode::SetY(y); return this;}
            Activated* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Activated* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Activated* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Activated* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Activated* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Activated* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Activated* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Activated* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Activated* SetReversed(bool reversed) {FeedbackBaseNode::SetReversed(reversed); return this;}

            bool GetFeedbackState();
    };

}

#endif