/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       crprescott2026                                            */
/*    Created:      4/12/2024, 4:34:09 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "globalVars.h"

#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

#include <iostream>

using namespace vex;

int main() {
    srand(Brain.Timer.systemHighResolution());

    InitGUISidebar();

    InitPanels();

    numpad = KOWGUI::Keyboard::CreateNumpad(10, 10, 100, 150, true, true, theme.sliderNFocused, theme.buttonNFocused, theme.buttonFocused, theme.lightText);
    gui.root->AddChild(numpad);

    keyboard = KOWGUI::Keyboard::CreateKeyboard(KOWGUI::Color::darkSlateGray, theme.buttonNFocused, theme.buttonFocused, theme.lightText);
    gui.root->AddChild(keyboard);

    LoadPanel(panels.keyboardDemo);

    while(true) {

        gui.Tick();

        // Allow other tasks to run
        this_thread::sleep_for(20);
    }
}
