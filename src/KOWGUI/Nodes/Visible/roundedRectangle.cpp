#include "KOWGUI/Nodes/Visible/roundedRectangle.h"

using namespace KOWGUI;

// Set the color that fills in the rounded rectangle
RoundedRectangle* RoundedRectangle::SetFillColor(std::shared_ptr<Color> fillColor) {
    mpFillColor = fillColor;
    return this;
}

// Set the color that borders the rounded rectangle
RoundedRectangle* RoundedRectangle::SetOutlineColor(std::shared_ptr<Color> outlineColor) {
    mpOutlineColor = outlineColor;
    return this;
}

// Set how wide the border is in pixels
RoundedRectangle* RoundedRectangle::SetOutlineWidth(int outlineWidth) {
    mOutlineWidth = outlineWidth;
    return this;
}

// Set the radius of the rounded corners
RoundedRectangle* RoundedRectangle::SetOutlineRadius(int outineRadius) {
    mOutlineRadius = outineRadius;
    return this;
}



// Draw the rounded rectangle to the screen
void RoundedRectangle::Draw(vex::brain::lcd& rScreen) {
    // Limit radius so that a value of mOutlineRadius above half the minimum side length will result in perfectly round sides instead of weird incorrect positioning
    int limitedRadius = std::min(mOutlineRadius, std::min(CalculateWidth(), CalculateHeight()) / 2);
    // Subtract 1 pixel when drawing circles because VEX API does not account for the center pixel. A circle with radius 5 is drawn 11 pixels wide instead of 10. Throws off the rectangle and circle alignments
    int drawRadius = limitedRadius - 1;

    // Draw 4 circles in each corner to create the rounded corners
    // TO DO If set too large, the last circles will draw their outline over the first ones. Fix this with a clipping area?
    rScreen.setFillColor(mpFillColor->GetVexColor());
    rScreen.setPenColor(mpOutlineColor->GetVexColor());
    rScreen.setPenWidth(mpOutlineColor->GetTransparent() ? 0 : mOutlineWidth);
    rScreen.drawCircle(CalculateX() + limitedRadius, CalculateY() + limitedRadius, drawRadius); // Top left
    rScreen.drawCircle(CalculateX() + CalculateWidth() - limitedRadius, CalculateY() + limitedRadius, drawRadius); // Top right
    rScreen.drawCircle(CalculateX() + limitedRadius, CalculateY() + CalculateHeight() - limitedRadius, drawRadius); // Bottom left
    rScreen.drawCircle(CalculateX() + CalculateWidth() - limitedRadius, CalculateY() + CalculateHeight() - limitedRadius, drawRadius); // Bottom right
    // Draw 2 rectangles in a cross through the center. Disable outline for it to be constructed manually afterwards
    rScreen.setPenWidth(0);
    rScreen.drawRectangle(CalculateX() + limitedRadius, CalculateY(), CalculateWidth() - limitedRadius * 2, CalculateHeight()); // Vertical
    rScreen.drawRectangle(CalculateX(), CalculateY() + limitedRadius, CalculateWidth(), CalculateHeight() - limitedRadius * 2); // Horizontal
    // Draw 4 lines on each of the flat outer edges to complete the outline
    // TO DO Lines don't render on a fully rounded edge
    // TO DO Lines sometimes appear offset from circle outline
    rScreen.setPenWidth(mpOutlineColor->GetTransparent() ? 0 : mOutlineWidth);
    rScreen.drawLine(CalculateX() + limitedRadius, CalculateY(), CalculateX() + CalculateWidth() - limitedRadius, CalculateY()); // Top line
    rScreen.drawLine(CalculateX() + limitedRadius, CalculateY() + CalculateHeight(), CalculateX() + CalculateWidth() - limitedRadius, CalculateY() + CalculateHeight()); // Bottom line
    rScreen.drawLine(CalculateX(), CalculateY() + limitedRadius, CalculateX(), CalculateY() + CalculateHeight() - limitedRadius); // Left line
    rScreen.drawLine(CalculateX() + CalculateWidth(), CalculateY() + limitedRadius, CalculateX() + CalculateWidth(), CalculateY() + CalculateHeight() - limitedRadius); // Right line
}