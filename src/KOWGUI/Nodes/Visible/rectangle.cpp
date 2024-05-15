#include "KOWGUI/Nodes/Visible/rectangle.h"

using namespace KOWGUI;

// Set the color that fills in the rectangle
Rectangle* Rectangle::SetFillColor(Color* fillColor) {
    mpFillColor = std::make_shared<Color>(*fillColor);
    return this;
}

// Set the color that borders the rectangle
Rectangle* Rectangle::SetOutlineColor(Color* outlineColor) {
    mpOutlineColor = std::make_shared<Color>(*outlineColor);
    return this;
}

// Set how wide the border is in pixels
Rectangle* Rectangle::SetOutlineWidth(int outlineWidth) {
    mOutlineWidth = outlineWidth;
    return this;
}



// Draw the rectangle to the screen
void Rectangle::Draw(vex::brain::lcd& rScreen) {
    rScreen.setFillColor(mpFillColor->GetVexColor());
    rScreen.setPenColor(mpOutlineColor->GetVexColor());
    rScreen.setPenWidth(mpOutlineColor->GetTransparent() ? 0 : mOutlineWidth); // Ternary because the fill can be vex::color::transparent but not the pen outline...?
    rScreen.drawRectangle(CalculateX(), CalculateY(), CalculateWidth(), CalculateHeight());
}