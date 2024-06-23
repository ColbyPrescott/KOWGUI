#include "TestGUI/sidebar.h"

#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include <string>

using namespace KOWGUI;

// Add a panel button to the sidebar
void CreateSidebarButton(Group* panel, std::string text, int height) {
    Draggable* sidebarDraggable = (Draggable*)gui.FindID("sidebarDraggable");

    void (*loadPanelFunc)(BaseNode*) = [](BaseNode* thisNode){
        Data* dataNode = (Data*)thisNode->FindShallowID("data");
        Group* targetPanel = (Group*)dataNode->GetProperty("panel");
        LoadPanel(targetPanel);
    };

    // Add a new button to the draggable node, positioned at it's height
    Clickable* button = sidebarDraggable->AddChild(
        (new Clickable)->SetPosition(-sidebarWidth + sidebarScrollbarWidth, sidebarDraggable->GetHeight())->SetSize(sidebarWidth - sidebarScrollbarWidth, height)->SetRelease(loadPanelFunc)->AddChildren({
            (new Data)->SetShallowID("data")->SetProperty("panel", (void*)panel),
            (new NFocused)->AddChildren({
                (new Rectangle)->SetFillColor(theme.buttonNFocused)
            }),
            (new Focused)->AddChildren({
                (new Rectangle)->SetFillColor(theme.buttonFocused)
            }),
            (new Text)->SetPosition(0, height / 2)->SetText(text)->SetFont(Fonts::proportional)->SetFontSize(12)->SetColor(theme.lightText)->SetFontAlign(FontAlign::middle)->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(1.1)
        })
    );

    // Expand draggable height for the next button
    sidebarDraggable->SetHeight(sidebarDraggable->GetHeight() + height + 3);

    // Expand scrollable range
    sidebarDraggable->SetMinY(-sidebarDraggable->GetHeight());
    sidebarDraggable->SetMaxY(sidebarDraggable->GetHeight());
}

// Create the sidebar that navigates between demo panels
void InitGUISidebar() {
    gui.root->AddChildren({
        (new Group)->SetPosition(0, 0)->SetSize(100, 240)->AddChildren({
            (new Rectangle)->SetFillColor(theme.sidebarBackground),
            (new Draggable)->SetID("sidebarDraggable")->SetPosition(sidebarWidth - sidebarScrollbarWidth, 0)->SetSize(20, 0)->SetRange(sidebarWidth - sidebarScrollbarWidth, 0, sidebarWidth, 0)->AddChildren({
                (new Rectangle)->SetFillColor(theme.scrollbar)
            })
        })
    });
}

// Individual buttons are added in src/TestGUI/panelManager.cpp InitPanels() with the rest of the initialization steps