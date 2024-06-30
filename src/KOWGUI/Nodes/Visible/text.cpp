#include "KOWGUI/Nodes/Visible/text.h"

#include "KOWGUI/General/color.h"

#include <vector>

using namespace KOWGUI;

// Set the text to display
Text* Text::SetText(std::string text) {
    mText = text;
    return this;
}

// Set the font that should be used. Pick from the KOWGUI::Fonts namespace
Text* Text::SetFont(font& fontName) {
    mpFont = &fontName;
    return this;
}

// Set the size of the font, measured as height from ascender to descender
Text* Text::SetFontSize(int fontSize) {
    mFontSize = fontSize;
    return this;
}

// Set the color of the text
Text* Text::SetColor(Color* color) {
    mpColor = std::make_shared<Color>(*color);
    return this;
}

// Set which part of the node's area the text should horizontally snap to
Text* Text::SetHorizontalAlign(HorizontalAlign horizontalAlign) {
    mHorizontalAlign = horizontalAlign;
    return this;
}

// Set which part of the node's area the text should vertically snap to
Text* Text::SetVerticalAlign(VerticalAlign verticalAlign) {
    mVerticalAlign = verticalAlign;

    // Setting vertical align infers that font align should also change. Placing text on the bottom of an area usually means that bottom touches bottom, thus it shall be default behavior
    switch(verticalAlign) {
        case VerticalAlign::top: SetFontAlign(FontAlign::ascender); break;
        case VerticalAlign::middle: SetFontAlign(FontAlign::middle); break;
        case VerticalAlign::bottom: SetFontAlign(FontAlign::descender); break;
    }

    return this;
}

// Set what part of the text to drawn at Y coordinate of 0
Text* Text::SetFontAlign(FontAlign fontAlign) {
    mFontAlign = fontAlign;
    return this;
}

// Set horizontal and vertical alignments in one function
Text* Text::SetAlignments(HorizontalAlign horizontalAlign, VerticalAlign verticalAlign) {
    SetHorizontalAlign(horizontalAlign);
    SetVerticalAlign(verticalAlign);
    return this;
}

// Set horizontal, vertical, and font alignment in one function
Text* Text::SetAlignments(HorizontalAlign horizontalAlign, VerticalAlign verticalAlign, FontAlign fontAlign) {
    SetHorizontalAlign(horizontalAlign);
    SetVerticalAlign(verticalAlign);
    SetFontAlign(fontAlign);
    return this;
}

// Set what should happen when text can't fit inside node's area, pick from the KOWGUI::Overflow enum
Text* Text::SetOverflow(Overflow overflow) {
    mOverflow = overflow;
    return this;
}



// Set how fast the text should scroll in pixels per tick
Text* Text::SetScrollSpeed(int speed) {
    mScrollProperties.speed = speed;
    return this;
}

// Set how many pixels should separate repeated sections of text
Text* Text::SetScrollSpacing(int spacing) {
    mScrollProperties.spacing = spacing;
    return this;
}

// Set multiplier for how far lines are spaced in overflow mode of wrap
Text* Text::SetWrapLineSpacing(double lineSpacing) {
    mWrapProperties.lineSpacing = lineSpacing;
    return this;
}



// Get the internal text being displayed
std::string Text::GetText() {
    return mText;
}



// Print a line to the screen, offsetting its position by font, horizonal, and vertical alignment
void Text::PrintAligned(vex::brain::lcd& rScreen, int x, int y, std::vector<std::string> lines) {
    // How much to move the Y coordinate based on fontAlign, calculated as the font's selected Y alignment line value multiplied by the default to custom font size scaling factor
    int fontAlignOffset = -mpFont->fontAlignmentHeights[(int)mFontAlign] * (mFontSize / (float)mpFont->height);

    // How much to move the Y coordinate based on verticalAlign
    int verticalAlignOffset;
    switch(mVerticalAlign) {
        case VerticalAlign::top: // Don't offset at all. Top side origin is already correct
            verticalAlignOffset = 0;
            break;
        case VerticalAlign::middle: // Offset text Y 0 to the middle of the node, then upwards by half of the total height of extra lines. Calculated as total height + total extra line height, all divided by 2
            verticalAlignOffset = (CalculateHeight() - ((mFontSize * mWrapProperties.lineSpacing) * (lines.size() - 1))) / 2.0;
            break;
        case VerticalAlign::bottom: // Offset text Y 0 to the bottom of the node, then upwards by the total height of extra lines
            verticalAlignOffset = CalculateHeight() - ((mFontSize * mWrapProperties.lineSpacing) * (lines.size() - 1));
            break;
    }

    // Loop through each line of text, calculate line-specific alignments, and print them to the screen
    for(int i = 0; i < lines.size(); i++) {

        // How much to move the X coordinate based on horizontalAlign
        int horizontalAlignOffset;
        switch(mHorizontalAlign) {
            case HorizontalAlign::left: // Don't offset at all. Left side origin is already correct
                horizontalAlignOffset = 0;
                break;
            case HorizontalAlign::center: // Offset by half of the blank space, calculated as node width minus line width, all divided by 2
                horizontalAlignOffset = (CalculateWidth() - rScreen.getStringWidth(lines[i].c_str())) / 2.0;
                break;
            case HorizontalAlign::right: // Offset by all of the blank space, calculated as node width minus line width
                horizontalAlignOffset = CalculateWidth() - rScreen.getStringWidth(lines[i].c_str());
                break;
        }

        // How much to move the Y coordinate based on the current line being printed, calculated as the full height of a line multiplied by the current line index
        int lineOffset = (mFontSize * mWrapProperties.lineSpacing) * i;

        // Print the line to the screen with all the offsets applied
        // Using %s instead of directly printing the line ensures that an escape character like % will be read as a percent sign instead of the escape character
        rScreen.printAt(x + horizontalAlignOffset, y + fontAlignOffset + verticalAlignOffset + lineOffset, false, "%s", lines[i].c_str());
    }
}



