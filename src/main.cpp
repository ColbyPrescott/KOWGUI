/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       crprescott2026                                            */
/*    Created:      4/12/2024, 4:34:09 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "globalVars.h"

#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

#include <iostream>

using namespace vex;

int main() {
    srand(Brain.Timer.systemHighResolution());

    InitGUISidebar();

    InitPanels();

    keyboard = KOWGUI::Keyboard::CreateKeyboard();
    gui.root->AddChild(keyboard);

    LoadPanel(panels.keyboardDemo);

    while(1) {

        gui.Tick();

        // GOAL: Find a way to read a character without waiting, or to detect if a character is ready to be read

        // // Correctly prints every typed letter to a new line. Waits until keyboard input
        // char data;
        // std::cin.get(data);
        // printf("%c\n", data);
        // printf("_\n");

        // // Pure gibberish. Mostly the letter U
        // char data[10];
        // std::cin.readsome(data, 5);
        // printf("%s\n", data);
        // printf("_\n");

        // // Waits until a delimiter is pressed to load whole line. By default, I think Windows might be incapable of typing \n
        // std::string data;
        // std::getline(std::cin, data, 'P');
        // printf("%s\n", data.c_str());

        // // Waits for 5 characters to be typed, then prints new line characters over and over again
        // char data[10];
        // std::cin.getline(data, 5);
        // printf("%s\n", data);

        // // Supposed to return number of letters waiting. Just returns 0 no matter what
        // printf("%d\n", std::cin.rdbuf()->in_avail());

        // // Supposed to return number of letters waiting. This is supposed to fix the 0 issue, but still prints 0 no matter what
        // std::ios::sync_with_stdio(false);
        // printf("%d\n", std::cin.rdbuf()->in_avail());

        // // Waits for the enter key to be pressed
        // std::string data;
        // std::cin >> data;
        // printf("%s\n", data.c_str());

        // CONCLUSION: Why does C++ give me so many headaches

        // Allow other tasks to run
        this_thread::sleep_for(20);
    }
}
