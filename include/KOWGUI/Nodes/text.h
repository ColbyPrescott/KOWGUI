#ifndef KOWGUI_TEXT_NODE_H
#define KOWGUI_TEXT_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"
#include "KOWGUI/color.h"

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
        scale // Decrement font size until text fits within width and height
    };

    struct ScrollProperties {
        int offsetX = 0; // Needed to keep track of how far the text is currently scrolled

        int speed = 1; // How fast the text should scroll in pixels per tick
        int spacing = 50; // How many pixels should separate repeated sections of text
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

            Overflow mOverflow = Overflow::wrap;

            ScrollProperties mScrollProperties;

            void DrawOverflow(vex::brain::lcd& rScreen, int startX, int startY);
            void DrawHide(vex::brain::lcd& rScreen, int startX, int startY);
            void DrawScroll(vex::brain::lcd& rScreen, int startX, int startY);
            void DrawWrap(vex::brain::lcd& rScreen, int startX, int startY);

        public:
            Text() {mType = NodeType::text;}

            Text* SetX(int x) {BaseNode::SetX(x); return this;}
            Text* SetY(int y) {BaseNode::SetY(y); return this;}
            Text* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Text* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Text* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Text* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Text* SetId(std::string id) {BaseNode::SetId(id); return this;}
            Text* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Text* AddChildren(std::vector<void*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Text* SetText(std::string text); // TO DO Add second version of this function with the SetText(const char* format, ...) thing
            Text* SetFont(font& fontName); // TO DO Should this take a pointer instead of a reference to match everything else?
            Text* SetFontSize(int fontSize);
            Text* SetColor(Color* color);
            Text* SetVerticalAlign(VerticalAlign verticalAlign);
            Text* SetOverflow(Overflow overflow);

            Text* SetScrollSpeed(int speed);
            Text* SetScrollSpacing(int spacing);

            void Draw(vex::brain::lcd& rScreen);
    };

    void DrawDebugTextScreen(vex::brain::lcd& rScreen);

}

#endif