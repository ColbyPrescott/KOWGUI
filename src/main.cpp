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

    KOWGUI::Rectangle* rect = (new KOWGUI::Rectangle);
    
    rect->Draw(Brain.Screen);

        while(1) {
            
            // Allow other tasks to run
            this_thread::sleep_for(10);
        }
}
