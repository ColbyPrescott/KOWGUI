#include "TestGUI/panelManager.h"

#include "KOWGUI/kowgui.h"

#include "vex.h"
#include "globalVars.h"

#include "TestGUI/sidebar.h"

#include "TestGUI/Panels/basicShapes.h"
#include "TestGUI/Panels/text.h"

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

    ConfigurePanel(panels.basicShapes); InitGUIBasicShapes(); CreateSidebarButton(panels.basicShapes, "Basic shapes");
    ConfigurePanel(panels.text); InitGUIText(); CreateSidebarButton(panels.text, "Text");

    LoadPanel(panels.basicShapes);
}