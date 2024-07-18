#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

void InitGUICircleDemo() {
    panels.circleDemo->AddChildren({
        (new Circle)->SetPosition(30, 30)->SetSize(50, 50)->SetFillColor(Color::red),
        (new Circle)->SetPosition(110, 30)->SetSize(50, 50)->SetFillColor(Color::lime)->SetOutlineColor(Color::blue)->SetOutlineWidth(1),
        (new Circle)->SetPosition(190, 30)->SetSize(50, 50)->SetFillColor(Color::blue)->SetOutlineColor(Color::orange)->SetOutlineWidth(10),

        (new Circle)->SetPosition(30, 140)->SetWidth(70)->SetOutlineColor(Color::white)->SetOutlineWidth(2)->AddChildren({
            (new Rectangle)->SetPosition(-5, -1)->SetSize(10, 2)->SetFillColor(Color::white),
            (new Rectangle)->SetPosition(-1, -5)->SetSize(2, 10)->SetFillColor(Color::white),
            (new Text)->SetText("Corner /\nDefault")->SetFont(Fonts::pixelated)->SetFontSize(14)->SetColor(Color::red)->SetFontAlign(FontAlign::ascender),
        }),
        (new Circle)->SetPosition(160, 140)->SetWidth(70)->SetCentered(true)->SetOutlineColor(Color::white)->SetOutlineWidth(2)->AddChildren({
            (new Rectangle)->SetPosition(-5, -1)->SetSize(10, 2)->SetFillColor(Color::white),
            (new Rectangle)->SetPosition(-1, -5)->SetSize(2, 10)->SetFillColor(Color::white),
            (new Text)->SetText("Centered")->SetFont(Fonts::pixelated)->SetFontSize(14)->SetColor(Color::red)->SetFontAlign(FontAlign::ascender),
        }),

        (new Circle)->SetPosition(280, 30)->SetWidth(70)->SetOutlineColor(Color::white)->SetOutlineWidth(2)->AddChildren({
            (new Text)->SetPosition(15, 15)->SetText("Set by width\n70")->SetFont(Fonts::pixelated)->SetFontSize(13)->SetColor(Color::red)->SetFontAlign(FontAlign::ascender),
        }),
        (new Circle)->SetPosition(280, 130)->SetRadius(35)->SetOutlineColor(Color::white)->SetOutlineWidth(2)->AddChildren({
            (new Text)->SetPosition(15, 15)->SetText("Set by radius\n35")->SetFont(Fonts::pixelated)->SetFontSize(13)->SetColor(Color::red)->SetFontAlign(FontAlign::ascender),
        }),
    });
}