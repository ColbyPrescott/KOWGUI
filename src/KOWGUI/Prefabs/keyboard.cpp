#include "KOWGUI/Prefabs/keyboard.h"

#include "KOWGUI/kowgui.h"

#include <stdlib.h>

using namespace KOWGUI;


// Unnamed namespace to avoid polluting global namespace
namespace {

    // Variables for parts of the GUI

    const int screenWidth = 480;
    const int screenHeight = 240;

    const int typingAreaMargin = 5;

    const int closeButtonSize = 40;
    const int closeButtonIconMargin = 10;
    const int closeButtonIconLineWidth = 2;

    const int keySize = 38;

    // TO DO Move these to CreateKeyboard parameters
    Color* buttonNFocused = (new KOWGUI::Color)->SetHex("#1b9477");
    Color* buttonFocused = (new KOWGUI::Color)->SetHex("#26d1a8");
    Color* highlightColor = (new KOWGUI::Color)->SetHex("#ffffff");


    // Variables for keyboard functionality

    std::string typingText = "Some good text UwU";
    int typingCursorIndex = 0;

    std::string* pDirectString = nullptr;


    // Functions for keyboard functionality

    // Called from typing text Text node
    void UpdateTypingText(BaseNode* thisNode) {
        // Cast for specific node
        Text* textNode = (Text*)thisNode;

        // Construct parts of text
        std::string beforeCursor = typingText.substr(0, typingCursorIndex);
        std::string afterCursor = typingText.substr(typingCursorIndex);
        char cursorCharacter = (vexSystemTimeGet() / 500) % 2 == 0 ? '|' : '/'; // Forward slash? Period? Underscore? Space will cause issues with line wrapping

        // Update text
        textNode->SetText("%s%c%s", beforeCursor.c_str(), cursorCharacter, afterCursor.c_str());
    }

    // Called from each standard key Clickable node
    void TypeKeyAtCursor(BaseNode* thisNode) {
        // Construct parts of text
        std::string beforeCursor = typingText.substr(0, typingCursorIndex);
        std::string afterCursor = typingText.substr(typingCursorIndex);
        char characterToAdd = *(char*)((Data*)thisNode->FindShallowID("data"))->GetProperty("keyCharacter");

        // Get whether or not the shift key is pressed
        bool shiftActivated = ((Toggleable*)thisNode->parent->parent->parent->FindShallowID("shiftKey"))->GetActivated();
        // Update characterToAdd to be lowercase or uppercase based on shift key. They are already uppercase, so only do something if they need otherwise
        if(!shiftActivated) characterToAdd = (char)tolower((int)characterToAdd);

        // Update text
        typingText = beforeCursor + characterToAdd + afterCursor;
        // Move cursor to after new character
        typingCursorIndex++;
    }

    // Called from the backspace key Clickable node
    void RemoveKeyAtCursor(BaseNode* thisNode) {
        // Avoid deleting nonexistent characters
        if(typingCursorIndex == 0) return;

        // Construct parts of text
        std::string beforeCursor = typingText.substr(0, typingCursorIndex - 1); // Subtract one before cursor to remove character
        std::string afterCursor = typingText.substr(typingCursorIndex);

        // Update text
        typingText = beforeCursor + afterCursor;
        // Move cursor backwards one as indices shifted
        typingCursorIndex--;
    }

    // Called from the left arrow key Clickable node
    // Move the cursor one character to the right if not already at the end
    void MoveCursorLeft(BaseNode* thisNode) {
        if(typingCursorIndex > 0) typingCursorIndex--;
    }

    // Called from the right arrow key Clickable node
    // Move the cursor one character to the left if not already at the beginning
    void MoveCursorRight(BaseNode* thisNode) {
        if(typingCursorIndex < typingText.size()) typingCursorIndex++;
    }

    // Called from the alphabet key Clickable node
    void SwitchLayoutQWERTY(BaseNode* thisNode) {
        thisNode->parent->parent->parent->FindShallowID("symbolsLayout")->SetDisabled(true);
        thisNode->parent->parent->parent->FindShallowID("QWERTYLayout")->SetDisabled(false);
    }

    // Called from the symbols key Clickable node
    void SwitchLayoutSymbols(BaseNode* thisNode) {
        thisNode->parent->parent->parent->FindShallowID("QWERTYLayout")->SetDisabled(true);
        thisNode->parent->parent->parent->FindShallowID("symbolsLayout")->SetDisabled(false);
    }

