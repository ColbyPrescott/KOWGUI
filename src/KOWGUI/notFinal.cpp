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

    };

    class Color {
        private:
            struct ColorSettings {
                int r = undefinedNumber;
                int g = undefinedNumber;
                int b = undefinedNumber;
                double h = undefinedNumber;
                double s = undefinedNumber;
                double v = undefinedNumber;
                std::string hex = undefinedString;
            };

        public:
            uint8_t r = 0;
            uint8_t g = 0;
            uint8_t b = 0;
            bool transparent = false;

            Color();
            Color(uint8_t r, uint8_t g, uint8_t b);
            Color(ColorSettings settings) {
                if(settings.r != undefinedNumber) r = settings.r;
                if(settings.g != undefinedNumber) g = settings.g;
                if(settings.b != undefinedNumber) b = settings.b;
                if(settings.h != undefinedNumber || settings.s != undefinedNumber || settings.v != undefinedNumber) SetHSV(settings.h, settings.s, settings.v);
            };

            void SetHSV(double h, double s, double v);
            void SetHex(std::string hex);

            vex::color GetVexColor();
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
        public:
            NodeType type; // Derived classes will overwrite from their constructor

            // Every node must have these properties in order for them to carry through 
            int x = 0;
            int y = 0;
            int width = 0;
            int height = 0;

            std::string id = undefinedString;
            std::string shallowId = undefinedString;

            std::vector<void*> children;

            // Get the X position from recursivly adding parent positions
            int GetScreenX();
            // Get the Y position from recursivly adding parent positions
            int GetScreenY();
            // Get internal width, or climb parent tree to last set width
            int GetWidth();
            // Get internal height, or climb parent tree to last set height
            int GetHeight();

            // Add a node to the end of the children vector and return a pointer to the new node
            void* AddChild(void* child);
            // Add multiple nodes to the end of the children vector and return a pointer to the original node
            void* AddChildren(std::vector<void*> childrenList);
    };

    class Rectangle : public BaseNode {
        private:
            struct RectangleSettings {
                int x = undefinedNumber;
                int y = undefinedNumber;
                int width = undefinedNumber;
                int height = undefinedNumber;
                std::string id = undefinedString;
                std::string shallowId = undefinedString;
                std::vector<void*> children;

                KOWGUI::Color* fillColor = nullptr;
                KOWGUI::Color* outlineColor = nullptr;
                int outlineWidth = undefinedNumber;
            };

        public:
            std::shared_ptr<KOWGUI::Color> fillColor = nullptr;
            std::shared_ptr<KOWGUI::Color> outlineColor = nullptr;
            int outlineWidth = 1;

            Rectangle() {
                type = NodeType::rectangle;
            }
            Rectangle(RectangleSettings settings) {
                if(settings.x != undefinedNumber) x = settings.x;
                if(settings.y != undefinedNumber) y = settings.y;
                if(settings.width != undefinedNumber) width = settings.width;
                if(settings.height != undefinedNumber) height = settings.height;
                if(settings.id != undefinedString) id = settings.id;
                if(settings.shallowId != undefinedString) shallowId = settings.shallowId;
                if(settings.fillColor != nullptr) fillColor = std::make_shared<KOWGUI::Color>(settings.fillColor);
                if(settings.outlineColor != nullptr) outlineColor = std::make_shared<KOWGUI::Color>(settings.outlineColor);
                if(settings.outlineWidth != undefinedNumber) outlineWidth = settings.outlineWidth;
            }

            void Draw(vex::brain::lcd& screen) {
                screen.setFillColor(fillColor->GetVexColor());
                screen.setPenColor(outlineColor->GetVexColor());
                screen.setPenWidth(outlineWidth);
                
                screen.drawRectangle(GetScreenX(), GetScreenY(), GetWidth(), GetHeight());
            }
    };

}


// USER SIDE OF CODE

// Global variable file

KOWGUI::GUI gui;

struct {
    
} panels;

struct {
    KOWGUI::Color primary = KOWGUI::Color(50, 50, 50);
} theme;


// Panels/home.cpp

void InitHomePanel() {
    KOWGUI::Rectangle* rect = new KOWGUI::Rectangle({
        .x = 50,
        .y = 50,
        .width = 200,
        .height = 150,
        .fillColor = &theme.primary
    });

    new KOWGUI::Rectangle({.x = 5});

    gui.root.AddChild(rect);

    rect->fillColor = new KOWGUI::Color({.h = 35, .s = 0.75, .v = 1.0}); // User will be responsible for deleting pointers like this...
                                                                         // User is NOT responsible for deleting pointers like this! Use an operator= function to
                                                                         // swoop in and convert this Color* to a std::shared_ptr<Color>

    delete rect; // Operator delete will remove invaid child pointer from gui.root

    
}


// Remaining issues:

/* Name of a basic node, one that has no functionality other than a position and child nodes. 
Transform, Static, Blank, Basic, Identity, Group, Container, Collection, Empty, Base? 
    Want something short and intuitive.
CONCLUSION: Group */ 

/* Concept of a shallow ID, being able to reuse an ID by associating it with a unique IDed parent. 
Shallow, Local?
Should Node.GetShallowID("name") ONLY look through direct children? 
Should it recursivley look through children of children? 
If it always recurses, should a shallow ID exist separately from a normal ID? 
    Only looking through direct children would be fast, but could create long chains of the same function call.
    Could be slow if search is recursive. Still probably not bad if it's meant to be "shallow."
    Shallow and normal ID should be kept separate. Normal IDs could be stored in a map on the GUI object which shallow is a realtime search
CONCLUSION: Normal IDs are fast and single use while shallow IDs are slow and multi-use. */

/* Should node children be stored as a std::shared_ptr or std::unique_ptr? What might happen
if two nodes are exact copies except for the nodes calling them a child? 
    The nodes won't be able to have a parent pointer since they can't be changed between copies...
    All of the node children will also be exact copies, meaning you can't even change text...
CONCLUSION: Node children should be stored as std::unique_ptr. Do not make clones like this. */