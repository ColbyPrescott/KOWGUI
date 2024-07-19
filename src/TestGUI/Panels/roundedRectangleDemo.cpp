#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

void InitGUIRoundedRectangleDemo() {
    panels.roundedRectangleDemo->AddChildren({
        (new RoundedRectangle)->SetPosition(20, 30)->SetSize(100, 240 - 30 - 30)->SetFillColor(Color::red)->SetOutlineRadius(10),
        (new RoundedRectangle)->SetPosition(140, 30)->SetSize(100, 240 - 30 - 30)->SetFillColor(Color::lime)->SetOutlineColor(Color::blue)->SetOutlineWidth(1)->SetOutlineRadius(25),
        (new RoundedRectangle)->SetPosition(260, 30)->SetSize(100, 240 - 30 - 30)->SetFillColor(Color::blue)->SetOutlineColor(Color::orange)->SetOutlineWidth(10)->SetOutlineRadius(200),
    });
}