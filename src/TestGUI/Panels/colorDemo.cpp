#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

void InitGUIColorDemo() {
    panels.colorDemo->AddChildren({
        (new Text)->SetPosition(0, 0)->SetText("Name cyan")->SetColor(Color::cyan)->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(0, 40)->SetText("RGB 255, 0, 255")->SetColor((new Color)->SetRGB(255, 0, 255))->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(0, 80)->SetText("Hex #e38212")->SetColor((new Color)->SetHex("#e38212"))->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(0, 120)->SetText("Transparent fill -->")->SetColor(Color::white)->SetVerticalAlign(VerticalAlign::ascender),
        (new Rectangle)->SetPosition(270, 120)->SetSize(25, 25)->SetFillColor(Color::transparent)->SetOutlineColor(Color::white)->SetOutlineWidth(2),
    });
}