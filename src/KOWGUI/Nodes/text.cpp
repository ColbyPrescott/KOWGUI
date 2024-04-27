#include "KOWGUI/Nodes/text.h"

#include <stdio.h> // DEBUG
#include <vector>

using namespace KOWGUI;

Text* Text::SetText(std::string text) {
    mText = text;
    return this;
}

Text* Text::SetFont(font& fontName) {
    mpFont = &fontName;
    return this;
}

Text* Text::SetFontSize(int fontSize) {
    mFontSize = fontSize;
    return this;
}

Text* Text::SetColor(Color* color) {
    mpColor = std::make_shared<Color>(*color);
    return this;
}

Text* Text::SetVerticalAlign(VerticalAlign verticalAlign) {
    mVerticalAlign = verticalAlign;
    return this;
}

Text* Text::SetOverflow(Overflow overflow) {
    mOverflow = overflow;
    return this;
}



Text* Text::SetScrollSpeed(int speed) {
    mScrollProperties.speed = speed;
    return this;
}

Text* Text::SetScrollSpacing(int spacing) {
    mScrollProperties.spacing = spacing;
    return this;
}

// Set multiplier for how far lines are spaced in overflow mode of wrap
Text* Text::SetWrapLineSpacing(double lineSpacing) {
    mWrapProperties.lineSpacing = lineSpacing;
    return this;
}



// Simply print all text at the position without worrying about it extending outside the node's area
void Text::DrawOverflow(vex::brain::lcd& rScreen, int startX, int startY) {
    rScreen.printAt(startX, startY, false, mText.c_str());
}

// Print all the text that will fit within the node's width, cutting off what goes outside
void Text::DrawHide(vex::brain::lcd& rScreen, int startX, int startY) {
    std::string remainingText = mText;
    std::string currentLine = "";

    // TO DO This could probably be optimized with something akin to quick sort, but, it's low priority
    // Move characters from remainingText to currentLine until adding the next one will no longer fit within mWidth
    while(
        remainingText.size() > 0 && // Ensure there's remaining text left
        rScreen.getStringWidth((currentLine + remainingText[0]).c_str()) < CalculateWidth() // Ensure adding next character will fit
    ) {
        // Move first character from remainingText to currentLine
        currentLine.push_back(remainingText[0]);
        remainingText.erase(remainingText.begin());
    }

    // Print currentLine, the text that fit inside mWidth
    rScreen.printAt(startX, startY, false, currentLine.c_str());
}

// Clip text within node's width and slowly move it to the left
void Text::DrawScroll(vex::brain::lcd& rScreen, int startX, int startY) {
    // Clip the left and right sides of the text as it moves
    rScreen.setClipRegion(CalculateX(), 0, CalculateWidth(), 240);

    // Increment the amount that the text has moved
    mScrollProperties.offsetX += mScrollProperties.speed;
    // Reset offsetX if the text has moved more than one repetition
    int repetitionWidth = rScreen.getStringWidth(mText.c_str()) + mScrollProperties.spacing;
    if(mScrollProperties.offsetX > repetitionWidth) mScrollProperties.offsetX -= repetitionWidth;

    // Repeat printing text so that the reset of offsetX is seamless
    for(int repetitionX = 0; repetitionX <= CalculateWidth() + repetitionWidth; repetitionX += repetitionWidth) {
        rScreen.printAt(startX - mScrollProperties.offsetX + repetitionX, startY, false, mText.c_str());
    }

    // Reset clipping so the next nodes can be drawn. TO DO Replace instances of this function with Clip::Push and Pop methods
    rScreen.setClipRegion(0, 0, 480, 240);
}

