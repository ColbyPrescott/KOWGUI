#include "KOWGUI/Nodes/text.h"

#include <stdio.h> // DEBUG

using namespace KOWGUI;

Text* Text::SetFontSize(int fontSize) {
    mFontSize = fontSize;
    return this;
}

void Text::Draw(vex::brain::lcd& rScreen) {
    // SetFontSize(20);
    // rScreen.setPenColor(vex::white);
    // rScreen.setFillColor(vex::blue);
    // rScreen.setFont(vex::prop30);

    // // vexDisplayFontNamedSet("Barlow");
    // vexDisplayTextSize(mFontSize, 60);
    // rScreen.printAt(CalculateX() - 50, CalculateY(), true, "The quick brown fox jumps");
    // rScreen.printAt(CalculateX() - 50, CalculateY() + 50, true, "over the lazy dog 012345");

    // // vexDisplayFontNamedSet("Prop");
    // rScreen.setFillColor(vex::purple);
    // rScreen.setFont(vex::mono60);
    // vexDisplayTextSize(mFontSize, 60);
    // rScreen.printAt(CalculateX(), CalculateY(), true, "Bg");
}

void KOWGUI::DrawDebugTextScreen(vex::brain::lcd& rScreen) {
    // My standard of measurement points:
    // Measure with vexDisplayTextSize(1, 1);
    // Pixels only partly lit due to antialiasing DO NOT COUNT
    // tallest / lowest character tests ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
    // Top - Red line directly ON highest blue pixel
    // Ascender - Red line directly ON highest pixel of tallest character, usually lowercase h
    // Middle - Average between baseline and red line directly ON highest pixel of lowercase x
    // Baseline - Red line directly BELOW lowest pixel of a character like h, usually 0
    // Descender - Red line directly BELOW lowest pixel of lowest character, usually lowercase g
    // Bottom - Red line directly BELOW lowest blue pixel
    // Height - Descender - ascender

    // mono
    // Top: -48
    // Ascender: -37
    // Middle: -13
    // Baseline: 0
    // Descender: 12
    // Bottom: 12
    // Height: 49

    // prop
    // Top: -57
    // Ascender: -41
    // Middle: -15
    // Baseline: 0
    // Descender: 13
    // Bottom: 33
    // Height: 54

    // cjk16
    // Top: -17
    // Ascender: -13
    // Middle: -5
    // Baseline: 0
    // Descender: 4
    // Bottom: 10
    // Height: 17

    rScreen.clearScreen();

    // Coordinate to display debugging text
    int textX = 40;
    int textY = 100;

    // Uniform grid lines
    rScreen.setPenWidth(1);
    rScreen.setPenColor(vex::color(100, 100, 100));
    for(int i = 0; i < 240; i += 10) {
        rScreen.drawLine(0, i, 480, i);
    }
    // Lines showing draw position
    rScreen.setPenColor(vex::color(255, 255, 255));
    rScreen.drawLine(0, textY, 480, textY);
    rScreen.drawLine(textX, 0, textX, 240);
    
    
    // Set current font being debugged
    // Update font quickly by holding the bumper sensors that happen to be plugged into by brain
    rScreen.setPenColor(vex::color::white);
    rScreen.setFillColor(vex::color::black);
    rScreen.setCursor(10, 10);
    vex::fontType currentFont;
    int heightOfCurrentFont;
    if(vex::bumper(vex::triport(vex::PORT22).C).pressing()) {       currentFont = vex::fontType::cjk16;    heightOfCurrentFont = 17;   rScreen.print("cjk16");}
    else if(vex::bumper(vex::triport(vex::PORT22).B).pressing()) {  currentFont = vex::fontType::prop60;   heightOfCurrentFont = 54;   rScreen.print("prop60");}
    else {                                                          currentFont = vex::fontType::mono60;   heightOfCurrentFont = 49;   rScreen.print("mono60");}

    // Set a font size that's being tested
    static int currentDebuggingSize = 60;
    if(vex::bumper(vex::triport(vex::PORT22).D).pressing()) currentDebuggingSize--;
    if(vex::bumper(vex::triport(vex::PORT22).H).pressing()) currentDebuggingSize++;
    rScreen.setPenColor(vex::color::white);
    rScreen.setFillColor(vex::color::black);
    rScreen.setCursor(10, 20);
    rScreen.print(currentDebuggingSize);

    // Draw debugging text
    rScreen.setFillColor(vex::color::blue);
    rScreen.setPenColor(vex::color::white);
    rScreen.setFont(currentFont);
    // Default font size
    vexDisplayTextSize(currentDebuggingSize, heightOfCurrentFont);
    // Draw actual text, these four characters seem to demonstrate each height
    rScreen.printAt(textX, textY, "Éghx");


    // Line where screen was pressed
    rScreen.setPenWidth(1);
    rScreen.setPenColor(vex::color(255, 0, 0));
    rScreen.drawLine(0, rScreen.yPosition(), 480, rScreen.yPosition());
    // Text showing y coordinate of line
    rScreen.setFillColor(vex::color::black);
    rScreen.setFont(vex::fontType::mono40);
    rScreen.setCursor(10, 1);
    rScreen.print(rScreen.yPosition() - textY);

    rScreen.render();
}