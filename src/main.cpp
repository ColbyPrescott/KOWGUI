/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       crprescott2026                                            */
/*    Created:      4/12/2024, 4:34:09 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

#include "KOWGUI/gui.h"

using namespace vex;

vex::brain Brain;

KOWGUI::GUI gui = KOWGUI::GUI(Brain);

int main() {
    Brain.Screen.print("Hewwo UwU");

    KOWGUI::Rectangle* rect = gui.root->AddChild((new KOWGUI::Rectangle)->
        SetPosition(50, 50)->
        SetSize(200, 100)->
        SetFillColor((new KOWGUI::Color)->SetRGB(50, 200, 50))->
        AddChildren({
            (new KOWGUI::Rectangle)->
                SetPosition(100, 100)->
                SetSize(50, 100)->
                SetOutlineColor((new KOWGUI::Color)->SetRGB(200, 0, 0))->
                SetOutlineWidth(5)
        })
    );
    
    // rect->Draw(Brain.Screen);
    // ((KOWGUI::Rectangle*)((KOWGUI::BaseNode*)gui.root->children[0])->children[0])->Draw(Brain.Screen);

        while(1) {
            
            gui.Tick();

            // Allow other tasks to run
            this_thread::sleep_for(20);
        }
}
