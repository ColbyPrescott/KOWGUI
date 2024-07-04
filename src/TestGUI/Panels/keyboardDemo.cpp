#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include "globalVars.h"

#include <string>
#include <stdlib.h>

using namespace KOWGUI;

namespace {

    std::string testStr = "Edit testStr directly! (This Text node is updated during preTick)";

    // Functions to update the text in each Text node
    void UpdateStringText(BaseNode* thisNode) {
        ((Text*)thisNode)->SetText(testStr);
    }

    void UpdateIntegerText(BaseNode* thisNode) {
        ((Text*)thisNode)->SetText("%d", *(int*)((Data*)thisNode->parent->FindShallowID("integerDemoData"))->GetProperty("number"));
    }

    void UpdateDecimalText(BaseNode* thisNode) {
        ((Text*)thisNode)->SetText("%.5f", *(double*)((Data*)thisNode->parent->FindShallowID("decimalDemoData"))->GetProperty("number"));
    }

    // Functions to update Data nodes after the numpad closes
    void UpdateIntegerDemoNumber(int num) {
        *(int*)((Data*)panels.keyboardDemo->FindShallowID("integerDemoData"))->GetProperty("number") = num;
    }

    void UpdateDecimalDemoNumber(double num) {
        *(double*)((Data*)panels.keyboardDemo->FindShallowID("decimalDemoData"))->GetProperty("number") = num;
    }

    // Functions to open the numpad for each demo
    void OpenIntegerDemoNumpad(BaseNode* thisNode) {
        Keyboard::Open(numpad, *(int*)((Data*)thisNode->FindShallowID("integerDemoData"))->GetProperty("number"), UpdateIntegerDemoNumber, true);
    }

    void OpenDecimalDemoNumpad(BaseNode* thisNode) {
        Keyboard::Open(numpad, *(double*)((Data*)thisNode->FindShallowID("decimalDemoData"))->GetProperty("number"), UpdateDecimalDemoNumber);
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
        (new Clickable)->SetPosition(30, 170)->SetSize(80, 40)->SetRelease(OpenIntegerDemoNumpad)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetText("418")->SetFontSize(16)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetPreTick(UpdateIntegerText),

            // Live update info text
            (new Text)->SetY(14)->SetText("Live Update")->SetFontSize(12)->SetAlignments(HorizontalAlign::center, VerticalAlign::bottom),

            (new Data)->SetShallowID("integerDemoData")->SetProperty("number", new int(1810)),
        }),

        // Decimal numpad demo
        (new Clickable)->SetPosition(150, 170)->SetSize(80, 40)->SetRelease(OpenDecimalDemoNumpad)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetText("418")->SetFontSize(16)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetPreTick(UpdateDecimalText),

            (new Data)->SetShallowID("decimalDemoData")->SetProperty("number", new double(3.14159265)),
        }),
    });
}