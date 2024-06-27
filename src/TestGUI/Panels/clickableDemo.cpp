#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include <string>
#include <iostream>

using namespace KOWGUI;

vex::task readTask;

int ReadLoop() {
    while(true) {
        // Retrieve single character from input buffer
        char data;
        std::cin.get(data);

        // Print single letter to terminal
        // std::cout << data << " - " << (int)data << std::endl;
        std::cout << data;


        // Find text node
        Text* keyCodeText = (Text*)gui.FindID("keyCodeText");
        Text* totalText = (Text*)gui.FindID("totalText");

        // Get existing text
        std::string existingKeyCodeText = keyCodeText->GetText().substr(0, 50);
        std::string existingTotalText = totalText->GetText();
        if(existingTotalText.size() > 150) existingTotalText = existingTotalText.substr(1);

        // Append input character and key code to front of existingtext
        keyCodeText->SetText("%c - %d\n%s", data, (int)data, existingKeyCodeText.c_str());
        totalText->SetText("%s%c", existingTotalText.c_str(), data);

        vex::task::sleep(20);
    }
}

void InitGUIClickableDemo() {
    readTask = vex::task(ReadLoop);

    panels.clickableDemo->AddChildren({
        (new Text)->SetID("keyCodeText")->SetPosition(0, 0)->SetAlignments(HorizontalAlign::left, VerticalAlign::top, FontAlign::ascender),
        (new Text)->SetID("totalText")->SetPosition(140, 0)->SetSize(200, 240)->SetText("Start typing in interactive terminal: ")->SetFontSize(20)->SetAlignments(HorizontalAlign::left, VerticalAlign::top, FontAlign::ascender),
    });
}