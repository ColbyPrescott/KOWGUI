#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

void InitGUIFocusedDemo() {
    panels.focusedDemo->AddChildren({
        // Demo button
        (new Clickable)->SetPosition(20, 20)->SetSize(160, 120)->AddChildren({
            // Background
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(Color::gray)->SetOutlineColor(Color::white)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(Color::dimGray)->SetOutlineColor(Color::white)}),

            // Instruction hold text
            (new Text)->SetY(20)->SetText("Hold")->SetFontSize(20)->SetAlignments(HorizontalAlign::center, VerticalAlign::top, FontAlign::ascender),

            // Icons for not focused and focused
            (new NFocused)->SetPosition(10, 60)->SetSize(70, 50)->AddChildren({
                (new Rectangle)->SetFillColor(Color::red),
                (new Text)->SetText("NFocused")->SetFontSize(12)->SetColor(Color::white)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
            }),
            (new Focused)->SetPosition(80, 60)->SetSize(70, 50)->AddChildren({
                (new Rectangle)->SetFillColor(Color::lime),
                (new Text)->SetText("Focused")->SetFontSize(12)->SetColor(Color::black)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
            }),
        }),

        // Description text
        (new Text)->SetPosition(200, 20)->SetSize(480 - sidebarWidth - 200 - 20, 200)->SetText("Feedback nodes will disable themselves and all child nodes if the closest (parent, grandparent, etc...) interactable node does not meet a specific condition.\n\nThe Focused and NFocused (Not Focused) nodes will check if input started AND is still on that interactable node.")->SetFontSize(11)->SetVerticalAlign(VerticalAlign::top)->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(1.1),
        (new Text)->SetPosition(20, 170)->SetSize(480 - sidebarWidth - 20 - 20, 200)->SetText("Nodes will only be focused if input is still on top of their area. If continuous input is dragged outside, they can be refocused by dragging input back inside. The release function is a good place to put button code as unfocusing the button can then cancel the click. The Focused node can help display such functionality.")->SetFontSize(11)->SetVerticalAlign(VerticalAlign::top)->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(1.1),
    });
}