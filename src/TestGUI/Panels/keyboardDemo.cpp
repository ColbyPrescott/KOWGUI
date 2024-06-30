#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include "globalVars.h"

#include <string>

using namespace KOWGUI;

namespace {

    std::string testStr = "Edit me!";

    void UpdateStringText(BaseNode* thisNode) {
        ((Text*)thisNode)->SetText(testStr);
    }

}

void InitGUIKeyboardDemo() {
    panels.keyboardDemo->AddChildren({
        (new Clickable)->SetPosition(30, 30)->SetSize(80, 40)->SetRelease([](BaseNode* thisNode){Keyboard::Open(keyboard, testStr);})->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetText("Open")->SetFontSize(20)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
        }),
        
        (new Rectangle)->SetPosition(150, 30)->SetSize(150, 100)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetFontSize(20)->SetPreTick(UpdateStringText),
        }),
    });
}