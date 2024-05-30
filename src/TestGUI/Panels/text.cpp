#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

void InitGUIText() {
    panels.text->AddChildren({
        (new Text)->SetPosition(10, 10)->SetText("Wow, oh my word! It's text!")->SetVerticalAlign(VerticalAlign::ascender),
        (new Text)->SetPosition(10, 150)->SetWidth(480 - sidebarWidth - 10 - 10)->SetText("                                         Get it? I'd usually say \"oh my gosh\" but this whole demo panel is supposed to be about text so I replaced it with the other common phrase of \"oh my word\" as in word like this piece of text is made out of. I do such a good job at making funny jokes. I mean, lying about making funny jokes so that I can elaborate a really long string of text.               Cough.        And oh nosie wosie oopsies TO DO Is something about lcd.print cutting off super long scrolling messages?")->SetFont(Fonts::monospace)->SetFontSize(20)->SetColor(Color::gray)->SetOverflow(Overflow::scroll)->SetScrollSpeed(4)
    });
}