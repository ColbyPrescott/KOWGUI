/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       crprescott2026                                            */
/*    Created:      4/12/2024, 4:34:09 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

#include "KOWGUI/kowgui.h"

using namespace vex;

vex::brain Brain;

KOWGUI::GUI gui = KOWGUI::GUI(Brain);

int main() {
    srand(Brain.Timer.systemHighResolution());

    KOWGUI::Rectangle* rect = gui.root->AddChild((new KOWGUI::Rectangle)->
        SetID("greenRectangle")->
        SetPosition(50, 50)->
        SetSize(200, 100)->
        SetFillColor((new KOWGUI::Color)->SetRGB(50, 200, 50))->
        AddChildren({
            (new KOWGUI::Rectangle)->
                SetPosition(-20, -20)->
                SetSize(50, 100)->
                SetOutlineColor((new KOWGUI::Color)->SetRGB(0, 0, 200))->
                SetOutlineWidth(5),
            (new KOWGUI::Text)->
                SetText("repeat and ")->
                SetFontSize(15)->
                SetVerticalAlign(KOWGUI::VerticalAlign::ascender)->
                SetOverflow(KOWGUI::Overflow::scroll)->
                SetScrollSpeed(3)->
                SetScrollSpacing(0),
            (new KOWGUI::Text)->
                SetPosition(0, 20)->
                SetHeight(80)->
                SetText("This is some test text that should break lines on the right edge of the text node, splitOnlyGiantWordsAcrossMultipleLinesAndIndicateSuchWasDoneWithAHyphen, account for      many    spaces and\nnew line characters\n:D")->
                SetFontSize(60)->
                SetVerticalAlign(KOWGUI::VerticalAlign::ascender)->
                SetOverflow(KOWGUI::Overflow::wrapScale)->
                SetWrapLineSpacing(1.1),
            (new KOWGUI::Draggable)->
                SetPosition(140, 90)->
                SetSize(50, 30)->
                AddChildren({
                    (new KOWGUI::Rectangle)->
                        SetFillColor(KOWGUI::Color::red),
                    (new KOWGUI::Text)->
                        SetText("Hewwo!")->
                        SetFont(KOWGUI::Fonts::proportional)->
                        SetFontSize(20)->
                        SetColor((new KOWGUI::Color)->SetRGB(0, 150, 255))->
                        SetVerticalAlign(KOWGUI::VerticalAlign::ascender)->
                        SetOverflow(KOWGUI::Overflow::visible)->
                        SetWrapLineSpacing(0.6)
                })
        })
    );

    gui.root->AddChild((new KOWGUI::Toggleable)->
        SetPosition(350, 100)->
        SetSize(75, 75)->
        SetPress([](){gui.FindID("greenRectangle")->SetX(0);})->
        SetRelease([](){gui.FindID("greenRectangle")->SetX(100);})->
        SetFocus([](){gui.FindID("greenRectangle")->SetY(0);})->
        SetUnfocus([](){gui.FindID("greenRectangle")->SetY(140);})->
        AddChildren({
            (new KOWGUI::Focused)->SetReversed(true)->AddChildren({
                (new KOWGUI::Rectangle)->SetFillColor((new KOWGUI::Color)->SetRGB(150, 150, 150))
            }),
            (new KOWGUI::Focused)->AddChildren({
                (new KOWGUI::Rectangle)->
                SetPosition(5, 5)->
                SetSize(65, 65)->
                SetFillColor((new KOWGUI::Color)->SetRGB(100, 100, 100)),
                (new KOWGUI::Text)->
                SetPosition(5, 75 / 2)->
                SetWidth(65)->
                SetText("Focused")->
                SetFont(KOWGUI::Fonts::monospace)->
                SetFontSize(20)->
                SetVerticalAlign(KOWGUI::VerticalAlign::middle)->
                SetOverflow(KOWGUI::Overflow::scroll)->
                SetScrollSpacing(20)
            }),
            (new KOWGUI::Activated)->AddChildren({
                (new KOWGUI::Rectangle)->SetPosition(5, 60)->SetSize(65, 10)->SetFillColor((new KOWGUI::Color)->SetRGB(153, 42, 232))
            })
        })
    );

    gui.root->AddChild((new KOWGUI::Draggable)->
        SetID("testRange")->
        SetPosition(350, 20)->
        SetSize(75, 75)->
        SetRange(200, 0, 350, 175)->
        SetPress([](){gui.FindID("greenRectangle")->SetX(0);})->
        SetRelease([](){gui.FindID("greenRectangle")->SetX(100);})->
        SetFocus([](){gui.FindID("greenRectangle")->SetY(0);})->
        SetUnfocus([](){gui.FindID("greenRectangle")->SetY(140);})->
        AddChildren({
            (new KOWGUI::Rectangle)->SetFillColor((new KOWGUI::Color)->SetRGB(255, 50, 150)),
            (new KOWGUI::Text)->
                SetShallowID("text")->
                SetFont(KOWGUI::Fonts::monospace)->
                SetFontSize(13)->
                SetVerticalAlign(KOWGUI::VerticalAlign::top)
        })
    );

    gui.root->AddChild((new KOWGUI::Clickable)->
        SetPosition(450, 0)->
        SetSize(30, 30)->
        SetRelease([](){gui.FindID("greenRectangle")->SetDisabled(!gui.FindID("greenRectangle")->GetDisabled());})->
        AddChildren({
            (new KOWGUI::Circle)->
                SetPosition(2, 2)->
                SetRadius(13)->
                SetFillColor((new KOWGUI::Color)->SetRGB(255, 255, 255))->
                SetOutlineColor((new KOWGUI::Color)->SetRGB(0, 200, 200))->
                SetOutlineWidth(4)
        })
    );

    while(1) {

        KOWGUI::Draggable* rangeNode = (KOWGUI::Draggable*)gui.FindID("testRange");
        KOWGUI::Text* rangeTextNode = (KOWGUI::Text*)gui.FindID("testRange")->FindShallowID("text");
        rangeTextNode->SetText("X: %d\nY: %d\n%d%%%%\n%d%%%%", rangeNode->CalculateX(), rangeNode->CalculateY(), (int)(rangeNode->GetPercentX() * 100), (int)(rangeNode->GetPercentY() * 100));
        
        gui.Tick();

        // Allow other tasks to run
        this_thread::sleep_for(20);
    }
}
