#ifndef KOWGUI_LINE_NODE_H
#define KOWGUI_LINE_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

#include "KOWGUI/General/color.h"

#include <memory>

namespace KOWGUI {

    class Line : public VisibleBaseNode {
        private:
            int mLineWidth = 1;
            std::shared_ptr<Color> mpColor = Color::white; // Default transparent like rectangles?

        public:
            Line* SetX(int x) {BaseNode::SetX(x); return this;}
            Line* SetY(int y) {BaseNode::SetY(y); return this;}
            Line* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Line* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Line* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Line* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Line* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Line* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Line* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Line* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Line* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Line* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Line* SetX1(int x1);
            Line* SetY1(int y1);
            Line* SetPosition1(int x1, int y1);
            Line* SetX2(int x2);
            Line* SetY2(int y2);
            Line* SetPosition2(int x2, int y2);
            Line* SetPositions(int x1, int y1, int x2, int y2);

            Line* SetColor(std::shared_ptr<Color> color);
            Line* SetLineWidth(int lineWidth);

            void Draw(vex::brain::lcd& rScreen);
    };

}

#endif