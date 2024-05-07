#ifndef KOWGUI_N_ACTIVATED_NODE_H
#define KOWGUI_N_ACTIVATED_NODE_H

#include "KOWGUI/Nodes/Feedback/activated.h"

namespace KOWGUI {

    class NActivated : public Activated {
        public:
            NActivated* SetX(int x) {BaseNode::SetX(x); return this;}
            NActivated* SetY(int y) {BaseNode::SetY(y); return this;}
            NActivated* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            NActivated* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            NActivated* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            NActivated* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            NActivated* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            NActivated* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            NActivated* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            NActivated* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}
            
            bool GetFeedbackState() {return !Activated::GetFeedbackState();}
    };

}

#endif