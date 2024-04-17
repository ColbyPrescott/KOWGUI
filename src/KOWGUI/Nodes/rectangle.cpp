#include "KOWGUI/Nodes/rectangle.h"

using namespace KOWGUI;

Rectangle* Rectangle::SetFillColor(Color* fillColor) {
    mpFillColor = std::make_shared<Color>(*fillColor);
    return this;
}

Rectangle* Rectangle::SetOutlineColor(Color* outlineColor) {
    mpOutlineColor = std::make_shared<Color>(*outlineColor);
    return this;
}

Rectangle* Rectangle::SetOutlineWidth(int outlineWidth) {
    mOutlineWidth = outlineWidth;
    return this;
}



void Rectangle::Draw(vex::brain::lcd& rScreen) {
    rScreen.setFillColor(mpFillColor->GetVexColor());
    rScreen.setPenColor(mpOutlineColor->GetVexColor());
    rScreen.setPenWidth(mOutlineWidth);
    rScreen.drawRectangle(CalculateX(), CalculateY(), GetWidth(), GetHeight());
}