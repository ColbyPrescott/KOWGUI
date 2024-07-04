#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include <iostream>

using namespace KOWGUI;

namespace {

    // Called from the Remove Mosaic button Clickable node
    void DeleteRemovalTestA(BaseNode* thisNode) {
        delete panels.removalDemo->FindShallowID("removalTestA");
    }

}

void InitGUIRemovalDemo() {
    panels.removalDemo->AddChildren({
        // Mosaic to delete
        (new Rectangle)->SetShallowID("removalTestA")->SetPosition(200, 30)->SetSize(50, 50)->SetFillColor(Color::red)->AddChildren({
            (new Rectangle)->SetPosition(20, 40)->SetSize(40, 30)->SetFillColor(Color::lime)->SetOutlineColor(Color::white)->SetOutlineWidth(5),
            (new Rectangle)->SetPosition(-20, -20)->SetSize(80, 5)->SetFillColor(Color::blue)->AddChildren({
                (new Circle)->SetPosition(70, 70)->SetWidth(20)->SetFillColor(Color::cyan),
                (new Circle)->SetPosition(60, 110)->SetWidth(15)->SetFillColor(Color::white),
            }),
            (new Rectangle)->SetPosition(30, 10)->SetSize(80, 5)->SetFillColor(Color::purple),
        }),

        // Button to delete the mosaic
        (new Clickable)->SetPosition(30, 30)->SetSize(100, 50)->SetRelease(DeleteRemovalTestA)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),
            (new Text)->SetText("Remove Mosaic")->SetFontSize(18)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
        }),
    });
}