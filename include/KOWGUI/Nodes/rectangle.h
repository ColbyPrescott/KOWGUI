#ifndef KOWGUI_RECTANGLE_NODE_H
#define KOWGUI_RECTANGLE_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"
#include "KOWGUI/color.h"

#include "v5.h"
#include "v5_vcs.h"

#include <memory>

namespace KOWGUI {

    class Rectangle : public VisibleBaseNode {
        private:
            std::shared_ptr<Color> mpFillColor = std::make_shared<Color>(*Color::transparent);
            std::shared_ptr<Color> mpOutlineColor = std::make_shared<Color>(*Color::transparent);
            int mOutlineWidth = 1;

        public:
            Rectangle() {mType = NodeType::rectangle;}

            Rectangle* SetX(int x) {BaseNode::SetX(x); return this;}
            Rectangle* SetY(int y) {BaseNode::SetY(y); return this;}
            Rectangle* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Rectangle* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Rectangle* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Rectangle* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Rectangle* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Rectangle* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Rectangle* AddChildren(std::vector<void*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Rectangle* SetFillColor(Color* fillColor);
            Rectangle* SetOutlineColor(Color* outlineColor);
            Rectangle* SetOutlineWidth(int outlineWidth);

            void Draw(vex::brain::lcd& rScreen);
    };

}

#endif