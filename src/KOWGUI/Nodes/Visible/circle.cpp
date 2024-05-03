#include "KOWGUI/Nodes/Visible/circle.h"

using namespace KOWGUI;

Circle* Circle::SetCentered(bool centered) {
    mCentered = centered;
    return this;
}

Circle* Circle::SetRadius(int radius) {
    SetWidth(radius * 2);
    SetHeight(radius * 2);
    return this;
}

Circle* Circle::SetFillColor(Color* fillColor) {
    mpFillColor = std::make_shared<Color>(*fillColor);
    return this;
}

Circle* Circle::SetOutlineColor(Color* outlineColor) {
    mpOutlineColor = std::make_shared<Color>(*outlineColor);
    return this;
}

Circle* Circle::SetOutlineWidth(int outlineWidth) {
    mOutlineWidth = outlineWidth;
    return this;
}



void Circle::Draw(vex::brain::lcd& rScreen) {
    rScreen.setFillColor(mpFillColor->GetVexColor());
    rScreen.setPenColor(mpOutlineColor->GetVexColor());
    rScreen.setPenWidth(mpOutlineColor->GetTransparent() ? 0 : mOutlineWidth);
    if(mCentered) rScreen.drawCircle(CalculateX(), CalculateY(), CalculateWidth() / 2);
    else rScreen.drawCircle(CalculateX() + CalculateWidth() / 2, CalculateY() + CalculateHeight() / 2, CalculateWidth() / 2);
}