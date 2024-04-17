#include "KOWGUI/color.h"

using namespace KOWGUI;

// Set the color with red, green, and blue values ranging 0 - 255
Color* Color::SetRGB(uint8_t red, uint8_t green, uint8_t blue) {
    mR = red;
    mG = green;
    mB = blue;
    return this;
}

vex::color Color::GetVexColor() {
    if(mTransparent) return vex::color::transparent;
    else return vex::color(mR, mG, mB);
}