    // Called from close button Clickable node
    void CloseKeyboard(BaseNode* thisNode) {
        // If a direct string was edited, update that string and remove the pointer
        if(pDirectString != nullptr) {
            *pDirectString = typingText;
            pDirectString = nullptr;
        }

        // Hide keyboard
        thisNode->parent->SetDisabled(true); // TO DO FindInverseShallowID? Climb the tree structure instead of going deeper? The parent and children variables are not guaranteed to stay public
    }


    // Functions for keyboard building

    // Template node system for a standard key like C, O, D, or E
    Clickable* CreateKey(char keyCharacter) {
        return (new Clickable)->SetSize(keySize, keySize)->SetRelease(TypeKeyAtCursor)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocused)->SetOutlineColor(highlightColor)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocused)->SetOutlineColor(highlightColor)}),

            (new Text)->SetPosition(1, 2)->SetText("%c", keyCharacter)->SetFont(Fonts::monospace)->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetColor(highlightColor),

            (new Data)->SetShallowID("data")->SetProperty("keyCharacter", new char(keyCharacter)),
        });
    }

    // Template node system for the shift key
    Toggleable* CreateToggleKey(std::string text) {
        return (new Toggleable)->SetSize(keySize, keySize)->AddChildren({
            (new NActivated)->AddChildren({
                (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocused)->SetOutlineColor(highlightColor)}),
                (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocused)->SetOutlineColor(highlightColor)}),
            }),
            (new Activated)->AddChildren({
                (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocused)->SetOutlineColor(highlightColor)}),
                (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocused)->SetOutlineColor(highlightColor)}),
            }),

            (new Text)->SetPosition(1, 2)->SetText(text)->SetFont(Fonts::monospace)->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetColor(highlightColor),
        });
    }

    // Template node system for keys that need more text visible and a different release function, like the backspace or arrow keys
    Clickable* CreateSpecialKey(std::string text, char keyCharacterOverride = ' ') {
        // Bare bones key with no functionality
        Clickable* pPrefab = (new Clickable)->SetSize(keySize, keySize)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocused)->SetOutlineColor(highlightColor)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocused)->SetOutlineColor(highlightColor)}),

            (new Text)->SetPosition(1, 2)->SetText(text)->SetFont(Fonts::monospace)->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetColor(highlightColor),
        });

        // If they special key just needs different data than text being displayed, add in the standard key functionality
        if(keyCharacterOverride != ' ') {
            pPrefab->AddChild((new Data)->SetShallowID("data")->SetProperty("keyCharacter", new char(keyCharacterOverride)));
            pPrefab->SetRelease(TypeKeyAtCursor);
        }

        // Return the fully built prefab
        return pPrefab;
    }
    
}

