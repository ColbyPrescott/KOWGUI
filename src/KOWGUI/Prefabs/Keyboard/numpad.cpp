#include "KOWGUI/Prefabs/keyboard.h"

#include "KOWGUI/kowgui.h"

#include <memory>

using namespace KOWGUI;

namespace {

    const int windowBarHeight = 20;

    const int closeButtonIconMargin = 3;
    const int closeButtonIconLineWidth = 2;

    std::shared_ptr<Color> backgroundColor((new Color)->SetHex("#424242"));
    std::shared_ptr<Color> buttonNFocusedColor((new Color)->SetHex("#6e6e6e"));
    std::shared_ptr<Color> buttonFocusedColor((new Color)->SetHex("#a3a3a3"));
    std::shared_ptr<Color> highlightColor((new Color)->SetHex("#ffffff"));

    void TypeDigitFromDataAtEnd(BaseNode* thisNode) {

    }

    void CloseNumpad(BaseNode* thisNode) {
        thisNode->parent->parent->SetDisabled(true);
    }

    // Template prefab for a standard key like 1, 2, or 3
    Clickable* CreateKey(char keyCharacter) {
        return (new Clickable)->SetRelease(TypeDigitFromDataAtEnd)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocusedColor.get())->SetOutlineColor(highlightColor.get())}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocusedColor.get())->SetOutlineColor(highlightColor.get())}),

            (new Text)->SetPosition(1, 2)->SetText("%c", keyCharacter)->SetFont(Fonts::monospace)->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetColor(highlightColor.get()),

            (new Data)->SetShallowID("data")->SetProperty("keyCharacter", new char(keyCharacter)),
        });
    }

    // Template prefab for keys that need more text visible and a different release function, like the decimal and delete keys
    Clickable* CreateSpecialKey(std::string text) {
        return (new Clickable)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocusedColor.get())->SetOutlineColor(highlightColor.get())}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocusedColor.get())->SetOutlineColor(highlightColor.get())}),

            (new Text)->SetPosition(1, 2)->SetText(text)->SetFont(Fonts::monospace)->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetColor(highlightColor.get()),
        });
    }

}

// Create a standard numpad prefab for typing numbers
Group* Keyboard::CreateNumpad(int x, int y, int width, int height, bool movable, bool resizable) {
    return (new Group)->SetDisabled(true)->AddChildren({
        (new Draggable)->SetPosition(x, y)->SetSize(width, windowBarHeight)->AddChildren({
            // Window bar background
            (new Rectangle)->SetFillColor(Color::dimGray)->SetOutlineColor(highlightColor.get()),

            // Window bar text
            (new Text)->SetText("Numpad")->SetFontSize(windowBarHeight - 4)->SetAlignments(HorizontalAlign::left, VerticalAlign::middle),

            // Close button
            (new Clickable)->SetPosition(width - windowBarHeight, 0)->SetSize(windowBarHeight, windowBarHeight)->SetRelease(CloseNumpad)->AddChildren({
                (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocusedColor.get())->SetOutlineColor(highlightColor.get())}),
                (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocusedColor.get())->SetOutlineColor(highlightColor.get())}),

                (new Line)->SetPositions(closeButtonIconMargin, closeButtonIconMargin, windowBarHeight - closeButtonIconMargin, windowBarHeight - closeButtonIconMargin)->SetColor(highlightColor.get())->SetLineWidth(closeButtonIconLineWidth),
                (new Line)->SetPositions(closeButtonIconMargin, windowBarHeight - closeButtonIconMargin, windowBarHeight - closeButtonIconMargin, closeButtonIconMargin)->SetColor(highlightColor.get())->SetLineWidth(closeButtonIconLineWidth),
            }),

            // Clickable to absorb inputs and reposition area
            (new Clickable)->SetPosition(0, windowBarHeight)->SetSize(width, height)->AddChildren({
                // Numpad grid layout
                (new Column)->SetScaleToFit(true)->AddChildren({
                    (new Rectangle)->SetFillColor(Color::black)->SetOutlineColor(highlightColor.get())->AddChildren({
                        (new Text)->SetText("418")->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetOverflow(Overflow::wrapScale),
                    }),
                    (new Row)->SetScaleToFit(true)->AddChildren({
                        CreateKey('7'),
                        CreateKey('8'),
                        CreateKey('9'),
                    }),
                    (new Row)->SetScaleToFit(true)->AddChildren({
                        CreateKey('4'),
                        CreateKey('5'),
                        CreateKey('6'),
                    }),
                    (new Row)->SetScaleToFit(true)->AddChildren({
                        CreateKey('1'),
                        CreateKey('2'),
                        CreateKey('3'),
                    }),
                    (new Row)->SetScaleToFit(true)->AddChildren({
                        (new Rectangle)->SetShallowID("intMessage")->SetDisabled(true)->SetFillColor(buttonNFocusedColor.get())->SetOutlineColor(highlightColor.get())->AddChildren({
                            (new Text)->SetText("Int")->SetFontSize(20)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetOverflow(Overflow::wrapScale),
                        }),
                        CreateSpecialKey(".")->SetShallowID("decimalKey")->SetDisabled(false),
                        CreateKey('0'),
                        CreateSpecialKey("<"),
                    }),
                }),
            }),
        }),
    });
}

// Open a numpad with an initialization integer, then call a function once the keyboard is closed
void Keyboard::Open(Group* numpad, int startNum, void (*closeCalback)(int)) {
    numpad->SetDisabled(false);
}