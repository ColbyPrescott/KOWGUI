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

        std::string mID = undefinedString;
        std::string mShallowID = undefinedString;

        bool mDisabled = false;

        GUI* mpContainingGUI = nullptr;

        void LinkChild(BaseNode* child);
    
    public:
        // Value is set in constructors of derived classes so a void* can be interpreted as BaseNode,
        // have its type read, then get casted to the correct class
        NodeType mType;

        // TO DO Should these be of type BaseNode?
        void* parent = nullptr;
        std::vector<void*> children;
        // TO DO Should these three variables be public or accessed with friendship?

        // All of these BaseNode* returning functions need to be redefined in the derived classes
        virtual BaseNode* SetX(int x);
        virtual BaseNode* SetY(int y);
        virtual BaseNode* SetPosition(int x, int y);
        virtual BaseNode* SetWidth(int width);
        virtual BaseNode* SetHeight(int height);
        virtual BaseNode* SetSize(int width, int height);
        virtual BaseNode* SetID(std::string iD);
        // TO DO BaseNode* SetShallowId(std::string shallowId);
        virtual BaseNode* SetDisabled(bool disabled);
        // TO DO SetTick

        virtual BaseNode* AddChildren(std::vector<BaseNode*> newChildren);

        // Add one node under this node, returning the new node
        template <typename T>
        T* AddChild(T* newChild) {
            LinkChild(newChild);

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
        std::string GetID();
        // std::string GetShallowId();
        bool GetDisabled();

        // void* FindShallowId(std::string shallowId);

        friend class GUI;

    };

}

#endif