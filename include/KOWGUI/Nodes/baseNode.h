#ifndef KOWGUI_BASE_NODE_H
#define KOWGUI_BASE_NODE_H

#include "KOWGUI/globalSystems.h"

#include <string>
#include <vector>

namespace KOWGUI {

    class GUI;

    class BaseNode {
    protected:
        // X coordinate
        int mX = 0;
        // Y coordinate
        int mY = 0;
        // Width
        int mWidth = undefinedNumber;
        // Height
        int mHeight = undefinedNumber;

        std::string mId = undefinedString;
        std::string mShallowId = undefinedString;

        GUI* mpContainingGUI = nullptr;

        GUI* GetContainingGUI();
    
    public:
        // Value is set in constructors of derived classes so a void* can be interpreted as BaseNode,
        // have its type read, then get casted to the correct class
        NodeType mType;

        void* parent = nullptr;
        std::vector<void*> children;

        // All of these BaseNode* returning functions need to be redefined in the derived classes
        BaseNode* SetX(int x);
        BaseNode* SetY(int y);
        BaseNode* SetPosition(int x, int y);
        BaseNode* SetWidth(int width);
        BaseNode* SetHeight(int height);
        BaseNode* SetSize(int width, int height);
        BaseNode* SetId(std::string id);
        // BaseNode* SetShallowId(std::string shallowId);

        BaseNode* AddChildren(std::vector<void*> newChildren);

        template <typename T>
        T* AddChild(T* newChild) {
            ((BaseNode*)newChild)->parent = this;
            children.push_back(newChild);
            return newChild;
        }

        int GetX();
        int CalculateX();
        int GetY();
        int CalculateY();
        int GetWidth();
        int CalculateWidth();
        int GetHeight();
        int CalculateHeight();
        // std::string GetID();
        // std::string GetShallowId();

        // void* FindShallowId(std::string shallowId);

    };

}

#endif