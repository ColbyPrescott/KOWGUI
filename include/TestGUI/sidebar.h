#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "KOWGUI/kowgui.h"

const static int sidebarWidth = 100;
const static int sidebarScrollbarWidth = 20;

void CreateSidebarButton(KOWGUI::Group* panel, std::string text, int height = 20);

void InitGUISidebar();

#endif