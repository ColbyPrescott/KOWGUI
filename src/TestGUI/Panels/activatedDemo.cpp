#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

void InitGUIActivatedDemo() {
    panels.activatedDemo->AddChildren({
        // Demo button
        (new Toggleable)->SetPosition(20, 20)->SetSize(160, 120)->AddChildren({
            // Background
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(Color::gray)->SetOutlineColor(Color::white)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(Color::dimGray)->SetOutlineColor(Color::white)}),

            // Instruction press text
            (new Text)->SetY(20)->SetText("Press")->SetFontSize(20)->SetAlignments(HorizontalAlign::center, VerticalAlign::top, FontAlign::ascender),

            // Icons for not activated and activated
            (new NActivated)->SetPosition(10, 60)->SetSize(70, 50)->AddChildren({
                (new Rectangle)->SetFillColor(Color::red),
                (new Text)->SetText("NActivated")->SetFontSize(12)->SetColor(Color::white)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
            }),
            (new Activated)->SetPosition(80, 60)->SetSize(70, 50)->AddChildren({
                (new Rectangle)->SetFillColor(Color::lime),
                (new Text)->SetText("Activated")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
            }),
        }),

        // Description text
        (new Text)->SetPosition(200, 20)->SetSize(480 - sidebarWidth - 200 - 20, 200)->SetText("Feedback nodes will disable themselves and all child nodes if the closest (parent, grandparent, etc...) interactable node does not meet a specific condition.\n\nThe Activated and NActivated (Not Activated) nodes will check if the closest TOGGLEABLE node is activated or not. That is, a shortcut for whether the internal click counter is odd or even.")->SetFontSize(11)->SetVerticalAlign(VerticalAlign::top)->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(1.1),
    });
}