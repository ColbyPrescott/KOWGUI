#ifndef KOWGUI_UNFOCUSED_NODE_H
#define KOWGUI_UNFOCUSED_NODE_H

#include "KOWGUI/BaseNodes/feedbackBaseNode.h"

namespace KOWGUI {

    class Focused : public FeedbackBaseNode {
        public:
            Focused() {mType = NodeType::focused;}

            Focused* SetX(int x) {BaseNode::SetX(x); return this;}
            Focused* SetY(int y) {BaseNode::SetY(y); return this;}
            Focused* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Focused* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Focused* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Focused* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Focused* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Focused* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Focused* AddChildren(std::vector<void*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Focused* SetReversed(bool reversed) {FeedbackBaseNode::SetReversed(reversed); return this;}

            bool GetFeedbackState();
    };

}

#endif