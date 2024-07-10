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

using namespace vex;

int main() {
    srand(Brain.Timer.systemHighResolution());

    InitGUISidebar();

    InitPanels();

    numpad = KOWGUI::Keyboard::CreateNumpad(10, 10, 100, 150, true, true, theme.sliderNFocused, theme.buttonNFocused, theme.buttonFocused, theme.lightText);
    gui.root->AddChild(numpad);

    keyboard = KOWGUI::Keyboard::CreateKeyboard(KOWGUI::Color::darkSlateGray, theme.buttonNFocused, theme.buttonFocused, theme.lightText);
    gui.root->AddChild(keyboard);

    LoadPanel(panels.removalDemo);

    while(true) {

        gui.Tick();

        for(int i = 0; i < 100; i++) {
            KOWGUI::Group* test = (new KOWGUI::Group)->AddChildren({
                (new KOWGUI::Group),
                (new KOWGUI::Data)->SetProperty("memoryLeakTest", std::make_shared<KOWGUI::Group>()),
                (new KOWGUI::Row),
                (new KOWGUI::Column),
                (new KOWGUI::Rectangle)->SetFillColor(std::make_shared<KOWGUI::Color>()->SetRGB(255, 255, 255)),
                (new KOWGUI::Circle),
                (new KOWGUI::Line),
                (new KOWGUI::Text),
                (new KOWGUI::Clickable),
                (new KOWGUI::Draggable),
                (new KOWGUI::Toggleable),
                (new KOWGUI::Selected),
                (new KOWGUI::Focused),
                (new KOWGUI::Activated),
                (new KOWGUI::Looped),
                (new KOWGUI::NSelected),
                (new KOWGUI::NFocused),
                (new KOWGUI::NActivated),
            });
            delete test;
        }

        // Allow other tasks to run
        this_thread::sleep_for(20);
    }
}
