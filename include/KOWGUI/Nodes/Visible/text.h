#ifndef KOWGUI_TEXT_NODE_H
#define KOWGUI_TEXT_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

#include "KOWGUI/General/color.h"

#include <string>
#include <memory>
#include <stdio.h>

namespace KOWGUI {

    // TO DO Move this stuff into a separate file. The Text node should be in this file alone

    enum class HorizontalAlign {
        left,
        center,
        right
    };

    enum class VerticalAlign {
        top,
        middle,
        bottom
    };

    enum class FontAlign {
        top,
        ascender,
        middle,
        baseline,
        descender,
        bottom
    };

    enum class Overflow {
        visible, // Simply let the overflowing text print outside the node
        hidden, // Overflowing text just gets cut off
        scroll, // Slowly move the text to the left
        wrap, // New line when width gets filled
        wrapScale // Decrement font size until text fits within width and height
    };

    struct font {
        vex::fontType vexFont;
        int height;
        int fontAlignmentHeights[6];
    };

    namespace Fonts {
        // TO DO Label these fonts with their actual names? Monospace and proportional 
        // are font TYPES, and cjk16 is... uh... how is such a small font supposed to display
        // the detail required for Chinese, Japanese, or Korean languages? What am I missing here?

        static font monospace = {
            vex::fontType::mono60, // vexFont
            49, // height
            {
                -48, // top
                -37, // ascender
                -13, // middle
                0, // baseline
                12, // descender
                12, // bottom
            }
        };

        static font proportional = {
            vex::fontType::prop60, // vexFont
            54, // height
            {
                -57, // top
                -41, // ascender
                -15, // middle
                0, // baseline
                13, // descender
                33, // bottom
            }
        };

        static font optimizedSmall = {
            vex::fontType::cjk16, // vexFont
            17, // height
            {
                -17, // top
                -13, // ascender
                -5, // middle
                0, // baseline
                4, // descender
                10, // bottom
            }
        };

    }

    class Text : public VisibleBaseNode {
        private:
            // Text that will be displayed
            std::string mText = "";

            // Font to use
            font* mpFont = &Fonts::proportional;
            // How big the text is, measured as the height in pixels from ascender to descender
            int mFontSize = 30;
            // Color of the text
            std::shared_ptr<Color> mpColor = std::make_shared<Color>(*Color::white);

            // Which part of the node's area the text should horizontally snap to
            HorizontalAlign mHorizontalAlign = HorizontalAlign::left;
            // Which part of the node's area the text should vertically snap to
            VerticalAlign mVerticalAlign = VerticalAlign::top;
            // What part of the text to drawn at Y coordinate of 0
            FontAlign mFontAlign = FontAlign::ascender;

            // What should happen when text can't fit inside node's area
            Overflow mOverflow = Overflow::wrap;

            struct {
                // How far the text is currently scrolled
                int offsetX = 0; 

                // How fast the text should scroll in pixels per tick
                int speed = 1; 
                // How many pixels should separate repeated sections of text
                int spacing = 50; 
            } mScrollProperties;

            struct {
                // How much the font height should be multiplied by to vertically space lines
                double lineSpacing = 1.4;
            } mWrapProperties;

            void PrintAligned(vex::brain::lcd& rScreen, int x, int y, std::vector<std::string> lines);

            void DrawOverflow(vex::brain::lcd& rScreen, int startX, int startY);
            void DrawHide(vex::brain::lcd& rScreen, int startX, int startY);
            void DrawScroll(vex::brain::lcd& rScreen, int startX, int startY);
            int DrawWrap(vex::brain::lcd& rScreen, int startX, int startY, bool returnHeight = false);
            void DrawWrapScale(vex::brain::lcd& rScreen, int startX, int startY);

        public:
            Text* SetX(int x) {BaseNode::SetX(x); return this;}
            Text* SetY(int y) {BaseNode::SetY(y); return this;}
            Text* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Text* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Text* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Text* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Text* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Text* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Text* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Text* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Text* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Text* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Text* SetText(std::string text);
            Text* SetFont(font& fontName); // TO DO Should this take a pointer instead of a reference to match everything else?
            Text* SetFontSize(int fontSize);
            Text* SetColor(Color* color);
            Text* SetHorizontalAlign(HorizontalAlign horizontalAlign);
            Text* SetVerticalAlign(VerticalAlign verticalAlign);
            Text* SetFontAlign(FontAlign fontAlign);
            Text* SetAlignments(HorizontalAlign horizontalAlign, VerticalAlign verticalAlign);
            Text* SetAlignments(HorizontalAlign horizontalAlign, VerticalAlign verticalAlign, FontAlign fontAlign);
            Text* SetOverflow(Overflow overflow);

            Text* SetScrollSpeed(int speed);
            Text* SetScrollSpacing(int spacing);
            Text* SetWrapLineSpacing(double lineSpacing);

            std::string GetText();

            void Draw(vex::brain::lcd& rScreen);

            // Set the text to display in a similar way to std::printf(format, ...)
            template <typename... Args>
            Text* SetText(std::string format, Args... args) {
                // Get exact length of expected text after formatting, including the terminator character 
                int length = snprintf(nullptr, 0, format.c_str(), args...) + 1;
                // Create the buffer that will store the formatted text
                char buffer[length];
                // Put the formatted text into the buffer
                snprintf(buffer, length, format.c_str(), args...);
                // Set internal text to the buffer. The terminator character is not needed in std::string
                mText = std::string(buffer, length - 1);
                return this;
            }
    };

}

#endif