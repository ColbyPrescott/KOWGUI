#ifndef KOWGUI_COLUMN_NODE_H
#define KOWGUI_COLUMN_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    class Column : public BaseNode {
        private:
            // Number of pixels between child nodes
            int mSpacing = 0;

            // Whether or not child nodes should be equally scaled to fit within this node's height 
            bool mScaleToFit = false;

            void OrganizeUnique();
            void OrganizeUniform();

            void Tick();

        public:
            Column* SetX(int x) {BaseNode::SetX(x); return this;}
            Column* SetY(int y) {BaseNode::SetY(y); return this;}
            Column* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Column* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Column* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Column* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Column* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Column* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Column* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Column* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Column* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Column* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Column* SetSpacing(int spacing);
            Column* SetScaleToFit(bool scaleToFit);
    };

}

#endif