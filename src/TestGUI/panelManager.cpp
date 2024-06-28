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

    ConfigurePanel(panels.groupDemo);                 InitGUIGroupDemo();                 CreateSidebarButton(panels.groupDemo,                 "Groups");
    ConfigurePanel(panels.colorDemo);                 InitGUIColorDemo();                 CreateSidebarButton(panels.colorDemo,                 "Colors");
    ConfigurePanel(panels.rectangleDemo);             InitGUIRectangleDemo();             CreateSidebarButton(panels.rectangleDemo,             "Rectangles");
    ConfigurePanel(panels.circleDemo);                InitGUICircleDemo();                CreateSidebarButton(panels.circleDemo,                "Circles");
    ConfigurePanel(panels.lineDemo);                  InitGUILineDemo();                  CreateSidebarButton(panels.lineDemo,                  "Lines");
    ConfigurePanel(panels.textFontDemo);              InitGUITextFontDemo();              CreateSidebarButton(panels.textFontDemo,              "Fonts");
    ConfigurePanel(panels.textFontAlignDemo);         InitGUITextFontAlignDemo();         CreateSidebarButton(panels.textFontAlignDemo,         "Font Align");
    ConfigurePanel(panels.textHorizontalAlignDemo);   InitGUITextHorizontalAlignDemo();   CreateSidebarButton(panels.textHorizontalAlignDemo,   "Horiz. Align");
    ConfigurePanel(panels.textVerticalAlignDemo);     InitGUITextVerticalAlignDemo();     CreateSidebarButton(panels.textVerticalAlignDemo,     "Vert. Align");
    ConfigurePanel(panels.textOverflowDemo);          InitGUITextOverflowDemo();          CreateSidebarButton(panels.textOverflowDemo,          "Overflow");
    ConfigurePanel(panels.rowDemo);                   InitGUIRowDemo();                   CreateSidebarButton(panels.rowDemo,                   "Rows");
    ConfigurePanel(panels.clickableDemo);             InitGUIClickableDemo();             CreateSidebarButton(panels.clickableDemo,             "Clickables");
    ConfigurePanel(panels.draggableDemo);             InitGUIDraggableDemo();             CreateSidebarButton(panels.draggableDemo,             "Draggables");
    ConfigurePanel(panels.toggleableDemo);            InitGUIToggleableDemo();            CreateSidebarButton(panels.toggleableDemo,            "Toggleables");
    ConfigurePanel(panels.preTickDemo);               InitGUIPreTickDemo();               CreateSidebarButton(panels.preTickDemo,               "PreTick");
}