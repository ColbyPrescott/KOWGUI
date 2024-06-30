#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include "globalVars.h"

using namespace KOWGUI;

void InitGUIKeyboardDemo() {
    panels.keyboardDemo->AddChildren({
        (new Clickable)->SetPosition(30, 30)->SetSize(80, 40)->SetRelease([](BaseNode* thisNode){Keyboard::Open(keyboard);})->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetText("Open")->SetFontSize(20)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
        }),
    });
}