Group* Keyboard::CreateKeyboard() {
    return (new Group)->SetDisabled(true)->SetSize(screenWidth, screenHeight)->AddChildren({
        // Clickable to absorb inputs behind buttons
        (new Clickable),

        // Background
        (new Rectangle)->SetFillColor(Color::darkSlateGray),

        // Typing text
        (new Rectangle)->SetPosition(typingAreaMargin, typingAreaMargin)->SetSize(screenWidth - closeButtonSize - typingAreaMargin * 2, screenHeight - keySize * 4 - typingAreaMargin * 2)->SetFillColor(Color::black)->SetOutlineColor(highlightColor)->AddChildren({
            (new Text)->SetText("Error, someting went tewwibwy wong, sowwy! <:3")->SetFont(Fonts::monospace)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetOverflow(Overflow::wrapScale)->SetWrapLineSpacing(1.1)->SetPreTick(UpdateTypingText),
        }),

        // Close button
        (new Clickable)->SetPosition(screenWidth - closeButtonSize, typingAreaMargin)->SetSize(closeButtonSize, closeButtonSize)->SetRelease(CloseKeyboard)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocused)->SetOutlineColor(highlightColor)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocused)->SetOutlineColor(highlightColor)}),

            (new Line)->SetPositions(closeButtonIconMargin, closeButtonIconMargin, closeButtonSize - closeButtonIconMargin, closeButtonSize - closeButtonIconMargin)->SetColor(highlightColor)->SetLineWidth(closeButtonIconLineWidth),
            (new Line)->SetPositions(closeButtonIconMargin, closeButtonSize - closeButtonIconMargin, closeButtonSize - closeButtonIconMargin, closeButtonIconMargin)->SetColor(highlightColor)->SetLineWidth(closeButtonIconLineWidth),
        }),

        // QWERTY character keys
        (new Column)->SetShallowID("QWERTYLayout")->SetDisabled(false)->SetPosition(0, screenHeight - keySize * 4)->AddChildren({
            (new Row)->SetX(keySize * 0.0 / 3.0)->AddChildren({
                CreateKey('Q'),
                CreateKey('W'),
                CreateKey('E'),
                CreateKey('R'),
                CreateKey('T'),
                CreateKey('Y'),
                CreateKey('U'),
                CreateKey('I'),
                CreateKey('O'),
                CreateKey('P'),
                CreateSpecialKey("<--")->SetWidth(screenWidth - keySize * 10)->SetRelease(RemoveKeyAtCursor),
            }),
            (new Row)->SetX(keySize * 1.0 / 3.0)->AddChildren({
                CreateKey('A'),
                CreateKey('S'),
                CreateKey('D'),
                CreateKey('F'),
                CreateKey('G'),
                CreateKey('H'),
                CreateKey('J'),
                CreateKey('K'),
                CreateKey('L'),
                CreateSpecialKey("Enter", '\n')->SetWidth(screenWidth - keySize * 9.333),
            }),
            (new Row)->SetX(keySize * 2.0 / 3.0)->AddChildren({
                CreateKey('Z'),
                CreateKey('X'),
                CreateKey('C'),
                CreateKey('V'),
                CreateKey('B'),
                CreateKey('N'),
                CreateKey('M'),
                (new Text)->SetSize(screenWidth - keySize * 7.666, keySize)->SetText("Interactive terminal something something...")->SetFontSize(10)->SetColor(highlightColor)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
            }),
            (new Row)->AddChildren({
                CreateToggleKey("Shift")->SetShallowID("shiftKey")->SetWidth(keySize * (2 + 2.0 / 3.0)),
                CreateKey(' ')->SetWidth(keySize * 5),
                CreateSpecialKey("<")->SetWidth(keySize * 1.5)->SetRelease(MoveCursorLeft),
                CreateSpecialKey(">")->SetWidth(keySize * 1.5)->SetRelease(MoveCursorRight),
                CreateSpecialKey("#!?")->SetWidth(screenWidth - keySize * 10.666)->SetRelease(SwitchLayoutSymbols),
            }),
        }),

        // Symbol character keys
        (new Column)->SetShallowID("symbolsLayout")->SetDisabled(true)->SetPosition(0, screenHeight - keySize * 4)->AddChildren({
            (new Row)->AddChildren({
                CreateKey('1'),
                CreateKey('2'),
                CreateKey('3'),
                CreateKey('4'),
                CreateKey('5'),
                CreateKey('6'),
                CreateKey('7'),
                CreateKey('8'),
                CreateKey('9'),
                CreateKey('0'),
                CreateSpecialKey("<--")->SetWidth(screenWidth - keySize * 10)->SetRelease(RemoveKeyAtCursor),
            }),
            (new Row)->AddChildren({
                CreateKey('!'),
                CreateKey('@'),
                CreateKey('#'),
                CreateKey('$'),
                CreateKey('%'),
                CreateKey('^'),
                CreateKey('&'),
                CreateKey('*'),
                CreateKey('('),
                CreateKey(')'),
                CreateKey('-'),
                CreateKey('='),
            }),
            (new Row)->AddChildren({
                CreateKey('['),
                CreateKey(']'),
                CreateKey('{'),
                CreateKey('}'),
                CreateKey('/'),
                CreateKey('|'),
                CreateKey('\\'),
                CreateKey('.'),
                CreateKey(','),
                CreateKey('?'),
                CreateKey('_'),
                CreateKey('+'),
            }),
            (new Row)->AddChildren({
                CreateKey('<'),
                CreateKey('>'),
                CreateKey('`'),
                CreateKey('~'),
                CreateKey(' ')->SetWidth(keySize * 2),
                CreateKey(';'),
                CreateKey(':'),
                CreateKey('\''),
                CreateKey('"'),
                CreateSpecialKey("ABC")->SetWidth(screenWidth - keySize * 10)->SetRelease(SwitchLayoutQWERTY),
            }),
        }),
    });
}

// Open a keyboard with direct access to a string
void Keyboard::Open(Group* pKeyboard, std::string& str) {
    // Copy typing text to the editing string
    typingText = str;

    // Note the address of the string being edited directly
    pDirectString = &str;

    // Show keyboard
    pKeyboard->SetDisabled(false);
}