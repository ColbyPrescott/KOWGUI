#include "KOWGUI/Prefabs/keyboard.h"

#include "KOWGUI/kowgui.h"

#include <memory>
#include <math.h>

using namespace KOWGUI;

namespace {

    // Variables for parts of the GUI

    const int windowBarHeight = 20;

    const int closeButtonIconMargin = 3;
    const int closeButtonIconLineWidth = 2;

    std::shared_ptr<Color> windowBarColor((new Color)->SetHex("#424242"));
    std::shared_ptr<Color> buttonNFocusedColor((new Color)->SetHex("#6e6e6e"));
    std::shared_ptr<Color> buttonFocusedColor((new Color)->SetHex("#a3a3a3"));
    std::shared_ptr<Color> highlightColor((new Color)->SetHex("#ffffff"));



    // Variables for numpad functionality

    // Representation of the number currently being typed. Represented as one giant integer for simpler code
    int32_t typingNumberAsInteger = 0;
    // Whether or not decimals are currently being typed
    bool typingDecimals = false;
    // How many digits of typingNumberAsInteger are placed after the decimal
    int numTypingDecimalDigits = 0;

    const int maxTypingInteger = 2147483647; // 32 bit signed integer limit

    void (*pUpdateFuncInt)(int) = nullptr;
    void (*pUpdateFuncDouble)(double) = nullptr;
    bool callUpdateFuncOnChange = false;


    // Functions for numpad functionality

    // Call the update function that is set
    void CallUpdateFunction() {
        if(pUpdateFuncInt != nullptr) pUpdateFuncInt(typingNumberAsInteger);
        if(pUpdateFuncDouble != nullptr) pUpdateFuncDouble((double)typingNumberAsInteger / pow(10, numTypingDecimalDigits));
    }

    // Called from each digit key
    void TypeDigitFromDataAtEnd(BaseNode* thisNode) {
        // Return immidiately if the more easily detectable multiplication error will occur
        if(typingNumberAsInteger > maxTypingInteger / 10 || typingNumberAsInteger < -maxTypingInteger / 10) return;
        // Save old typing number for detecting and reverting integer overflow in single digits
        int32_t prevTypingNumberAsInteger = typingNumberAsInteger;

        int digitToAdd = *(int*)((Data*)thisNode->FindShallowID("data"))->GetProperty("keyDigit");
        // Shift all digits left by one digit, making room for a zero, then converted to new digit by adding / subtracting it
        typingNumberAsInteger *= 10;
        if(typingNumberAsInteger >= 0) typingNumberAsInteger += digitToAdd;
        else typingNumberAsInteger -= digitToAdd;

        // If integer overflow in single digits, revert changes
        if((prevTypingNumberAsInteger >= 0) != (typingNumberAsInteger >= 0)) {
            typingNumberAsInteger = prevTypingNumberAsInteger;
            return;
        }

        // If currently typing decimals, this new digit should add to the number of digits after the decimal
        if(typingDecimals) numTypingDecimalDigits++;

        // Call update function if scheduled
        if(callUpdateFuncOnChange) CallUpdateFunction();
    }

    // Called from the backspace key Clickable node
    void RemoveDigitFromEnd(BaseNode* thisNode) {
        // Edge case where the decimal key was pressed, then no digits were typed
        if(typingDecimals && numTypingDecimalDigits == 0) {
            // Just stop the mode for typing decimals
            typingDecimals = false;
            // No need to do anything else
            return;
        }

        // Shift all digits right by one digit. typingNumberAsInteger is an integer, so the shifted digit automatically gets cut off
        typingNumberAsInteger /= 10;

        // If currently typing decimals, this removed digit should remove from the number of digits after the decimal
        if(typingDecimals) numTypingDecimalDigits--;
        // If the last decimal was removed, stop typing decimal mode
        if(numTypingDecimalDigits == 0) typingDecimals = false;

        // Call update function if scheduled
        if(callUpdateFuncOnChange) CallUpdateFunction();
    }

