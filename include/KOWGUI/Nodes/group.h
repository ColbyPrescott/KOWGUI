#ifndef KOWGUI_GROUP_NODE_H
#define KOWGUI_GROUP_NODE_H

#include "KOWGUI/globalSystems.h"
#include "KOWGUI/Nodes/baseNode.h"

namespace KOWGUI {

    class Group : public BaseNode {
        public:
            Group* SetX(int x) {BaseNode::SetX(x); return this;}
            Group* SetY(int y) {BaseNode::SetY(y); return this;}
            Group* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Group* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Group* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Group* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
    };

}

#endif