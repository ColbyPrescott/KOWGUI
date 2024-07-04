#include "TestGUI/panelManager.h"

#include "KOWGUI/kowgui.h"

#include "vex.h"
#include "globalVars.h"

#include "TestGUI/sidebar.h"

#include "TestGUI/panels.h"

#include <vector>
#include <string>

using namespace KOWGUI;

// To iterate through panels, store them in a vector as they're configured
std::vector<Group*> panelsVector;

Panels panels;

// Disable all panels and enable the chosen one
void LoadPanel(Group* panel) {
    for(int i = 0; i < panelsVector.size(); i++) panelsVector[i]->SetDisabled(true);

    panel->SetDisabled(false);
}

// Set up each panel group object, setting properties, adding it to appropriate arrays, and calling panel initialization function
void InitPanels() {
    void (*ConfigurePanel)(Group*) = [](Group* panel){
        gui.root->AddChild(panel->SetPosition(100, 0)->SetSize(480 - 100, 240));
        panelsVector.push_back(panel);
    };

    CreateSidebarLabel("Shapes");
    ConfigurePanel(panels.rectangleDemo);             InitGUIRectangleDemo();             CreateSidebarButton(panels.rectangleDemo,             "Rectangles");
    ConfigurePanel(panels.circleDemo);                InitGUICircleDemo();                CreateSidebarButton(panels.circleDemo,                "Circles");
    ConfigurePanel(panels.lineDemo);                  InitGUILineDemo();                  CreateSidebarButton(panels.lineDemo,                  "Lines");
    CreateSidebarLabel("Text");
    ConfigurePanel(panels.textFontDemo);              InitGUITextFontDemo();              CreateSidebarButton(panels.textFontDemo,              "Fonts");
    ConfigurePanel(panels.textFontAlignDemo);         InitGUITextFontAlignDemo();         CreateSidebarButton(panels.textFontAlignDemo,         "Font Align");
    ConfigurePanel(panels.textHorizontalAlignDemo);   InitGUITextHorizontalAlignDemo();   CreateSidebarButton(panels.textHorizontalAlignDemo,   "Horiz. Align");
    ConfigurePanel(panels.textVerticalAlignDemo);     InitGUITextVerticalAlignDemo();     CreateSidebarButton(panels.textVerticalAlignDemo,     "Vert. Align");
    ConfigurePanel(panels.textOverflowDemo);          InitGUITextOverflowDemo();          CreateSidebarButton(panels.textOverflowDemo,          "Overflow");
    CreateSidebarLabel("Interactables");
    ConfigurePanel(panels.clickableDemo);             InitGUIClickableDemo();             CreateSidebarButton(panels.clickableDemo,             "Clickables");
    ConfigurePanel(panels.draggableDemo);             InitGUIDraggableDemo();             CreateSidebarButton(panels.draggableDemo,             "Draggables");
    ConfigurePanel(panels.toggleableDemo);            InitGUIToggleableDemo();            CreateSidebarButton(panels.toggleableDemo,            "Toggleables");
    CreateSidebarLabel("Feedback");
    ConfigurePanel(panels.selectedDemo);              InitGUISelectedDemo();              CreateSidebarButton(panels.selectedDemo,              "Selected");
    ConfigurePanel(panels.focusedDemo);               InitGUIFocusedDemo();               CreateSidebarButton(panels.focusedDemo,               "Focused");
    ConfigurePanel(panels.activatedDemo);             InitGUIActivatedDemo();             CreateSidebarButton(panels.activatedDemo,             "Activated");
    ConfigurePanel(panels.loopedDemo);                InitGUILoopedDemo();                CreateSidebarButton(panels.loopedDemo,                "Looped");
    CreateSidebarLabel("Other Nodes");
    ConfigurePanel(panels.groupDemo);                 InitGUIGroupDemo();                 CreateSidebarButton(panels.groupDemo,                 "Groups");
    ConfigurePanel(panels.rowDemo);                   InitGUIRowDemo();                   CreateSidebarButton(panels.rowDemo,                   "Rows");
    CreateSidebarLabel("Prefabs");
    ConfigurePanel(panels.keyboardDemo);              InitGUIKeyboardDemo();              CreateSidebarButton(panels.keyboardDemo,              "Keyboards");
    CreateSidebarLabel("Other");
    ConfigurePanel(panels.colorDemo);                 InitGUIColorDemo();                 CreateSidebarButton(panels.colorDemo,                 "Colors");
    ConfigurePanel(panels.preTickDemo);               InitGUIPreTickDemo();               CreateSidebarButton(panels.preTickDemo,               "PreTick");
    ConfigurePanel(panels.removalDemo);               InitGUIRemovalDemo();               CreateSidebarButton(panels.removalDemo,               "Removal");
}