    // Called from the decimal key Clickable node
    void StartTypingDecimal(BaseNode* thisNode) {
        // Enable mode for typing decimals. If it's already true, this won't change anything
        typingDecimals = true;
    }

    // Called from the sign key Clickable node
    void InvertTypingNumberSign(BaseNode* thisNode) {
        typingNumberAsInteger *= -1;

        // Call update function if scheduled
        if(callUpdateFuncOnChange) CallUpdateFunction();
    }

    // Called from the typing number Text node
    void UpdateTypingTextNode(BaseNode* thisNode) {
        // If not typing a decimal, simply display the integer as is
        if(!typingDecimals) ((Text*)thisNode)->SetText("%d", typingNumberAsInteger);
        else {
            // If typing decimal, display it by splitting the number before and after the decimal character and putting a period in between
            int digitsBeforeDecimal = fabs((double)typingNumberAsInteger / pow(10, numTypingDecimalDigits)); // Cast to integer floors number with both positive and negative numbers accounted for
            int digitsAfterDecimal = fabs((double)(typingNumberAsInteger % (int)pow(10.0, (double)numTypingDecimalDigits)));
            ((Text*)thisNode)->SetText("%s%d.%d", typingNumberAsInteger < 0 ? "-" : "", digitsBeforeDecimal, digitsAfterDecimal);
        }
    }

    // Called from the close button Clickable node
    void CloseNumpad(BaseNode* thisNode) {
        // Hide numpad
        thisNode->parent->parent->SetDisabled(true);

        // Call update function
        CallUpdateFunction();

        // Remove function pointers to show that they are no longer in use
        pUpdateFuncInt = nullptr;
        pUpdateFuncDouble = nullptr;
    }

    // Template prefab for a standard key like 1, 2, or 3
    Clickable* CreateDigitKey(int keyDigit) {
        return (new Clickable)->SetRelease(TypeDigitFromDataAtEnd)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocusedColor.get())->SetOutlineColor(highlightColor.get())}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocusedColor.get())->SetOutlineColor(highlightColor.get())}),

            (new Text)->SetPosition(1, 2)->SetText("%d", keyDigit)->SetFont(Fonts::monospace)->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetColor(highlightColor.get()),

            (new Data)->SetShallowID("data")->SetProperty("keyDigit", new int(keyDigit)),
        });
    }

    // Template prefab for keys that need more text visible and a different release function, like the decimal and delete keys
    Clickable* CreateSpecialKey(std::string text) {
        return (new Clickable)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(buttonNFocusedColor.get())->SetOutlineColor(highlightColor.get())}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(buttonFocusedColor.get())->SetOutlineColor(highlightColor.get())}),

            (new Text)->SetPosition(1, 2)->SetText(text)->SetFont(Fonts::monospace)->SetFontSize(25)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetColor(highlightColor.get())->SetOverflow(Overflow::wrap)->SetWrapLineSpacing(0.4),
        });
    }

}

