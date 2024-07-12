#ifndef PANEL_MANAGER_H
#define PANEL_MANAGER_H

#include "KOWGUI/kowgui.h"

extern KOWGUI::GUI gui;

struct Panels {
    KOWGUI::Group* rectangleDemo = new KOWGUI::Group;
    KOWGUI::Group* circleDemo = new KOWGUI::Group;
    KOWGUI::Group* lineDemo = new KOWGUI::Group;
    KOWGUI::Group* imageDemo = new KOWGUI::Group;
    KOWGUI::Group* textFontDemo = new KOWGUI::Group;
    KOWGUI::Group* textFontAlignDemo = new KOWGUI::Group;
    KOWGUI::Group* textHorizontalAlignDemo = new KOWGUI::Group;
    KOWGUI::Group* textVerticalAlignDemo = new KOWGUI::Group;
    KOWGUI::Group* textOverflowDemo = new KOWGUI::Group;
    KOWGUI::Group* clickableDemo = new KOWGUI::Group;
    KOWGUI::Group* draggableDemo = new KOWGUI::Group;
    KOWGUI::Group* toggleableDemo = new KOWGUI::Group;
    KOWGUI::Group* selectedDemo = new KOWGUI::Group;
    KOWGUI::Group* focusedDemo = new KOWGUI::Group;
    KOWGUI::Group* activatedDemo = new KOWGUI::Group;
    KOWGUI::Group* loopedDemo = new KOWGUI::Group;
    KOWGUI::Group* groupDemo = new KOWGUI::Group;
    KOWGUI::Group* rowDemo = new KOWGUI::Group;
    KOWGUI::Group* keyboardDemo = new KOWGUI::Group;
    KOWGUI::Group* graphDemo = new KOWGUI::Group;
    KOWGUI::Group* colorDemo = new KOWGUI::Group;
    KOWGUI::Group* preTickDemo = new KOWGUI::Group;
    KOWGUI::Group* removalDemo = new KOWGUI::Group;
};

extern Panels panels;


struct {
    std::shared_ptr<KOWGUI::Color> sidebarBackground = std::make_shared<KOWGUI::Color>()->SetHex("#2F4F4F");
    std::shared_ptr<KOWGUI::Color> lightText = std::make_shared<KOWGUI::Color>()->SetRGB(255, 255, 255);
    std::shared_ptr<KOWGUI::Color> buttonNFocused = std::make_shared<KOWGUI::Color>()->SetHex("#1b9477");
    std::shared_ptr<KOWGUI::Color> buttonFocused = std::make_shared<KOWGUI::Color>()->SetHex("#26d1a8");
    std::shared_ptr<KOWGUI::Color> sliderNFocused = std::make_shared<KOWGUI::Color>()->SetHex("#661b94");
    std::shared_ptr<KOWGUI::Color> sliderFocused = std::make_shared<KOWGUI::Color>()->SetHex("#8e26cf");
} theme;


void InitPanels();

void LoadPanel(KOWGUI::Group* panel);

#endif