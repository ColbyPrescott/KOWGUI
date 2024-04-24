#include "KOWGUI/color.h"

using namespace KOWGUI;

// Set the color with red, green, and blue values ranging 0 - 255
Color* Color::SetRGB(uint8_t red, uint8_t green, uint8_t blue) {
    mR = red;
    mG = green;
    mB = blue;
    return this;
}

Color* Color::SetTransparent(bool transparent) {
    mTransparent = transparent;
    return this;
}

uint8_t Color::GetR() {
    return mR;
}

uint8_t Color::GetG() {
    return mG;
}

uint8_t Color::GetB() {
    return mB;
}

bool Color::GetTransparent() {
    return mTransparent;
}

vex::color Color::GetVexColor() {
    if(mTransparent) return vex::color::transparent;
    else return vex::color(mR, mG, mB);
}

Color* Color::transparent = (new Color)->SetTransparent(true);

Color* Color::white = (new Color)->SetRGB(255, 255, 255);
Color* Color::red = (new Color)->SetRGB(255, 0, 0);