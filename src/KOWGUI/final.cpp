#include <stdint.h>
#include <string>
#include <memory>
#include <vector>
#include "vex.h"

// KOWGUI



namespace KOWGUI {

    int undefinedNumber = -1;
    std::string undefinedString = "";


    class GUI {
        public:
            Group* root = new Group;

            void* FindId(std::string id); // Maybe try finding a way to alter the return type based on the node the ID is associated with?
    };

    class Color {
        private:
            uint8_t mR = 0;
            uint8_t mG = 0;
            uint8_t mB = 0;
            bool mTransparent = false;

        public:
            Color();

            Color* SetRGB(uint8_t red, uint8_t green, uint8_t blue);
            Color* SetHSV(double hue, double saturation, double value);
            Color* SetHex(std::string hex);
            Color* SetTransparent(bool transparent);

            uint8_t GetR();
            uint8_t GetG();
            uint8_t GetB();

            vex::color GetVexColor();

            static Color* red;
            // Color* Color::red = (new Color)->SetRGB(255, 0, 0); in cpp file
            static Color* green;
    };

    enum NodeType {
        // Other
        group,
        custom,
        
        // Interactable
        clickable,
        draggable,
        toggleable,

        // Interactable feedback
        unfocused,
        focused,
        activated,
        deactivated,

        // Visible
        rectangle,
        circle,
        line,
        text,
        image,
        polygon
    };

    class BaseNode {
        protected:
            NodeType mType; // Derived classes will overwrite from their constructor

            // Every node must have these properties in order for them to carry through the tree
            int mX = 0;
            int mY = 0;
            int mWidth = 0;
            int mHeight = 0;

            std::string mId = undefinedString;
            std::string mShallowId = undefinedString;

            std::vector<void*> mChildren;
        
        public:
            // Setters need to be defined in each derived class individually so the return type matches :/
            // If there's a way to do it with templates or something then it somehow escaped my research!
            // All of these BaseNode* returning functions need to be rewritten in the derived classes
            BaseNode* SetX(int x);
            BaseNode* SetY(int y);
            BaseNode* SetPosition(int x, int y);
            BaseNode* SetWidth(int width);
            BaseNode* SetHeight(int height);
            BaseNode* SetSize(int width, int height);
            BaseNode* SetId(std::string id);
            BaseNode* SetShallowId(std::string shallowId);

            void* AddChild(void* child);
            BaseNode* AddChildren(std::vector<void*> children);

            int GetX();
            int CalculateX();
            int GetY();
            int CalculateY();
            int GetWidth();
            int CalculateWidth();
            int GetHeight();
            int CalculateHeight();
            std::string GetID();
            std::string GetShallowId();

            void* FindShallowId(std::string shallowId);

    };

    class Group : public BaseNode {
        public:
            Group() {
                mType = NodeType::group;
            }

            Group* SetX(int _x) {BaseNode::SetX(_x); return this;}
            Group* SetY(int _y) {BaseNode::SetY(_y); return this;}
            Group* SetPosition(int _x, int _y) {BaseNode::SetPosition(_x, _y); return this;}
            Group* SetWidth(int _width) {BaseNode::SetWidth(_width); return this;}
            Group* SetHeight(int _height) {BaseNode::SetHeight(_height); return this;}
            Group* SetSize(int _width, int _height) {BaseNode::SetSize(_width, _height); return this;}
            Group* SetID(std::string _id) {BaseNode::SetId(_id); return this;}
            Group* SetShallowId(std::string _shallowId) {BaseNode::SetShallowId(_shallowId); return this;}
            Group* AddChildren(std::vector<void*> _children) {BaseNode::AddChildren(_children); return this;}
    };

    class Rectangle : public BaseNode {
        public:
            std::shared_ptr<Color> fillColor = nullptr;
            std::shared_ptr<Color> outlineColor = nullptr;
            int outlineWidth = 1;

            Rectangle() {
                mType = NodeType::rectangle;
            }

            Rectangle* SetX(int _x) {BaseNode::SetX(_x); return this;}
            Rectangle* SetY(int _y) {BaseNode::SetY(_y); return this;}
            Rectangle* SetPosition(int _x, int _y) {BaseNode::SetPosition(_x, _y); return this;}
            Rectangle* SetWidth(int _width) {BaseNode::SetWidth(_width); return this;}
            Rectangle* SetHeight(int _height) {BaseNode::SetHeight(_height); return this;}
            Rectangle* SetSize(int _width, int _height) {BaseNode::SetSize(_width, _height); return this;}
            Rectangle* SetID(std::string _id) {BaseNode::SetId(_id); return this;}
            Rectangle* SetShallowId(std::string _shallowId) {BaseNode::SetShallowId(_shallowId); return this;}
            Rectangle* AddChildren(std::vector<void*> _children) {BaseNode::AddChildren(_children); return this;}

            Rectangle* SetFillColor(Color* _fillColor);
            Rectangle* SetOutlineColor(Color* _outlineColor);
            Rectangle* SetOutlineWidth(int _outlineWidth);

            void Draw(vex::brain::lcd& screen) {
                screen.setFillColor(fillColor->GetVexColor());
                screen.setPenColor(outlineColor->GetVexColor());
                screen.setPenWidth(outlineWidth);
                
                screen.drawRectangle(CalculateX(), CalculateY(), CalculateWidth(), CalculateHeight());
            }
    };

}


// USER SIDE OF CODE

// Global variable file

KOWGUI::GUI gui;

struct {
    KOWGUI::Group* home = nullptr;
} panels;

struct {
    KOWGUI::Color* primary = (new KOWGUI::Color)->SetRGB(100, 100, 100);
} theme;


// Panels/home.cpp

void InitHomePanel() {
    KOWGUI::Rectangle* rect = (new KOWGUI::Rectangle)->
        SetPosition(50, 50)->
        SetSize(200, 150)->
        SetFillColor(theme.primary);

    gui.root->AddChild(rect);

    rect->SetFillColor((new KOWGUI::Color)->SetHSV(35, 0.75, 1));

    delete rect; // Operator delete will remove invaid child pointer from gui.root

    
    panels.home = (KOWGUI::Group*)gui.root->AddChild((new KOWGUI::Group)->AddChildren({
        (new KOWGUI::Rectangle)->SetPosition(0, 0)->SetSize(480, 50)->SetFillColor(KOWGUI::Color::red),
        (new KOWGUI::Toggleable)->SetPosition(50, 100)->SetSize(100, 50)->AddChildren({
            (new KOWGUI::Rectangle)->SetFillColor(theme.primary)->SetOutlineColor((new KOWGUI::Color)->SetHex("#ffffff"))->SetOutlineWidth(2),
            (new KOWGUI::Deactivated)->AddChildren({(new KOWGUI::Rectangle)->SetWidth(50)->SetFillColor(KOWGUI::Color::red)}),
            (new KOWGUI::Activated)->AddChildren({(new KOWGUI::Rectangle)->SetX(50)->SetWidth(50)->SetFillColor(KOWGUI::Color::green)})
        }),
        (new KOWGUI::Text)->
            SetPosition(200, 100)->
            SetText("Hewwo :D")->
            SetHorizontalCentering(true)
    }));

}



// Remaining issues:

/* Should the interactable feedback classes have a position and size?
CONCLUSION: In order to make position and size calculations easier, yes */