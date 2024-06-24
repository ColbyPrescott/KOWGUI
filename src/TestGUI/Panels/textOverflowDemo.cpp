#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

const int spacing = 20;
const int rectWidth = 100;
const int rectHeight = 50;

const int scrollbarWidth = sidebarScrollbarWidth;
const int scrollbarHeight = 570;

void InitGUITextOverflowDemo() {
    panels.textOverflowDemo->AddChildren({
        (new Draggable)->SetPosition(480 - sidebarWidth - scrollbarWidth, 0)->SetSize(scrollbarWidth, scrollbarHeight)->SetRange(480 - sidebarWidth - scrollbarWidth, -scrollbarHeight + 240, 480 - sidebarWidth, scrollbarHeight)->AddChildren({
            (new Rectangle)->SetFillColor(theme.scrollbar),
            (new Group)->SetShallowID("scrollArea")->SetPosition(-(480 - sidebarWidth - scrollbarWidth), spacing),
        }),
        
    });

    panels.textOverflowDemo->FindShallowID("scrollArea")->AddChildren({
        (new Rectangle)->SetPosition(spacing, (spacing + rectHeight) * 0)->SetSize(rectWidth, rectHeight)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Visible is default VEX behavior.")->SetFontSize(16)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::visible)
        }),
        (new Rectangle)->SetPosition(spacing, (spacing + rectHeight) * 1)->SetSize(rectWidth, rectHeight)->SetFillColor(Color::gray)->AddChildren({
            // (new Text)->SetText("(Hidden will cut overflowing characters.)")->SetFontSize(16)->SetFontAlign(FontAlign::descender)->SetOverflow(Overflow::visible),
            (new Text)->SetText("Hidden will cut overflowing characters.")->SetFontSize(16)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::hidden)
        }),
        (new Rectangle)->SetPosition(spacing, (spacing + rectHeight) * 2)->SetSize(rectWidth, rectHeight)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Scroll at a speed of 1.")->SetFontSize(16)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::scroll)->SetScrollSpeed(1)
        }),
        (new Rectangle)->SetPosition(spacing, (spacing + rectHeight) * 3)->SetSize(rectWidth, rectHeight)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Scroll at a speed of 2.")->SetFontSize(16)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::scroll)->SetScrollSpeed(2)
        }),
        (new Rectangle)->SetPosition(spacing, (spacing + rectHeight) * 4)->SetSize(rectWidth, rectHeight)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Scroll with a repetition spacing of 20 pixels.")->SetFontSize(16)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::scroll)->SetScrollSpacing(20)
        }),
        (new Rectangle)->SetPosition(spacing, (spacing + rectHeight) * 5)->SetSize(rectWidth, rectHeight)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Scroll with a repetition spacing of 200 pixels.")->SetFontSize(16)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::scroll)->SetScrollSpacing(200)
        }),
        (new Rectangle)->SetPosition(spacing, (spacing + rectHeight) * 6)->SetSize(rectWidth * 2, rectHeight)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("Wrap will move overflowing text to the next line.\n\\n will force a new line.")->SetFontSize(16)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::wrap)
        }),
        (new Rectangle)->SetPosition(spacing, (spacing + rectHeight) * 7)->SetSize(rectWidth * 2, rectHeight)->SetFillColor(Color::gray)->AddChildren({
            (new Text)->SetText("WrapScale is just like wrap, except it will decrease font size until vertical overflow stops too.")->SetFontSize(16)->SetFontAlign(FontAlign::ascender)->SetOverflow(Overflow::wrapScale)
        }),
    });
}