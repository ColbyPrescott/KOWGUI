#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

const int rectWidth = (480 - sidebarWidth - 20 * 4) / 3.0;

void InitGUITextVerticalAlignDemo() {
    panels.textVerticalAlignDemo->AddChildren({
        (new Rectangle)->SetPosition(20 + (rectWidth + 20) * 0, 20)->SetSize(rectWidth, 200)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Top")->SetFontSize(20)->SetFontAlign(FontAlign::ascender)->SetVerticalAlign(VerticalAlign::top)
        }),
        (new Rectangle)->SetPosition(20 + (rectWidth + 20) * 1, 20)->SetSize(rectWidth, 200)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Middle")->SetFontSize(20)->SetFontAlign(FontAlign::ascender)->SetVerticalAlign(VerticalAlign::middle)
        }),
        (new Rectangle)->SetPosition(20 + (rectWidth + 20) * 2, 20)->SetSize(rectWidth, 200)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Bottom")->SetFontSize(20)->SetFontAlign(FontAlign::ascender)->SetVerticalAlign(VerticalAlign::bottom)
        }),
    });
}