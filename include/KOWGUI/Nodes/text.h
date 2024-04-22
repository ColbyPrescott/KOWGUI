#ifndef KOWGUI_TEXT_NODE_H
#define KOWGUI_TEXT_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

namespace KOWGUI {

    class Text : public VisibleBaseNode {
        private:

        public:
            Text() {mType = NodeType::text;}

            Text* SetX(int x) {BaseNode::SetX(x); return this;}
            Text* SetY(int y) {BaseNode::SetY(y); return this;}
            Text* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Text* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Text* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Text* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Text* SetId(std::string id) {BaseNode::SetId(id); return this;}
            Text* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Text* AddChildren(std::vector<void*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            void Draw(vex::brain::lcd& rScreen);
    };

}

#endif