// Create a standard numpad prefab for typing numbers
Group* Keyboard::CreateNumpad(int x, int y, int width, int height, bool movable, bool resizable, Color* customWindowBarColor, Color* customButtonNFocusedColor, Color* customButtonFocusedColor, Color* customHighlightColor) {
    // Set colors for prefab generation if they are specified
    if(customWindowBarColor != nullptr) windowBarColor = std::make_shared<Color>(*customWindowBarColor);
    if(customButtonNFocusedColor != nullptr) buttonNFocusedColor = std::make_shared<Color>(*customButtonNFocusedColor);
    if(customButtonFocusedColor != nullptr) buttonFocusedColor = std::make_shared<Color>(*customButtonFocusedColor);
    if(customHighlightColor != nullptr) highlightColor = std::make_shared<Color>(*customHighlightColor);

    // Set the window bar's type of node based on whether it should be movable
    BaseNode* barNode = nullptr;
    if(movable) barNode = new Draggable;
    else barNode = new Clickable;

    // Make and return the numpad prefab
    return (new Group)->SetDisabled(true)->AddChildren({
        barNode->SetPosition(x, y)->SetSize(width, windowBarHeight)->AddChildren({
            // Window bar background
            (new Rectangle)->SetFillColor(windowBarColor.get())->SetOutlineColor(highlightColor.get()),

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
                        (new Text)->SetText("418")->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetOverflow(Overflow::wrapScale)->SetPreTick(UpdateTypingTextNode),
                    }),
                    (new Row)->SetScaleToFit(true)->AddChildren({
                        CreateDigitKey(7),
                        CreateDigitKey(8),
                        CreateDigitKey(9),
                    }),
                    (new Row)->SetScaleToFit(true)->AddChildren({
                        CreateDigitKey(4),
                        CreateDigitKey(5),
                        CreateDigitKey(6),
                    }),
                    (new Row)->SetScaleToFit(true)->AddChildren({
                        CreateDigitKey(1),
                        CreateDigitKey(2),
                        CreateDigitKey(3),
                    }),
                    (new Row)->SetScaleToFit(true)->AddChildren({
                        CreateDigitKey(0),
                        CreateSpecialKey(".")->SetShallowID("decimalKey")->SetDisabled(false)->SetRelease(StartTypingDecimal),
                        CreateSpecialKey("+\n-")->SetRelease(InvertTypingNumberSign),
                        CreateSpecialKey("<")->SetRelease(RemoveDigitFromEnd),
                    }),
                }),
            }),
        }),
    });
}

// Open a numpad with an initialization integer, then call a function once closed or every button press
void Keyboard::Open(Group* numpad, int startNum, void (*updateCallback)(int), bool liveUpdate) {
    // Reset numpad state
    // Initialize typingNumber for modification
    typingNumberAsInteger = startNum;
    // Disable mode for typing decimals
    typingDecimals = false;
    // Since this is an integer, no digits should be part of the decimal
    numTypingDecimalDigits = 0;
    // Hide decimal key
    numpad->FindShallowID("decimalKey")->SetDisabled(true);
    // Remove update functions in case they weren't already removed
    pUpdateFuncInt = nullptr;
    pUpdateFuncDouble = nullptr;

    // Note the address of the function to call once the keyboard is closed / changed
    pUpdateFuncInt = updateCallback;
    // Set whether or not the update function should be called each change, or just when closed
    callUpdateFuncOnChange = liveUpdate;

    // Show numpad
    numpad->SetDisabled(false);
}

// Open a numpad with an initialization double, then call a function once the keyboard is closed
void Keyboard::Open(Group* numpad, double startNum, void (*updateCallback)(double), bool liveUpdate) {
    // Reset numpad state
    // Calculate number of decimal digits
    // Reset counter
    numTypingDecimalDigits = 0;
    // Shift decimal place to the right until tempDecimals is equal to itself with decimals removed
    while(startNum * pow(10, numTypingDecimalDigits) != floor(startNum * pow(10, numTypingDecimalDigits))) numTypingDecimalDigits++;
    // Remove decimal point for typingNumerAsInteger
    typingNumberAsInteger = startNum * pow(10, numTypingDecimalDigits);
    // Set mode for typing decimal based on whether there already is a decimal part
    typingDecimals = numTypingDecimalDigits > 0;
    // Enable the decimal key
    numpad->FindShallowID("decimalKey")->SetDisabled(false);
    // Remove update functions in case they weren't already removed
    pUpdateFuncInt = nullptr;
    pUpdateFuncDouble = nullptr;

    // Note the address of the function to call once the numpad is closed / changed
    pUpdateFuncDouble = updateCallback;
    // Set whether or not the update function should be called each change, or just when closed
    callUpdateFuncOnChange = liveUpdate;

    // Show numpad
    numpad->SetDisabled(false);
}