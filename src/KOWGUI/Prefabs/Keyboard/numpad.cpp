#include "KOWGUI/Prefabs/keyboard.h"

#include "KOWGUI/kowgui.h"

#include <memory>

using namespace KOWGUI;

namespace {

    const int edgeMargin = 5;

    const int closeButtonIconMargin = 10;
    const int closeButtonIconLineWidth = 2;

    std::shared_ptr<Color> backgroundColor((new Color)->SetHex("#424242"));
    std::shared_ptr<Color> buttonNFocusedColor((new Color)->SetHex("#6e6e6e"));
    std::shared_ptr<Color> buttonFocusedColor((new Color)->SetHex("#a3a3a3"));
    std::shared_ptr<Color> highlightColor((new Color)->SetHex("#ffffff"));

    void CloseNumpad(BaseNode* thisNode) {
        thisNode->parent->SetDisabled(true);
    }

}

// Create a standard numpad prefab for typing numbers
Group* Keyboard::CreateNumpad(int x, int y, int width, int height, bool movable, bool resizable) {
    const int buttonWidth = (height - edgeMargin * 3) / 4.0;
    const int buttonHeight = (height - edgeMargin * 3) / 4.0;

    return (new Group)->SetDisabled(true)->SetPosition(x, y)->SetSize(width, height)->AddChildren({
        // Clickable to absorb inputs behind buttons
        (new Clickable),

        // Background
        (new Rectangle)->SetFillColor(Color::gray),

        // Close button
        (new Clickable)->SetPosition(edgeMargin, edgeMargin)->SetSize(buttonHeight, buttonHeight)->SetRelease(CloseNumpad)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocusedColor.get())->SetOutlineColor(highlightColor.get())}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocusedColor.get())->SetOutlineColor(highlightColor.get())}),

            (new Line)->SetPositions(closeButtonIconMargin, closeButtonIconMargin, buttonHeight - closeButtonIconMargin, buttonHeight - closeButtonIconMargin)->SetColor(highlightColor.get())->SetLineWidth(closeButtonIconLineWidth),
            (new Line)->SetPositions(closeButtonIconMargin, buttonHeight - closeButtonIconMargin, buttonHeight - closeButtonIconMargin, closeButtonIconMargin)->SetColor(highlightColor.get())->SetLineWidth(closeButtonIconLineWidth),
        }),
    });
}

// Open a numpad with an initialization integer, then call a function once the keyboard is closed
void Keyboard::Open(Group* numpad, int startNum, void (*closeCalback)(int)) {
    numpad->SetDisabled(false);
}