#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

#include <string>

using namespace KOWGUI;

namespace DraggableDemo {

    void FrontAppendLineToTextNode(Text* textNode, std::string newLine) {
        static int lineNumber = 0;
        lineNumber++;

        std::string existingText = textNode->GetText().substr(0, 150);

        textNode->SetText("%d: %s\n%s", lineNumber, newLine.c_str(), existingText.c_str());
    }

    void DemoPressed(BaseNode* thisNode) {
        FrontAppendLineToTextNode((Text*)panels.draggableDemo->FindShallowID("stateText"), "Press function");
    }

    void DemoReleased(BaseNode* thisNode) {
        FrontAppendLineToTextNode((Text*)panels.draggableDemo->FindShallowID("stateText"), "Release function");
    }

    void DemoFocused(BaseNode* thisNode) {
        FrontAppendLineToTextNode((Text*)panels.draggableDemo->FindShallowID("stateText"), "Focus function");
    }

    void DemoUnfocused(BaseNode* thisNode) {
        FrontAppendLineToTextNode((Text*)panels.draggableDemo->FindShallowID("stateText"), "Unfocus function");
    }

    void UpdatePercentValues(BaseNode* thisNode) {
        Text* textNode = (Text*)panels.draggableDemo->FindShallowID("valueText");
        Draggable* demoDraggable = (Draggable*)panels.draggableDemo->FindShallowID("demoDraggable");

        textNode->SetText("Value X: %.2f%%%%\nValue Y: %.2f%%%%", demoDraggable->GetPercentX() * 100.0, demoDraggable->GetPercentY() * 100.0);
    }

}

using namespace DraggableDemo;

void InitGUIDraggableDemo() {
    panels.draggableDemo->AddChildren({
        // Function log
        (new Text)->SetShallowID("stateText")->SetPosition(140, 10)->SetSize(480 - sidebarWidth - 140 - 10, 130)->SetText("State")->SetFontSize(20)->SetAlignments(HorizontalAlign::left, VerticalAlign::top, FontAlign::ascender)->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(1.8)->AddChildren({
            (new Rectangle)->SetY(130)->SetFillColor(Color::black),
            (new Line)->SetY1(140)->SetY2(140)->SetColor(Color::white)->SetLineWidth(2),
        }),

        // Percent value info
        (new Text)->SetShallowID("valueText")->SetPosition(140, 170)->SetText("Value X: xxx%%\nValue Y: xxx%%")->SetFontSize(20)->SetAlignments(HorizontalAlign::left, VerticalAlign::top, FontAlign::ascender)->SetPreTick(UpdatePercentValues),

        // Highlight for the draggable range
        (new Rectangle)->SetPosition(10, 10)->SetSize(120, 220)->SetOutlineColor(Color::white)->SetOutlineWidth(2),

        // Demo draggable
        (new Draggable)->SetShallowID("demoDraggable")->SetPosition(30, 30)->SetSize(80, 80)->SetRange(10, 10, 130, 230)->SetPress(DemoPressed)->SetRelease(DemoReleased)->SetFocus(DemoFocused)->SetUnfocus(DemoUnfocused)->AddChildren({
            (new Rectangle)->SetFillColor(Color::gray)->SetOutlineColor(Color::white),
            (new Text)->SetText("Drag")->SetFontSize(20)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
        }),

        // Info help button
        (new Clickable)->SetPosition(50, 160)->SetSize(40, 40)->AddChildren({
            (new NSelected)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Selected)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetPosition(1, 2)->SetText("?")->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle, FontAlign::middle),
            
            (new Selected)->SetPosition(-50, -160)->SetSize(480 - sidebarWidth, 140)->AddChildren({
                (new Rectangle)->SetFillColor(Color::gray),
                (new Text)->SetText("Same features as the Clickable node with some additions:\n\n- Draggables will automatically follow continuous user input while selected.\n- Draggables will try to move even while not focused.\n- Position can be constrained with minimum and maximum X and Y coordinates. Minimum for top / left edge, maximum for bottom / right edge.\n- When a X or Y range is defined, position can be retrieved as a percentage.\n\nTouchscreen input is slow to respond. Dragging slowly works better.")->SetFontSize(10)->SetFontAlign(FontAlign::ascender),
            }),
        }),
    });
}