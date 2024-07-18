#include "TestGUI/sidebar.h"

#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include <string>

using namespace KOWGUI;

// Add a panel button to the sidebar
void CreateSidebarButton(Group* panel, std::string text, int height) {
    // Find the sidebar node
    Draggable* sidebarDraggable = (Draggable*)gui.FindID("sidebarDraggable");

    // Function for each panel button. Gets the panel stored as data and loads it
    void (*loadPanelFunc)(BaseNode*) = [](BaseNode* thisNode){
        Data* dataNode = (Data*)thisNode->FindShallowID("data");
        Group* targetPanel = (Group*)dataNode->GetProperty("panel").get();
        LoadPanel(targetPanel);
    };

    // Add a new button to the draggable node, positioned at it's height
    sidebarDraggable->AddChild(
        (new Clickable)->SetPosition(-sidebarWidth + sidebarScrollbarWidth, sidebarDraggable->GetHeight())->SetSize(sidebarWidth - sidebarScrollbarWidth, height)->SetRelease(loadPanelFunc)->AddChildren({
            (new Data)->SetShallowID("data")->SetProperty("panel", std::shared_ptr<void>(panel)),

            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetPosition(0, height / 2)->SetText(text)->SetFont(Text::fontProportional)->SetFontSize(12)->SetColor(theme.lightText)->SetFontAlign(Text::FontAlign::middle)->SetHorizontalAlign(Text::HorizontalAlign::center)->SetOverflow(Text::Overflow::wrap)->SetWrapLineSpacing(1.1)
        })
    );

    // Expand draggable height for the next button
    sidebarDraggable->SetHeight(sidebarDraggable->GetHeight() + height + 3);

    // Expand scrollable range
    sidebarDraggable->SetMinY(-sidebarDraggable->GetHeight() + 240);
    sidebarDraggable->SetMaxY(sidebarDraggable->GetHeight());
}

// Add a space with text to the sidebar
void CreateSidebarLabel(std::string text, int height) {
    // Find the sidebar node
    Draggable* sidebarDraggable = (Draggable*)gui.FindID("sidebarDraggable");

    // Add a new node to the draggable node, positioned at it's height
    sidebarDraggable->AddChild(
        (new Group)->SetPosition(-sidebarWidth + sidebarScrollbarWidth, sidebarDraggable->GetHeight())->SetSize(sidebarWidth - sidebarScrollbarWidth, height)->AddChildren({
            (new Text)->SetY(-10)->SetText(text)->SetFont(Text::fontProportional)->SetFontSize(12)->SetColor(theme.lightText)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::bottom)->SetOverflow(Text::Overflow::wrap)->SetWrapLineSpacing(1.1),
            (new Line)->SetPositions(5, height - 5, sidebarWidth - sidebarScrollbarWidth - 5, height - 5)->SetColor(theme.lightText),
        })
    );

    // Expand draggable height for the next node
    sidebarDraggable->SetHeight(sidebarDraggable->GetHeight() + height + 3);

    // Expand scrollable range
    sidebarDraggable->SetMinY(-sidebarDraggable->GetHeight() + 240);
    sidebarDraggable->SetMaxY(sidebarDraggable->GetHeight());
}

// Create the sidebar that navigates between demo panels
void InitGUISidebar() {
    gui.root->AddChildren({
        (new Group)->SetPosition(0, 0)->SetSize(100, 240)->AddChildren({
            (new Rectangle)->SetFillColor(theme.sidebarBackground),
            (new Draggable)->SetID("sidebarDraggable")->SetPosition(sidebarWidth - sidebarScrollbarWidth, 0)->SetSize(20, 0)->SetRange(sidebarWidth - sidebarScrollbarWidth, 0, sidebarWidth, 0)->AddChildren({
                (new NSelected)->AddChildren({(new Rectangle)->SetFillColor(theme.sliderNFocused)}),
                (new Selected)->AddChildren({(new Rectangle)->SetFillColor(theme.sliderFocused)}),
            })
        })
    });
}

// Individual buttons are added in src/TestGUI/panelManager.cpp InitPanels() with the rest of the initialization steps