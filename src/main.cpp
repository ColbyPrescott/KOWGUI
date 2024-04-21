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

    gui.root->AddChild((new KOWGUI::Clickable)->
        SetPosition(350, 100)->
        SetSize(75, 75)->
        SetPress([](){((KOWGUI::Rectangle*)gui.root->children[0])->SetX(0);})->
        SetRelease([](){((KOWGUI::Rectangle*)gui.root->children[0])->SetX(100);})->
        SetFocus([](){((KOWGUI::Rectangle*)gui.root->children[0])->SetY(0);})->
        SetUnfocus([](){((KOWGUI::Rectangle*)gui.root->children[0])->SetY(140);})->
        AddChildren({
            (new KOWGUI::Rectangle)->SetFillColor((new KOWGUI::Color)->SetRGB(150, 150, 150))
        })
    );

    gui.root->AddChild((new KOWGUI::Draggable)->
        SetPosition(350, 20)->
        SetSize(75, 75)->
        SetPress([](){((KOWGUI::Rectangle*)gui.root->children[0])->SetX(0);})->
        SetRelease([](){((KOWGUI::Rectangle*)gui.root->children[0])->SetX(100);})->
        SetFocus([](){((KOWGUI::Rectangle*)gui.root->children[0])->SetY(0);})->
        SetUnfocus([](){((KOWGUI::Rectangle*)gui.root->children[0])->SetY(140);})->
        AddChildren({
            (new KOWGUI::Rectangle)->SetFillColor((new KOWGUI::Color)->SetRGB(255, 50, 150))
        })
    );

    while(1) {
        
        gui.Tick();

        // rect->SetY((sin(Brain.Timer.system() / 1000.0) / 2.0 + 0.5) * 140);
        // Allow other tasks to run
        this_thread::sleep_for(20);
    }
}
