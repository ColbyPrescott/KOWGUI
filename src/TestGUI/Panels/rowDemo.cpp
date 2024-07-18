#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include <stdlib.h>

using namespace KOWGUI;

// Add a new rectangle to both row demos
void AppendNodeToRows(BaseNode* thisNode) {
    ((Row*)panels.rowDemo->FindShallowID("uniqueSize"))->AddChild((new Rectangle)->SetWidth(rand() % 60 + 10)->SetFillColor(Color::orange)->SetOutlineColor(Color::white));
    ((Row*)panels.rowDemo->FindShallowID("scaleToFit"))->AddChild((new Rectangle)->SetWidth(rand() % 60 + 10)->SetFillColor(Color::orange)->SetOutlineColor(Color::white));
}

// Update the spacing of both row demos based on the slider
void UpdateSpacing(BaseNode* thisNode) {
    int spacing = ((Draggable*)thisNode)->GetPercentX() * 40;

    ((Row*)panels.rowDemo->FindShallowID("uniqueSize"))->SetSpacing(spacing);
    ((Row*)panels.rowDemo->FindShallowID("scaleToFit"))->SetSpacing(spacing);
}

// Make a node set its width to that of its first child
void CopyChildSize(BaseNode* thisNode) {
    BaseNode* firstChild = thisNode->children[0];
    thisNode->SetSize(firstChild->CalculateWidth(), firstChild->CalculateHeight());
}

// Update the scale to fit demo width to touch the draggable bar
void UpdateScaleToFitWidth(BaseNode* thisNode) {
    panels.rowDemo->FindShallowID("scaleToFit")->SetWidth(thisNode->GetX() - 30);
}



void InitGUIRowDemo() {
    panels.rowDemo->AddChildren({
        // New rectangle button
        (new Clickable)->SetPosition(20, 30)->SetSize(30, 30)->SetRelease(AppendNodeToRows)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetPosition(1, 2)->SetText("+")->SetFontSize(30)->SetHorizontalAlign(Text::HorizontalAlign::center)->SetVerticalAlign(Text::VerticalAlign::middle),
        }),

        // Spacing slider
        (new Group)->SetPosition(70, 30)->SetSize(270, 30)->AddChildren({
            (new Line)->SetPositions(15, 15, 270 - 15, 15)->SetColor(theme.sliderNFocused)->SetLineWidth(10),
            (new Text)->SetText("Spacing")->SetFontSize(20)->SetHorizontalAlign(Text::HorizontalAlign::center)->SetVerticalAlign(Text::VerticalAlign::middle),
            (new Draggable)->SetSize(30, 30)->SetRange(0, 0, 270, 30)->SetPreTick(UpdateSpacing)->AddChildren({
                (new NSelected)->AddChildren({(new Circle)->SetFillColor(theme.sliderNFocused)->SetOutlineColor(Color::lightGray)}),
                (new Selected)->AddChildren({(new Circle)->SetFillColor(theme.sliderFocused)->SetOutlineColor(Color::lightGray)}),
            }),
        }),

        // First row demo with unique sizes
        (new Draggable)->SetPosition(30, 100)->SetHeight(40)->SetPreTick(CopyChildSize)->AddChildren({
            (new Row)->SetShallowID("uniqueSize")->SetSpacing(10)->AddChildren({
                (new Rectangle)->SetSize(40, 40)->SetFillColor(Color::red)->SetOutlineColor(Color::white),
                (new Rectangle)->SetSize(20, 40)->SetFillColor(Color::red)->SetOutlineColor(Color::white),
                (new Rectangle)->SetSize(80, 40)->SetFillColor(Color::red)->SetOutlineColor(Color::white),
                (new Rectangle)->SetSize(40, 40)->SetFillColor(Color::red)->SetOutlineColor(Color::white),
            }),
        }),

        // Second row demo with scale to fit
        (new Group)->SetY(20)->AddChildren({
            (new Row)->SetShallowID("scaleToFit")->SetPosition(30, 150)->SetWidth(200)->SetHeight(40)->SetScaleToFit(true)->SetSpacing(10)->AddChildren({
                (new Rectangle)->SetSize(40, 40)->SetFillColor(Color::red)->SetOutlineColor(Color::white)->AddChildren({
                    (new Text)->SetText("Scale")->SetFontSize(20)->SetHorizontalAlign(Text::HorizontalAlign::center)->SetVerticalAlign(Text::VerticalAlign::middle)->SetOverflow(Text::Overflow::hidden),
                }),
                (new Rectangle)->SetSize(20, 40)->SetFillColor(Color::red)->SetOutlineColor(Color::white)->AddChildren({
                    (new Text)->SetText("To")->SetFontSize(20)->SetHorizontalAlign(Text::HorizontalAlign::center)->SetVerticalAlign(Text::VerticalAlign::middle)->SetOverflow(Text::Overflow::hidden),
                }),
                (new Rectangle)->SetSize(80, 40)->SetFillColor(Color::red)->SetOutlineColor(Color::white)->AddChildren({
                    (new Text)->SetText("Fit")->SetFontSize(20)->SetHorizontalAlign(Text::HorizontalAlign::center)->SetVerticalAlign(Text::VerticalAlign::middle)->SetOverflow(Text::Overflow::hidden),
                }),
                (new Rectangle)->SetSize(40, 40)->SetFillColor(Color::red)->SetOutlineColor(Color::white)->AddChildren({
                    (new Text)->SetText("Grab ->")->SetFontSize(20)->SetHorizontalAlign(Text::HorizontalAlign::center)->SetVerticalAlign(Text::VerticalAlign::middle)->SetOverflow(Text::Overflow::wrapScale)->SetWrapLineSpacing(1),
                }),
            }),

            // Bar to change the width
            (new Draggable)->SetPosition(240, 150)->SetSize(20, 40)->SetRange(100, 150, 340, 190)->SetPreTick(UpdateScaleToFitWidth)->AddChildren({
                (new NSelected)->AddChildren({(new Rectangle)->SetFillColor(theme.sliderNFocused)}),
                (new Selected)->AddChildren({(new Rectangle)->SetFillColor(theme.sliderFocused)}),
                
                (new Line)->SetPositions(5, 5, 5, 35)->SetColor(Color::lightGray)->SetLineWidth(1),
                (new Line)->SetPositions(10, 5, 10, 35)->SetColor(Color::lightGray)->SetLineWidth(1),
                (new Line)->SetPositions(15, 5, 15, 35)->SetColor(Color::lightGray)->SetLineWidth(1),
            }),
        }),
    });
}