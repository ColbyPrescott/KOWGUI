#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

void InitGUIRectangleDemo() {
    panels.rectangleDemo->AddChildren({
        (new Rectangle)->SetPosition(20, 30)->SetSize(100, 240 - 30 - 30)->SetFillColor(Color::red),
        (new Rectangle)->SetPosition(140, 30)->SetSize(100, 240 - 30 - 30)->SetFillColor(Color::lime)->SetOutlineColor(Color::blue)->SetOutlineWidth(1),
        (new Rectangle)->SetPosition(260, 30)->SetSize(100, 240 - 30 - 30)->SetFillColor(Color::blue)->SetOutlineColor(Color::orange)->SetOutlineWidth(10),
    });
}