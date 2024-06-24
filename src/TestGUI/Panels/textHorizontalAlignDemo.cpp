#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

void InitGUITextHorizontalAlignDemo() {
    panels.textHorizontalAlignDemo->AddChildren({
        (new Rectangle)->SetPosition(20, 20)->SetSize(480 - sidebarWidth - 40, 60)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Left")->SetFontSize(20)->SetFontAlign(FontAlign::ascender)->SetHorizontalAlign(HorizontalAlign::left)
        }),
        (new Rectangle)->SetPosition(20, 90)->SetSize(480 - sidebarWidth - 40, 60)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Center")->SetFontSize(20)->SetFontAlign(FontAlign::ascender)->SetHorizontalAlign(HorizontalAlign::center)
        }),
        (new Rectangle)->SetPosition(20, 160)->SetSize(480 - sidebarWidth - 40, 60)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Right")->SetFontSize(20)->SetFontAlign(FontAlign::ascender)->SetHorizontalAlign(HorizontalAlign::right)
        }),
    });
}