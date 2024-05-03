#ifndef KOWGUI_CIRCLE_NODE_H
#define KOWGUI_CIRCLE_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

#include "KOWGUI/General/color.h"

#include <memory>

namespace KOWGUI {

    class Circle : public VisibleBaseNode {
        private:
            bool mCentered = false;

            std::shared_ptr<Color> mpFillColor = std::make_shared<Color>(*Color::transparent);
            std::shared_ptr<Color> mpOutlineColor = std::make_shared<Color>(*Color::transparent);
            int mOutlineWidth = 1;

        public:
            Circle* SetX(int x) {BaseNode::SetX(x); return this;}
            Circle* SetY(int y) {BaseNode::SetY(y); return this;}
            Circle* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Circle* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Circle* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Circle* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Circle* SetId(std::string id) {BaseNode::SetID(id); return this;}
            Circle* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Circle* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Circle* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Circle* SetCentered(bool centered);
            Circle* SetRadius(int radius);

            Circle* SetFillColor(Color* fillColor);
            Circle* SetOutlineColor(Color* outlineColor);
            Circle* SetOutlineWidth(int outlineWidth);

            void Draw(vex::brain::lcd& rScreen);
    };

}

#endif