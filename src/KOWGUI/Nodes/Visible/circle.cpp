#include "KOWGUI/Nodes/Visible/circle.h"

using namespace KOWGUI;

// Set whether or not the position of this node is treated as the circle's center instead of the top left corner like most nodes
Circle* Circle::SetCentered(bool centered) {
    mCentered = centered;
    return this;
}

// Set both the width and height to double the radius
Circle* Circle::SetRadius(int radius) {
    SetWidth(radius * 2);
    SetHeight(radius * 2);
    return this;
}

// Set the color that fills in the circle
Circle* Circle::SetFillColor(Color* fillColor) {
    mpFillColor = std::make_shared<Color>(*fillColor);
    return this;
}

// Set the color that borders the circle
Circle* Circle::SetOutlineColor(Color* outlineColor) {
    mpOutlineColor = std::make_shared<Color>(*outlineColor);
    return this;
}

// Set how wide the border is in pixels
Circle* Circle::SetOutlineWidth(int outlineWidth) {
    mOutlineWidth = outlineWidth;
    return this;
}



// Draw the circle to the screen
void Circle::Draw(vex::brain::lcd& rScreen) {
    rScreen.setFillColor(mpFillColor->GetVexColor());
    rScreen.setPenColor(mpOutlineColor->GetVexColor());
    rScreen.setPenWidth(mpOutlineColor->GetTransparent() ? 0 : mOutlineWidth);
    if(mCentered) rScreen.drawCircle(CalculateX(), CalculateY(), CalculateWidth() / 2);
    else rScreen.drawCircle(CalculateX() + CalculateWidth() / 2, CalculateY() + CalculateWidth() / 2, CalculateWidth() / 2);
}