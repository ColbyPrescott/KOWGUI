#ifndef PANEL_MANAGER_H
#define PANEL_MANAGER_H

#include "KOWGUI/kowgui.h"

extern KOWGUI::GUI gui;

struct Panels {
    KOWGUI::Group* groupDemo = new KOWGUI::Group;
    KOWGUI::Group* colorDemo = new KOWGUI::Group;
    KOWGUI::Group* rectangleDemo = new KOWGUI::Group;
    KOWGUI::Group* circleDemo = new KOWGUI::Group;
    KOWGUI::Group* lineDemo = new KOWGUI::Group;
    KOWGUI::Group* textFontDemo = new KOWGUI::Group;
    KOWGUI::Group* textFontAlignDemo = new KOWGUI::Group;
    KOWGUI::Group* textOverflowDemo = new KOWGUI::Group;
    KOWGUI::Group* preTickDemo = new KOWGUI::Group;
};

extern Panels panels;

// https://coolors.co/2f4f4f-eec170-f2a65a-f58549-772f1a

struct {
    KOWGUI::Color* sidebarBackground = (new KOWGUI::Color)->SetHex("#2F4F4F");
    KOWGUI::Color* scrollbar = (new KOWGUI::Color)->SetRGB(60, 102, 102);
    KOWGUI::Color* lightText = (new KOWGUI::Color)->SetRGB(255, 255, 255);
    KOWGUI::Color* buttonNFocused = (new KOWGUI::Color)->SetHex("#F58549");
    KOWGUI::Color* buttonFocused = (new KOWGUI::Color)->SetHex("#F2A65A");
} theme;

void InitPanels();

void LoadPanel(KOWGUI::Group* panel);

#endif