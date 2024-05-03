#ifndef KOWGUI_TEXT_NODE_H
#define KOWGUI_TEXT_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

#include "KOWGUI/General/color.h"

#include <string>
#include <memory>

namespace KOWGUI {

    // TO DO Move this stuff into a separate file. The Text node should be in this file alone

    enum VerticalAlign {
        top,
        ascender,
        middle,
        baseline,
        descender,
        bottom
    };

    enum Overflow {
        visible, // Simply let the overflowing text print outside the node
        hidden, // Overflowing text just gets cut off
        scroll, // Slowly move the text to the left
        wrap, // New line when width gets filled
        wrapScale // Decrement font size until text fits within width and height
    };

    struct font {
        vex::fontType vexFont;
        int height;
        int verticalAlignmentHeights[6];
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
            std::string mText = "";

            // Font properties
            font* mpFont = &Fonts::proportional;
            int mFontSize = 30;
            std::shared_ptr<Color> mpColor = std::make_shared<Color>(*Color::white);

            // Alignment properties
            VerticalAlign mVerticalAlign = VerticalAlign::baseline;
            bool mHorizontalCentering = false;
            bool mVerticalCentering = false;

            // What should happen when text can't fit inside node's area
            Overflow mOverflow = Overflow::wrap;

            struct {
                int offsetX = 0; // Needed to keep track of how far the text is currently scrolled

                int speed = 1; // How fast the text should scroll in pixels per tick
                int spacing = 50; // How many pixels should separate repeated sections of text
            } mScrollProperties;

            struct {
                double lineSpacing = 1.4;
            } mWrapProperties;

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
            Text* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Text* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Text* SetText(std::string text);
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
            Text* SetFont(font& fontName); // TO DO Should this take a pointer instead of a reference to match everything else?
            Text* SetFontSize(int fontSize);
            Text* SetColor(Color* color);
            Text* SetVerticalAlign(VerticalAlign verticalAlign);
            Text* SetOverflow(Overflow overflow);

            Text* SetScrollSpeed(int speed);
            Text* SetScrollSpacing(int spacing);
            Text* SetWrapLineSpacing(double lineSpacing);

            void Draw(vex::brain::lcd& rScreen);
    };

}

#endif