// Split text into new lines as it runs outside the node's width
void Text::DrawWrap(vex::brain::lcd& rScreen, int startX, int startY) {
    std::string remainingText = mText;
    std::vector<std::string> storedLines;

    // Break remainingText into storedLines, looping through remainingText word by word or special character by special character
    std::string currentLine = "";
    while(remainingText.size() > 0) { // Ensure there's remaining text left
        // Handle special case characters that shouldn't go through word processing
        switch(remainingText[0]) {
            // Space is the delimiter between words
            case ' ':
                // Simply add it to currentLine outside of the word processing
                currentLine.push_back(' ');
                // Remove space for next iteration of while loop
                remainingText.erase(remainingText.begin());
                continue;
            // \n is the new line character that forces a line break
            case '\n':
                // Move currentLine into storedLines
                storedLines.push_back(currentLine);
                currentLine.clear();
                // Remove \n for next iteration of while loop
                remainingText.erase(remainingText.begin());
                continue;
        }

        // Move characters from remainingText into currentWord until a whole word is aggregated
        // This goofy while loop beats string find because that would complicate the logic more
        std::string currentWord = "";
        while(
            remainingText.size() > 0 && // Ensure there's text remaining
            remainingText[0] != ' ' && // Stop adding to word if a space is hit
            remainingText[0] != '\n' // Stop adding to word if a new line character is hit
        ) {
            // Move first character from remainingText to end of currentWord
            currentWord.push_back(remainingText[0]);
            remainingText.erase(remainingText.begin());
        }

        // Add word into current or new line
        // Does the word fit in currentLine? Add it
        if(rScreen.getStringWidth((currentLine + currentWord).c_str()) < CalculateWidth()) currentLine.append(currentWord);
        // No? Does the word fit on the next line itself? Add it to the next line
        else if(rScreen.getStringWidth(currentWord.c_str()) < CalculateWidth()) {
            storedLines.push_back(currentLine);
            currentLine.clear();
            currentLine.append(currentWord);
        // Still no? The word just on its own must be too wide for the node. Split it with a hyphen and add the remaining portion back into remainingText
        } else {
            // Start with putting whole word into currentLine
            currentLine.append(currentWord);

            // Move characters from end of currentLine back into beginning of remainingText until it with a hyphen stops overflowing node
            int movedCharacters = 0;
            while(rScreen.getStringWidth((currentLine + "-").c_str()) >= CalculateWidth()) {
                remainingText.insert(remainingText.begin(), currentLine.back());
                currentLine.erase(currentLine.end() - 1);
                movedCharacters++;
            }

            // If any of the currentWord remains in currentLine, add the hyphen in to signify that the word was broken
            if(movedCharacters != currentWord.size()) currentLine.push_back('-');

            // currentLine must now be filled from the dynamically cut word so start the next line
            storedLines.push_back(currentLine);
            currentLine.clear();
        }
    }

    // If currentLine ended in the middle of construction, finish up the process of storing it
    if(currentLine.size() > 0) storedLines.push_back(currentLine);

    // This code is separated from the main while loop to make implementing vertical centering easier later
    // Print each stored line
    for(int i = 0; i < storedLines.size(); i++) {
        rScreen.printAt(startX, startY + i * mFontSize * mWrapProperties.lineSpacing, false, storedLines[i].c_str());
    }
}

void Text::Draw(vex::brain::lcd& rScreen) {
    rScreen.setFont(mpFont->vexFont);
    vexDisplayTextSize(mFontSize, mpFont->height);
    rScreen.setPenColor(mpColor->GetVexColor());

    int verticalAlignmentOffset = mpFont->verticalAlignmentHeights[mVerticalAlign] * mFontSize / (float)mpFont->height;
    int startX = CalculateX();
    int startY = CalculateY() - verticalAlignmentOffset;

    switch(mOverflow) {
        case Overflow::visible: DrawOverflow(rScreen, startX, startY); break;
        case Overflow::hidden: DrawHide(rScreen, startX, startY); break;
        case Overflow::scroll: DrawScroll(rScreen, startX, startY); break;
        case Overflow::wrap: DrawWrap(rScreen, startX, startY); break;

        default: DrawOverflow(rScreen, startX, startY); break;
    }
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
    if(vex::bumper(vex::triport(vex::PORT22).B).pressing()) {       currentFont = vex::fontType::cjk16;    heightOfCurrentFont = 17;   rScreen.print("cjk16");}
    else if(vex::bumper(vex::triport(vex::PORT22).A).pressing()) {  currentFont = vex::fontType::prop60;   heightOfCurrentFont = 54;   rScreen.print("prop60");}
    else {                                                          currentFont = vex::fontType::mono60;   heightOfCurrentFont = 49;   rScreen.print("mono60");}

    // Set a font size that's being tested
    static int currentDebuggingSize = 60;
    if(vex::bumper(vex::triport(vex::PORT22).C).pressing()) currentDebuggingSize--;
    if(vex::bumper(vex::triport(vex::PORT22).D).pressing()) currentDebuggingSize++;
    rScreen.setPenColor(vex::color::white);
    rScreen.setFillColor(vex::color::black);
    rScreen.setCursor(10, 20);
    if(vex::bumper(vex::triport(vex::PORT22).H).pressing()) rScreen.print(currentDebuggingSize);

    // Draw debugging text
    rScreen.setFillColor(vex::color::blue);
    rScreen.setPenColor(vex::color::white);
    rScreen.setFont(currentFont);
    // Default font size
    if(vex::bumper(vex::triport(vex::PORT22).H).pressing()) vexDisplayTextSize(currentDebuggingSize, heightOfCurrentFont);
    else vexDisplayTextSize(1, 1);
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