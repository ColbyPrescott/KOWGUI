#ifndef KOWGUI_DATA_NODE_H
#define KOWGUI_DATA_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

#include <string>
#include <map>
#include <memory>

namespace KOWGUI {

    class Data : public BaseNode {
        private:
            std::map<std::string, std::shared_ptr<void>> mCustomProperties; // TO DO Should Data nodes hold a map of information or just one piece of data?

        public:
            Data* SetX(int x) {BaseNode::SetX(x); return this;}
            Data* SetY(int y) {BaseNode::SetY(y); return this;}
            Data* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Data* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Data* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Data* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Data* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Data* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Data* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Data* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Data* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Data* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Data* SetProperty(std::string name, std::shared_ptr<void> value);
            std::shared_ptr<void> GetProperty(std::string name);
            // TO DO Data::RemoveProperty(std::string name)
    };

}

#endif