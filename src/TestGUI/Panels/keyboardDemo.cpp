#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include "globalVars.h"

#include <string>

using namespace KOWGUI;

namespace {

    std::string testStr = "Edit testStr directly! (This Text node is updated during preTick)";

    void UpdateStringText(BaseNode* thisNode) {
        ((Text*)thisNode)->SetText(testStr);
    }

}

void InitGUIKeyboardDemo() {
    panels.keyboardDemo->AddChildren({
        // Direct edit demo
        (new Clickable)->SetPosition(30, 30)->SetSize(80, 40)->SetRelease([](BaseNode* thisNode){Keyboard::Open(keyboard, testStr);})->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetText("Open Direct")->SetFontSize(16)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
        }),
        (new Rectangle)->SetPosition(150, 30)->SetSize(150, 60)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetFontSize(12)->SetPreTick(UpdateStringText),
        }),

        // Function edit demo
        (new Clickable)->SetPosition(30, 100)->SetSize(80, 40)->SetRelease([](BaseNode* thisNode){Keyboard::Open(keyboard, ((Text*)thisNode->parent->FindShallowID("indirectText"))->GetText(), [](std::string str){((Text*)panels.keyboardDemo->FindShallowID("indirectText"))->SetText(str);});})->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetText("Open With Func")->SetFontSize(16)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
        }),
        (new Rectangle)->SetPosition(150, 100)->SetSize(150, 60)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetShallowID("indirectText")->SetText("Edit this Text node by getting and setting the content")->SetFontSize(12),
        }),

        // Integer numpad demo
        (new Clickable)->SetPosition(30, 170)->SetSize(80, 40)->SetRelease([](BaseNode* thisNode){Keyboard::Open(numpad, 10, [](int num){});})->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetText("10")->SetFontSize(16)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
        }),
    });
}