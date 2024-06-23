#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

void InitGUIGroupDemo() {
    panels.groupDemo->AddChildren({
        (new Draggable)->SetPosition(50, 50)->SetSize(100, 50)->AddChildren({
            (new Rectangle)->SetFillColor(Color::red),
            (new Rectangle)->SetPosition(20, 20)->SetSize(30, 70)->SetOutlineColor(Color::lime)->SetOutlineWidth(3),
            (new Text)->SetPosition(0, 0)->SetWidth(400)->SetText("Drag me!\nBoth rectangles follow\nRed inherits size")->SetFont(Fonts::optimizedSmall)->SetFontSize(13)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::wrap)
        }),
        (new Group)->SetPosition(250, 100)->SetSize(100, 50)->AddChildren({
            (new Rectangle)->SetFillColor(Color::white),
            (new Rectangle)->SetPosition(20, 20)->SetSize(30, 70)->SetOutlineColor(Color::blue)->SetOutlineWidth(3),
            (new Rectangle)->SetPosition(60, -60)->SetSize(50, 50)->SetOutlineColor(Color::violet)->SetOutlineWidth(3),
            (new Text)->SetPosition(0, 0)->SetWidth(400)->SetText("Static group")->SetFont(Fonts::optimizedSmall)->SetFontSize(13)->SetColor(Color::black)->SetFontAlign(FontAlign::ascender)
        }),
    });
}