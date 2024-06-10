#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

#include <stdlib.h>
#include <math.h>

using namespace KOWGUI;

// Add a new line to the slide with random vertices, color, and width
void AddRandomLine(BaseNode* thisNode) {
    panels.lineDemo->AddChild(
        (new Line)->
            SetPositions(
                rand() % (480 - sidebarWidth), 
                rand() % 240, 
                rand() % (480 - sidebarWidth), 
                rand() % 240)->
            SetColor((new Color)->SetRGB(
                rand() % 255,
                rand() % 255,
                rand() % 255
            ))->
            SetLineWidth(rand() % 10 + 3)
    );
}

void InitGUILineDemo() {
    panels.lineDemo->AddChildren({
        // Basic red and green lines demonstrating width
        (new Line)->SetPositions(50, 50, 75, 190)->SetColor(Color::red)->SetLineWidth(1),
        (new Line)->SetPositions(100, 190, 125, 50)->SetColor(Color::lime)->SetLineWidth(5),
        // Blue line with a circular animation on second vertex
        (new Line)->SetPositions(175, 50, 200, 190)->SetColor(Color::blue)->SetLineWidth(20)->SetPreTick([](BaseNode* thisNode){
            ((Line*)thisNode)->SetPosition2(
                cos(vexSystemTimeGet() / 1000.0) * 50 + 250,
                sin(vexSystemTimeGet() / 1000.0) * 50 + 150);
        }),
        // Button to generate a new random line
        (new Clickable)->SetPosition(0, 0)->SetSize(30, 30)->SetRelease(AddRandomLine)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetPosition(8, 2)->SetText("?")->SetVerticalAlign(VerticalAlign::ascender),
        }),
    });
}