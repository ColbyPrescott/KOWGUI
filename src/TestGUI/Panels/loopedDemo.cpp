#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

namespace LoopedDemo {

    void UpdateClicksText(BaseNode* thisNode) {
        ((Text*)thisNode)->SetText("Press (%d)", ((Toggleable*)thisNode->parent)->GetClicks());
    }

}

using namespace LoopedDemo;

void InitGUILoopedDemo() {
    panels.loopedDemo->AddChildren({
        // Demo button
        (new Toggleable)->SetPosition(20, 20)->SetSize(160, 200)->AddChildren({
            // Background
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(Color::gray)->SetOutlineColor(Color::white)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(Color::dimGray)->SetOutlineColor(Color::white)}),

            // Instruction press text
            (new Text)->SetY(20)->SetText("Press (x)")->SetFontSize(20)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::top, Text::FontAlign::ascender)->SetPreTick(UpdateClicksText),


            // Icons for each 2 length state
            (new Looped)->SetPosition(10 + (140 / 2) * 0, 50)->SetSize(140 / 2, 40)->SetLoopLength(2)->SetLoopTargets({0})->AddChildren({
                (new Rectangle)->SetFillColor(Color::lime),
                (new Text)->SetText("Len: 2\nTar: 0")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
            }),
            (new Looped)->SetPosition(10 + (140 / 2) * 1, 50)->SetSize(140 / 2, 40)->SetLoopLength(2)->SetLoopTargets({1})->AddChildren({
                (new Rectangle)->SetFillColor(Color::lime),
                (new Text)->SetText("Len: 2\nTar: 1")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
            }),

            // Icons for each 3 length state
            (new Looped)->SetPosition(10 + (140 / 3) * 0, 100)->SetSize(140 / 3, 40)->SetLoopLength(3)->SetLoopTargets({0})->AddChildren({
                (new Rectangle)->SetFillColor(Color::lime),
                (new Text)->SetText("Len: 3\nTar: 0")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
            }),
            (new Looped)->SetPosition(10 + (140 / 3) * 1, 100)->SetSize(140 / 3, 40)->SetLoopLength(3)->SetLoopTargets({1})->AddChildren({
                (new Rectangle)->SetFillColor(Color::lime),
                (new Text)->SetText("Len: 3\nTar: 1")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
            }),
            (new Looped)->SetPosition(10 + (140 / 3) * 2, 100)->SetSize(140 / 3, 40)->SetLoopLength(3)->SetLoopTargets({2})->AddChildren({
                (new Rectangle)->SetFillColor(Color::lime),
                (new Text)->SetText("Len: 3\nTar: 2")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
            }),

            // Last icons for example multi target 5 length state
            (new Looped)->SetPosition(10, 150)->SetSize(140, 40)->SetLoopLength(5)->SetLoopTargets({0, 1, 3})->AddChildren({
                (new Rectangle)->SetFillColor(Color::blue),
                (new Text)->SetText("Length: 5\nTargets: 0, 1, 3")->SetFontSize(12)->SetColor(Color::white)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
            }),
            (new Looped)->SetPosition(10, 150)->SetSize(140, 40)->SetLoopLength(5)->SetLoopTargets({2, 4})->AddChildren({
                (new Rectangle)->SetFillColor(Color::orange),
                (new Text)->SetText("Length: 5\nTargets: 2, 4")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle, Text::FontAlign::middle),
            }),
        }),

        // Description text
        (new Text)->SetPosition(200, 20)->SetSize(480 - sidebarWidth - 200 - 20, 200)->SetText("Feedback nodes will disable themselves and all child nodes if the closest (parent, grandparent, etc...) interactable node does not meet a specific condition.\n\nThe Looped node will check if the closest parent TOGGLEABLE node is on specific target number of clicks. Setting a loop length will divide the total clicks and use the remainder for the target number conditions, AKA the modulo operator. Similar to C++ arrays, target indexing is zero-based.")->SetFontSize(11)->SetVerticalAlign(Text::VerticalAlign::top)->SetOverflow(Text::Overflow::wrapScale)->SetWrapLineSpacing(1.1),
    });
}