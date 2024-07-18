#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include <iostream>

using namespace KOWGUI;

namespace {

    // Called from the Remove Mosaic button Clickable node
    void DeleteRemovalTestA(BaseNode* thisNode) {
        delete panels.removalDemo->FindShallowID("removalTestA");
    }

    // Called from the Remove Self On Press (unsafe) button Clickable node
    void DeleteSelf(BaseNode* thisNode) {
        delete thisNode;
    }

    // Called from the Schedule Delete Self On Press button Clickable node
    void ScheduleSelfDeletion(BaseNode* thisNode) {
        thisNode->ScheduleDeletion();
    }

}

void InitGUIRemovalDemo() {
    panels.removalDemo->AddChildren({
        // Mosaic to delete
        (new Rectangle)->SetShallowID("removalTestA")->SetPosition(200, 30)->SetSize(50, 50)->SetFillColor(Color::red)->AddChildren({
            (new Rectangle)->SetPosition(20, 40)->SetSize(40, 30)->SetFillColor(Color::lime)->SetOutlineColor(Color::white)->SetOutlineWidth(5),
            (new Rectangle)->SetPosition(-20, -20)->SetSize(80, 5)->SetFillColor(Color::blue)->AddChildren({
                (new Circle)->SetPosition(70, 70)->SetWidth(20)->SetFillColor(std::make_shared<Color>()->SetRGB(0, 150, 150)),
                (new Circle)->SetPosition(60, 110)->SetWidth(15)->SetFillColor(Color::white),
            }),
            (new Rectangle)->SetPosition(30, 10)->SetSize(80, 5)->SetFillColor(Color::purple),
        }),

        // Button to delete the mosaic
        // This really only works because the mosaic is defined BEFORE the remove button. Still relatively unsafe to use a raw delete keyword
        (new Clickable)->SetPosition(30, 30)->SetSize(100, 50)->SetRelease(DeleteRemovalTestA)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetText("Remove Mosaic")->SetFontSize(18)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle),
        }),

        // Test button to delete a node currently being processed by GUI::Tick
        (new Clickable)->SetPosition(30, 100)->SetSize(100, 50)->SetPress(DeleteSelf)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetText("Remove Self On Press (unsafe)")->SetFontSize(13)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle),
        }),

        // Indicator for when the program crashes
        (new Text)->SetWidth(100)->SetText("Running - ")->SetFontSize(20)->SetAlignments(Text::HorizontalAlign::left, Text::VerticalAlign::top)->SetOverflow(Text::Overflow::scroll)->SetScrollSpeed(2)->SetScrollSpacing(0),

        // Button to safely delete self
        (new Clickable)->SetPosition(30, 170)->SetSize(100, 50)->SetPress(ScheduleSelfDeletion)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetText("Schedule Delete Self On Press")->SetFontSize(13)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle),
        }),
    });
}