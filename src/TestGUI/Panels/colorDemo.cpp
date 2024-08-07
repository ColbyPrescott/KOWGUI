#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

void InitGUIColorDemo() {
    panels.colorDemo->AddChildren({
        (new Text)->SetPosition(0, 0)->SetText("Name cyan")->SetColor(Color::cyan)->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(0, 40)->SetText("RGB 255, 0, 255")->SetColor(std::make_shared<Color>()->SetRGB(255, 0, 255))->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(0, 80)->SetText("Hex #e38212")->SetColor(std::make_shared<Color>()->SetHex("#e38212"))->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(0, 120)->SetText("Transparent fill -->")->SetColor(Color::white)->SetFontAlign(Text::FontAlign::ascender),
        (new Rectangle)->SetPosition(270, 120)->SetSize(25, 25)->SetFillColor(Color::transparent)->SetOutlineColor(Color::white)->SetOutlineWidth(2),
    });
}