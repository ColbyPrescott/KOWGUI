#ifndef KOWGUI_TEXT_NODE_H
#define KOWGUI_TEXT_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

#include "KOWGUI/General/color.h"

#include <string>
#include <memory>
#include <stdio.h>

namespace KOWGUI {

    class Text : public VisibleBaseNode {
        public:
            enum class HorizontalAlign {
                left, // Align the left edge of the text to the left edge of the node
                center, // Align the center of the text to the center of the node
                right // Align the right edge of the text to the right edge of the node
            };

            enum class VerticalAlign {
                top, // Align the text's Y coordinate of 0 to the top of the node
                middle, // Align the text's Y coordinate of 0 to the middle of the node
                bottom // Align the text's Y coordinate of 0 to the bottom of the node
            };

            enum class FontAlign {
                top, // Align the text's Y coordinate to the very top of the font
                ascender, // Align the text's Y coordinate to the top of the letter 'h'. Useful when placing text at the top of the node
                middle, // Align the text's Y coordinate to the middle of the letter 'x'. Useful when placing text in the middle of the node
                baseline, // Align the text's Y coordinate to the bottom of the letter 'h'. Useful when placing text on a line
                descender, // Align the text's Y coordinate to the bottom of the letter 'g'. Useful when placing text at the bottom of the node
                bottom // Align the text's Y coordinate to the very bottom of the font
            };

            enum class Overflow {
                visible, // Simply let the overflowing text print outside the node
                hidden, // Overflowing text just gets cut off
                scroll, // Slowly move the text to the left
                wrap, // New line when width gets filled
                wrapScale // Decrement font size until text fits within width and height
            };

            struct Font {
                vex::fontType vexFont;
                int height;
                int fontAlignmentHeights[6];
            };
            
            static const Font fontMonospace;
            static const Font fontProportional;
            static const Font fontPixelated;

        private:
            // Text that will be displayed
            std::string mText = "";

            // Font to use
            const Font* mpFont = &fontProportional;
            // How big the text is, measured as the height in pixels from ascender to descender
            int mFontSize = 30;
            // Color of the text
            std::shared_ptr<Color> mpColor = Color::white;

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
            Text* SetFont(const Font& fontName);
            Text* SetFontSize(int fontSize);
            Text* SetColor(std::shared_ptr<Color> color);
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