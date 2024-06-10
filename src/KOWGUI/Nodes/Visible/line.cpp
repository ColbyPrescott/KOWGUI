#include "KOWGUI/Nodes/Visible/line.h"

using namespace KOWGUI;

// Set the local X coordinate of the first vertex
Line* Line::SetX1(int x1) {
    int difference = x1 - GetX();
    SetX(x1);
    SetWidth(CalculateWidth() - difference);
    return this;
}

// Set the local Y coordinate of the first vertex
Line* Line::SetY1(int y1) {
    int difference = y1 - GetY();
    SetY(y1);
    SetHeight(CalculateHeight() - difference);
    return this;
}

// Set the local coordinate of the first vertex
Line* Line::SetPosition1(int x1, int y1) {
    SetX1(x1);
    SetY1(y1);
    return this;
}

// Set the local X coordinate of the second vertex
Line* Line::SetX2(int x2) {
    SetWidth(x2 - GetX());
    return this;
}

// Set the local Y coordinate of the second vertex
Line* Line::SetY2(int y2) {
    SetHeight(y2 - GetY());
    return this;
}

// Set the local coordinate of the second vertex
Line* Line::SetPosition2(int x2, int y2) {
    SetX2(x2);
    SetY2(y2);
    return this;
}

// Set the local coordinates of both the first and second vertex
Line* Line::SetPositions(int x1, int y1, int x2, int y2) {
    SetPosition1(x1, y1);
    SetPosition2(x2, y2);
    return this;
}



// Set the color of the line
Line* Line::SetColor(Color* color) {
    mpColor = std::make_shared<Color>(*color);
    return this;
}

// Set the thickness of the line
Line* Line::SetLineWidth(int lineWidth) {
    mLineWidth = lineWidth;
    return this;
}



// Draw the line to the screen
void Line::Draw(vex::brain::lcd& rScreen) {
    rScreen.setPenColor(mpColor->GetVexColor());
    rScreen.setPenWidth(mLineWidth);
    rScreen.drawLine(CalculateX(), CalculateY(), CalculateX() + CalculateWidth(), CalculateY() + CalculateHeight()); // Perhaps set undefined number to something hyper specific?
}