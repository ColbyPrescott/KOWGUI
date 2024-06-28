#ifndef PANEL_MANAGER_H
#define PANEL_MANAGER_H

#include "KOWGUI/kowgui.h"

extern KOWGUI::GUI gui;

struct Panels {
    KOWGUI::Group* rectangleDemo = new KOWGUI::Group;
    KOWGUI::Group* circleDemo = new KOWGUI::Group;
    KOWGUI::Group* lineDemo = new KOWGUI::Group;
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
    KOWGUI::Group* colorDemo = new KOWGUI::Group;
    KOWGUI::Group* preTickDemo = new KOWGUI::Group;
};

extern Panels panels;


struct {
    KOWGUI::Color* sidebarBackground = (new KOWGUI::Color)->SetHex("#2F4F4F");
    KOWGUI::Color* lightText = (new KOWGUI::Color)->SetRGB(255, 255, 255);
    KOWGUI::Color* buttonNFocused = (new KOWGUI::Color)->SetHex("#1b9477");
    KOWGUI::Color* buttonFocused = (new KOWGUI::Color)->SetHex("#26d1a8");
    KOWGUI::Color* sliderNFocused = (new KOWGUI::Color)->SetHex("#661b94");
    KOWGUI::Color* sliderFocused = (new KOWGUI::Color)->SetHex("#8e26cf");
} theme;


void InitPanels();

void LoadPanel(KOWGUI::Group* panel);

#endif