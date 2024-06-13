#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

void InitGUITextFontDemo() {
    panels.textFontDemo->AddChildren({
        (new Text)->SetPosition(10, 10)->SetText("Proportional 40")->SetFont(Fonts::proportional)->SetFontSize(40)->SetColor(Color::red)->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(10, 50)->SetText("Monospace 40")->SetFont(Fonts::monospace)->SetFontSize(40)->SetColor(Color::red)->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(10, 90)->SetText("Prop. Opt. Small 40")->SetFont(Fonts::optimizedSmall)->SetFontSize(40)->SetColor(Color::red)->SetVerticalAlign(VerticalAlign::ascender),

        (new Text)->SetPosition(10, 140)->SetText("Proportional 20")->SetFont(Fonts::proportional)->SetFontSize(20)->SetColor(Color::lime)->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(10, 160)->SetText("Monospace 20")->SetFont(Fonts::monospace)->SetFontSize(20)->SetColor(Color::lime)->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(10, 180)->SetText("Prop. Opt. Small 20")->SetFont(Fonts::optimizedSmall)->SetFontSize(20)->SetColor(Color::lime)->SetVerticalAlign(VerticalAlign::ascender),

        (new Text)->SetPosition(10, 210)->SetText("Proportional 10")->SetFont(Fonts::proportional)->SetFontSize(10)->SetColor(Color::blue)->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(10, 220)->SetText("Monospace 10")->SetFont(Fonts::monospace)->SetFontSize(10)->SetColor(Color::blue)->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(10, 230)->SetText("Prop. Opt. Small 10")->SetFont(Fonts::optimizedSmall)->SetFontSize(10)->SetColor(Color::blue)->SetVerticalAlign(VerticalAlign::ascender),
    });
}