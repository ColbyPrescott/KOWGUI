#ifndef KOWGUI_BASE_NODE_H
#define KOWGUI_BASE_NODE_H

#include "KOWGUI/General/globalSystems.h"

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

        // Unique identifier to find this node. GUI::FindID
        std::string mID = undefinedString;
        // Multi-use identifier for this node. BaseNode::FindShallowID
        std::string mShallowID = undefinedString;

        // Called in GUI::Tick() before any other processing
        void (*mpPreTickFunc)(BaseNode*) = nullptr;
        void CallPreTick();

        // Derived nodes may execute their own code each tick
        virtual void Tick() {};


        // Whether or not GUI::Tick should ignore this node
        bool mDisabled = false;

        // Pointer to the GUI object. All nodes have this for speed and convenience
        GUI* mpContainingGUI = nullptr;
        void LinkChild(BaseNode* child);
    
    public:
        ~BaseNode();

        // Node that this node is attatched to. Position and scale are inherited
        BaseNode* parent = nullptr;
        // All nodes that are attatched to this one
        std::vector<BaseNode*> children;
        // TO DO Should these three variables be public or accessed with friendship?

        // All of these BaseNode* returning functions need to be redefined in the derived classes
        virtual BaseNode* SetX(int x);
        virtual BaseNode* SetY(int y);
        virtual BaseNode* SetPosition(int x, int y);
        virtual BaseNode* SetWidth(int width);
        virtual BaseNode* SetHeight(int height);
        virtual BaseNode* SetSize(int width, int height);
        virtual BaseNode* SetID(std::string iD);
        virtual BaseNode* SetShallowID(std::string shallowID);
        virtual BaseNode* SetPreTick(void (*callback)(BaseNode*));
        virtual BaseNode* SetDisabled(bool disabled);

        virtual BaseNode* ClearPreTick();

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
        std::string GetShallowID();
        bool GetDisabled();

        BaseNode* FindShallowID(std::string shallowID);

        friend class GUI;

    };

}

#endif