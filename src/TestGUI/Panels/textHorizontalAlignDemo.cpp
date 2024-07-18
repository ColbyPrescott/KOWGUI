#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

void InitGUITextHorizontalAlignDemo() {
    panels.textHorizontalAlignDemo->AddChildren({
        (new Rectangle)->SetPosition(20, 20)->SetSize(480 - sidebarWidth - 40, 60)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Left\nMultiline")->SetFontSize(20)->SetFontAlign(Text::FontAlign::ascender)->SetHorizontalAlign(Text::HorizontalAlign::left)
        }),
        (new Rectangle)->SetPosition(20, 90)->SetSize(480 - sidebarWidth - 40, 60)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Center\nMultiline")->SetFontSize(20)->SetFontAlign(Text::FontAlign::ascender)->SetHorizontalAlign(Text::HorizontalAlign::center)
        }),
        (new Rectangle)->SetPosition(20, 160)->SetSize(480 - sidebarWidth - 40, 60)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Right\nMultiline")->SetFontSize(20)->SetFontAlign(Text::FontAlign::ascender)->SetHorizontalAlign(Text::HorizontalAlign::right)
        }),
    });
}