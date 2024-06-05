#ifndef KOWGUI_RECTANGLE_NODE_H
#define KOWGUI_RECTANGLE_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

#include "KOWGUI/General/color.h"

#include <memory>

namespace KOWGUI {

    class Rectangle : public VisibleBaseNode {
        private:
            // Color that fills in the rectangle
            std::shared_ptr<Color> mpFillColor = std::make_shared<Color>(*Color::transparent);
            // Color that borders the rectangle
            std::shared_ptr<Color> mpOutlineColor = std::make_shared<Color>(*Color::transparent);
            // How wide the border is in pixels
            int mOutlineWidth = 1;

        public:
            Rectangle* SetX(int x) {BaseNode::SetX(x); return this;}
            Rectangle* SetY(int y) {BaseNode::SetY(y); return this;}
            Rectangle* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Rectangle* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Rectangle* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Rectangle* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Rectangle* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Rectangle* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Rectangle* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Rectangle* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Rectangle* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Rectangle* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Rectangle* SetFillColor(Color* fillColor);
            Rectangle* SetOutlineColor(Color* outlineColor);
            Rectangle* SetOutlineWidth(int outlineWidth);

            void Draw(vex::brain::lcd& rScreen);
    };

}

#endif