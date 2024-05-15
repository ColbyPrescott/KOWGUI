#ifndef KOWGUI_LOOPED_NODE_H
#define KOWGUI_LOOPED_NODE_H

#include "KOWGUI/BaseNodes/feedbackBaseNode.h"

#include <vector>

namespace KOWGUI {

    class Looped : public FeedbackBaseNode {
        private:
            // Modulo divisor, how many states there are before repeating
            int mLoopLength = 2;
            // List of states that will be seen as activated
            std::vector<int> mLoopTargets;

        public:
            Looped* SetX(int x) {BaseNode::SetX(x); return this;}
            Looped* SetY(int y) {BaseNode::SetY(y); return this;}
            Looped* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Looped* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Looped* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Looped* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Looped* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Looped* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Looped* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Looped* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Looped* SetLoopLength(int loopLength);
            Looped* SetLoopTarget(int loopTarget);
            Looped* SetLoopTargets(std::vector<int> loopTargets);

            bool GetFeedbackState();
    };

}

#endif