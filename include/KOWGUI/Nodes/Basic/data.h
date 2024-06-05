#ifndef KOWGUI_DATA_NODE_H
#define KOWGUI_DATA_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

#include <string>
#include <map>

namespace KOWGUI {

    class Data : public BaseNode {
        private:
            // TO DO std::shared_ptr<void>
            std::map<std::string, void*> mCustomProperties;

        public:
            Data* SetX(int x) {BaseNode::SetX(x); return this;}
            Data* SetY(int y) {BaseNode::SetY(y); return this;}
            Data* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Data* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Data* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Data* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Data* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Data* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Data* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Data* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Data* SetProperty(std::string name, void* value);
            void* GetProperty(std::string name);
    };

}

#endif