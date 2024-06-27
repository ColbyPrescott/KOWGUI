#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

#include <string>

using namespace KOWGUI;

void FrontAppendLineToTextNode(Text* textNode, std::string newLine) {
    static int lineNumber = 0;
    lineNumber++;

    std::string existingText = textNode->GetText().substr(0, 150);

    textNode->SetText("%d: %s\n%s", lineNumber, newLine.c_str(), existingText.c_str());
}

void DemoPressed(BaseNode* thisNode) {
    FrontAppendLineToTextNode((Text*)panels.clickableDemo->FindShallowID("stateText"), "Press function");
}

void DemoReleased(BaseNode* thisNode) {
    FrontAppendLineToTextNode((Text*)panels.clickableDemo->FindShallowID("stateText"), "Release function");
}

void DemoFocused(BaseNode* thisNode) {
    FrontAppendLineToTextNode((Text*)panels.clickableDemo->FindShallowID("stateText"), "Focus function");
}

void DemoUnfocused(BaseNode* thisNode) {
    FrontAppendLineToTextNode((Text*)panels.clickableDemo->FindShallowID("stateText"), "Unfocus function");
}

void InitGUIClickableDemo() {
    panels.clickableDemo->AddChildren({
        // Demo clickable
        (new Clickable)->SetPosition(30, 30)->SetSize(80, 80)->SetPress(DemoPressed)->SetRelease(DemoReleased)->SetFocus(DemoFocused)->SetUnfocus(DemoUnfocused)->AddChildren({
            (new Rectangle)->SetFillColor(Color::gray)->SetOutlineColor(Color::white),
            (new Text)->SetText("Press")->SetFontSize(20)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
        }),

        // Function log
        (new Text)->SetShallowID("stateText")->SetPosition(140, 30)->SetText("State")->SetFontSize(20)->SetAlignments(HorizontalAlign::left, VerticalAlign::top, FontAlign::ascender)->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(1.8),

        // Info help button
        (new Clickable)->SetPosition(50, 160)->SetSize(40, 40)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetPosition(1, 2)->SetText("?")->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
            
            (new Focused)->SetPosition(-50, -160)->SetSize(480 - sidebarWidth, 150)->AddChildren({ // TO DO Add Selected and put it here
                (new Rectangle)->SetFillColor(Color::gray),
                (new Text)->SetText("When an interactable node is selected (input starts in its area), it will start running these four user-defined callback functions:\n\n- Press: Called when input starts.\n- Release: Called when input is removed inside node area.\n- Focus: Called when input starts or re-enters node area after dragging continuous input.\n- Unfocus: Called when continuous input is dragged outside of node area.")->SetFontSize(12)->SetFontAlign(FontAlign::ascender),
            }),
        }),
    });
}