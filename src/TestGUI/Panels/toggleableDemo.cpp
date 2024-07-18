#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

#include <string>

using namespace KOWGUI;

namespace ToggleableDemo {

    void FrontAppendLineToTextNode(Text* textNode, std::string newLine) {
        static int lineNumber = 0;
        lineNumber++;

        std::string existingText = textNode->GetText().substr(0, 150);

        textNode->SetText("%d: %s\n%s", lineNumber, newLine.c_str(), existingText.c_str());
    }

    void DemoPressed(BaseNode* thisNode) {
        FrontAppendLineToTextNode((Text*)panels.toggleableDemo->FindShallowID("stateText"), "Press function");
    }

    void DemoReleased(BaseNode* thisNode) {
        FrontAppendLineToTextNode((Text*)panels.toggleableDemo->FindShallowID("stateText"), "Release function");
    }

    void DemoFocused(BaseNode* thisNode) {
        FrontAppendLineToTextNode((Text*)panels.toggleableDemo->FindShallowID("stateText"), "Focus function");
    }

    void DemoUnfocused(BaseNode* thisNode) {
        FrontAppendLineToTextNode((Text*)panels.toggleableDemo->FindShallowID("stateText"), "Unfocus function");
    }

    void UpdateCounterDisplay(BaseNode* thisNode) {
        Text* textNode = (Text*)panels.toggleableDemo->FindShallowID("counterText");
        Toggleable* demoToggleable = (Toggleable*)panels.toggleableDemo->FindShallowID("demoToggleable");

        textNode->SetText("Activated: %s\nClicks: %d", demoToggleable->GetActivated() ? "True" : "False", demoToggleable->GetClicks());
    }

}

using namespace ToggleableDemo;

void InitGUIToggleableDemo() {
    panels.toggleableDemo->AddChildren({
        // Function log
        (new Text)->SetShallowID("stateText")->SetPosition(140, 10)->SetSize(480 - sidebarWidth - 140 - 10, 130)->SetText("State")->SetFontSize(20)->SetAlignments(Text::HorizontalAlign::left, Text::VerticalAlign::top, Text::FontAlign::ascender)->SetOverflow(Text::Overflow::wrap)->SetWrapLineSpacing(1.8)->AddChildren({
            (new Rectangle)->SetY(130)->SetFillColor(Color::black),
            (new Line)->SetY1(140)->SetY2(140)->SetColor(Color::white)->SetLineWidth(2),
        }),

        // Counter and activated info
        (new Text)->SetShallowID("counterText")->SetPosition(140, 170)->SetText("Activated: xxxxx\nClicks: xxx")->SetFontSize(20)->SetAlignments(Text::HorizontalAlign::left, Text::VerticalAlign::top, Text::FontAlign::ascender)->SetPreTick(UpdateCounterDisplay),

        // Demo toggleable
        (new Toggleable)->SetShallowID("demoToggleable")->SetPosition(30, 30)->SetSize(80, 80)->SetPress(DemoPressed)->SetRelease(DemoReleased)->SetFocus(DemoFocused)->SetUnfocus(DemoUnfocused)->AddChildren({
            (new Rectangle)->SetFillColor(Color::gray)->SetOutlineColor(Color::white),
            (new Text)->SetText("Press")->SetFontSize(20)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
        }),

        // Info help button
        (new Clickable)->SetPosition(50, 160)->SetSize(40, 40)->AddChildren({
            (new NSelected)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Selected)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetPosition(1, 2)->SetText("?")->SetFontSize(25)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
            
            (new Selected)->SetPosition(-50, -160)->SetSize(480 - sidebarWidth, 140)->AddChildren({
                (new Rectangle)->SetFillColor(Color::gray),
                (new Text)->SetText("Same features as the Clickable node with some additions:\n\n- Toggleables will keep track of how many times the release function has been called.\n- Toggleables can return raw number of clicks, or pass it through modulo two to return a true / false \"activated\" state.\n\nNumber of releases is tracked instead of presses because executing code on a button's release gives a user the opportunity to unfocus and cancel a mistaken click.")->SetFontSize(10)->SetFontAlign(Text::FontAlign::ascender),
            }),
        }),
    });
}