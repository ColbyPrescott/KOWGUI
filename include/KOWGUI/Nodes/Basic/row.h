#ifndef KOWGUI_ROW_NODE_H
#define KOWGUI_ROW_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    class Row : public BaseNode {
        private:
            // Number of pixels between child nodes
            int mSpacing = 0;

            // Whether or not child nodes should be equally scaled to fit within this node's width 
            bool mScaleToFit = false;

            void OrganizeUnique();
            void OrganizeUniform();

            void Tick();

        public:
            Row* SetX(int x) {BaseNode::SetX(x); return this;}
            Row* SetY(int y) {BaseNode::SetY(y); return this;}
            Row* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Row* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Row* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Row* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Row* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Row* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Row* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Row* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Row* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Row* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Row* SetSpacing(int spacing);
            Row* SetScaleToFit(bool scaleToFit);
    };

}

#endif