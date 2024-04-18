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
    srand(Brain.Timer.systemHighResolution());

    KOWGUI::Rectangle* rect = gui.root->AddChild((new KOWGUI::Rectangle)->
        SetPosition(50, 50)->
        SetSize(200, 100)->
        SetFillColor((new KOWGUI::Color)->SetRGB(50, 200, 50))->
        AddChildren({
            (new KOWGUI::Rectangle)->
                SetPosition(-20, -20)->
                SetSize(50, 100)->
                SetOutlineColor((new KOWGUI::Color)->SetRGB(0, 0, 200))->
                SetOutlineWidth(5),
            (new KOWGUI::Group)->
                SetPosition(100, 50)->
                SetSize(50, 30)->
                AddChildren({
                    (new KOWGUI::Rectangle)->
                        SetFillColor(KOWGUI::Color::red)
                })
        })
    );
    
    int floatDirection = 1;
    float lastDuration = 0;

    while(1) {
        
        uint32_t startTime = Brain.Timer.systemHighResolution();
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.setFillColor(vex::color::black);
        Brain.Screen.setPenColor(vex::color::white);
        Brain.Screen.print("%d nodes - %.3fms", rect->children.size(), lastDuration);
        gui.Tick();
        uint32_t endTime = Brain.Timer.systemHighResolution();
        lastDuration = (endTime - startTime) / 1000.0;

        if(rect->CalculateX() < 0 || rect->CalculateX() + rect->GetWidth() > 480) {
            floatDirection *= -1;
            
            for(int i = 0; i < rect->children.size() * 0.25; i++) rect->AddChild((new KOWGUI::Rectangle)->
                SetX(rand() % 300 - 50)->
                SetY(rand() % 200 - 50)->
                SetWidth(rand() % 100)->
                SetHeight(rand() % 100)->
                SetOutlineColor((new KOWGUI::Color)->SetRGB(rand() % 256, rand() % 256, rand() % 256)));
        }
        rect->SetX(rect->GetX() + floatDirection);
        rect->SetY((sin(Brain.Timer.system() / 1000.0) / 2.0 + 0.5) * 140);

        // Allow other tasks to run
        this_thread::sleep_for(20);
    }
}
