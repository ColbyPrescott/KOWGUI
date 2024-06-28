#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

void InitGUISelectedDemo() {
    panels.selectedDemo->AddChildren({
        // Demo button
        (new Clickable)->SetPosition(20, 20)->SetSize(160, 120)->AddChildren({
            // Background
            (new NSelected)->AddChildren({(new Rectangle)->SetFillColor(Color::gray)->SetOutlineColor(Color::white)}),
            (new Selected)->AddChildren({(new Rectangle)->SetFillColor(Color::dimGray)->SetOutlineColor(Color::white)}),

            // Instruction hold text
            (new Text)->SetY(20)->SetText("Hold")->SetFontSize(20)->SetAlignments(HorizontalAlign::center, VerticalAlign::top, FontAlign::ascender),

            // Icons for not selected and selected
            (new NSelected)->SetPosition(10, 60)->SetSize(70, 50)->AddChildren({
                (new Rectangle)->SetFillColor(Color::red),
                (new Text)->SetText("NSelected")->SetFontSize(12)->SetColor(Color::white)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
            }),
            (new Selected)->SetPosition(80, 60)->SetSize(70, 50)->AddChildren({
                (new Rectangle)->SetFillColor(Color::lime),
                (new Text)->SetText("Selected")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
            }),
        }),

        // Description text
        (new Text)->SetPosition(200, 20)->SetSize(480 - sidebarWidth - 200 - 20, 200)->SetText("Feedback nodes will disable themselves and all child nodes if the closest (parent, grandparent, etc...) interactable node does not meet a specific condition.\n\nThe Selected and NSelected (Not Selected) nodes will check if input started on that interactable node.")->SetFontSize(11)->SetVerticalAlign(VerticalAlign::top)->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(1.1),
        (new Text)->SetPosition(20, 170)->SetSize(480 - sidebarWidth - 20 - 20, 200)->SetText("Nodes will continue being selected even if continuous input is dragged outside the node area. Thus, because Draggable nodes will continue trying to move in this same case, the Selected node is useful feedback for sliders, scrollbars, and other movable elements.")->SetFontSize(12)->SetVerticalAlign(VerticalAlign::top)->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(1.1),
    });
}