// Simply print all text at the position without worrying about it extending outside the node's area
void Text::DrawOverflow(vex::brain::lcd& rScreen, int startX, int startY) {
    PrintAligned(rScreen, startX, startY, {mText});
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
    PrintAligned(rScreen, startX, startY, {currentLine});
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
        PrintAligned(rScreen, startX - mScrollProperties.offsetX + repetitionX, startY, {mText});
    }

    // Reset clipping so the next nodes can be drawn. TO DO Replace instances of this function with Clip::Push and Pop methods
    rScreen.setClipRegion(0, 0, 480, 240);
}

// Split text into new lines as it runs outside the node's width
int Text::DrawWrap(vex::brain::lcd& rScreen, int startX, int startY, bool returnHeight) {
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
            int movedCharacters = 0; // Keep track of how much of the word was moved
            while(rScreen.getStringWidth((currentLine + "-").c_str()) >= CalculateWidth()) {
                remainingText.insert(remainingText.begin(), currentLine.back()); // Put last character of currentLine into front of remainingText
                currentLine.erase(currentLine.end() - 1); // Remove last character of currentLine
                movedCharacters++;
                // If not even one character can fit in the node's width, exit and skip drawing anything
                if(currentLine.length() == 0) return -1;
            }

            // If any of the currentWord remains in currentLine, add the hyphen in to signify that the word was broken
            if(movedCharacters < currentWord.size()) currentLine.push_back('-');

            // currentLine must now be filled from the dynamically cut word so start the next line
            storedLines.push_back(currentLine);
            currentLine.clear();
        }
    }

    // If currentLine ended in the middle of construction, finish up the process of storing it
    if(currentLine.size() > 0) storedLines.push_back(currentLine);

    // If this function is just being called by DrawWrapScale to get the number of lines calculated, just return 
    // that number and don't bother drawing anything on screen
    if(returnHeight) return mFontSize * storedLines.size() * mWrapProperties.lineSpacing; // TO DO Does this put an extra line spacing on the end?

    // Print each stored line
    PrintAligned(rScreen, startX, startY, storedLines);

    return 0;
}

// Split text into multiple lines like wrap overflow, but automatically decrease the font size until it stops overflowing vertically too
void Text::DrawWrapScale(vex::brain::lcd& rScreen, int startX, int startY) {
    // TO DO Increase / decrease mFontSize in proportion to height difference to reduce wrapScale lag spikes

    // Calculate the total height of all lines for comparison with node height
    int totalHeight = DrawWrap(rScreen, startX, startY, true);

    // If DrawWrap failed to draw the text, fail here too
    if(totalHeight == -1) return;

    // Gradually reduce mFontSize until height of all text lines fits within node's height
    while(totalHeight > CalculateHeight() && mFontSize > 5) {
        mFontSize--;
        vexDisplayTextSize(mFontSize, mpFont->height);

        totalHeight = DrawWrap(rScreen, startX, startY, true);
    }
    // Draw wrapping text with the new font size
    DrawWrap(rScreen, CalculateX(), CalculateY());

    // Slightly raise mFontSize so that it can increase if need be, but the high performace cost while loop 
    // will otherwise not eat too much time in the next draw call
    mFontSize++;
}

// Draw the text to the screen
void Text::Draw(vex::brain::lcd& rScreen) {
    // Set up screen's properties for drawing text
    // Set the font to prop, mono, or cjk16
    rScreen.setFont(mpFont->vexFont);
    // Use this hidden function to set a custom font size
    vexDisplayTextSize(mFontSize, mpFont->height);
    // Set the text's color
    rScreen.setPenColor(mpColor->GetVexColor());

    // Different overflow options will handle the text completely differently, thus they are broken into separate functions
    switch(mOverflow) {
        case Overflow::visible: DrawOverflow(rScreen, CalculateX(), CalculateY()); break;
        case Overflow::hidden: DrawHide(rScreen, CalculateX(), CalculateY()); break;
        case Overflow::scroll: DrawScroll(rScreen, CalculateX(), CalculateY()); break;
        case Overflow::wrap: DrawWrap(rScreen, CalculateX(), CalculateY()); break;
        case Overflow::wrapScale: DrawWrapScale(rScreen, CalculateX(), CalculateY()); break;
    }
}