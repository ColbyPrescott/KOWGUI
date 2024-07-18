#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

void InitGUITextFontDemo() {
    panels.textFontDemo->AddChildren({
        (new Text)->SetPosition(10, 10)->SetText("Proportional 40")->SetFont(Text::fontProportional)->SetFontSize(40)->SetColor(Color::red)->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(10, 50)->SetText("Monospace 40")->SetFont(Text::fontMonospace)->SetFontSize(40)->SetColor(Color::red)->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(10, 90)->SetText("Pixelated 40")->SetFont(Text::fontPixelated)->SetFontSize(40)->SetColor(Color::red)->SetFontAlign(Text::FontAlign::ascender),

        (new Text)->SetPosition(10, 140)->SetText("Proportional 20")->SetFont(Text::fontProportional)->SetFontSize(20)->SetColor(Color::lime)->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(10, 160)->SetText("Monospace 20")->SetFont(Text::fontMonospace)->SetFontSize(20)->SetColor(Color::lime)->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(10, 180)->SetText("Pixelated 20")->SetFont(Text::fontPixelated)->SetFontSize(20)->SetColor(Color::lime)->SetFontAlign(Text::FontAlign::ascender),

        (new Text)->SetPosition(10, 210)->SetText("Proportional 10")->SetFont(Text::fontProportional)->SetFontSize(10)->SetColor(Color::blue)->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(10, 220)->SetText("Monospace 10")->SetFont(Text::fontMonospace)->SetFontSize(10)->SetColor(Color::blue)->SetFontAlign(Text::FontAlign::ascender),
        (new Text)->SetPosition(10, 230)->SetText("Pixelated 10")->SetFont(Text::fontPixelated)->SetFontSize(10)->SetColor(Color::blue)->SetFontAlign(Text::FontAlign::ascender),
    });
}