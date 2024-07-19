#ifndef KOWGUI_ROUNDED_RECTANGLE_NODE_H
#define KOWGUI_ROUNDED_RECTANGLE_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

#include "KOWGUI/General/color.h"

#include <memory>

namespace KOWGUI {

    class RoundedRectangle : public VisibleBaseNode {
        private:
            // Color that fills in the rectangle
            std::shared_ptr<Color> mpFillColor = Color::transparent;
            // Color that borders the rectangle
            std::shared_ptr<Color> mpOutlineColor = Color::transparent;
            // How wide the border is in pixels
            int mOutlineWidth = 1;

            // Radius of the rounded corners
            int mOutlineRadius = 0;
        
        public:
            RoundedRectangle* SetX(int x) {BaseNode::SetX(x); return this;}
            RoundedRectangle* SetY(int y) {BaseNode::SetY(y); return this;}
            RoundedRectangle* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            RoundedRectangle* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            RoundedRectangle* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            RoundedRectangle* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            RoundedRectangle* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            RoundedRectangle* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            RoundedRectangle* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            RoundedRectangle* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            RoundedRectangle* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            RoundedRectangle* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            RoundedRectangle* SetFillColor(std::shared_ptr<Color> fillColor);
            RoundedRectangle* SetOutlineColor(std::shared_ptr<Color> outlineColor);
            RoundedRectangle* SetOutlineWidth(int outlineWidth);
            RoundedRectangle* SetOutlineRadius(int outlineRadius);

            void Draw(vex::brain::lcd& rScreen);
    };

}

#endif