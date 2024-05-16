#include "KOWGUI/General/color.h"

#include <sstream>

using namespace KOWGUI;

// Set whether or not this color will be drawn
Color* Color::SetTransparent(bool transparent) {
    mTransparent = transparent;
    return this;
}

// Set the color with red, green, and blue values ranging 0 - 255
Color* Color::SetRGB(uint8_t red, uint8_t green, uint8_t blue) {
    mR = red;
    mG = green;
    mB = blue;
    return this;
}

// Set the color with a hexidecimal color code value, "#xxxxxx"
Color* Color::SetHex(std::string hex) {
    // Remove hashtag if there
    if(hex[0] == '#') hex.erase(hex.begin());

    // Function to convert two hexidecimal digits to decimal
    uint8_t (*HexToInt)(std::string) = [](std::string twoHexChars){
        std::stringstream ss;
        int out;
        ss << std::hex << twoHexChars;
        ss >> out;
        return (uint8_t)out;
    };

    // Convert each red, green, and blue part of the hex color code to decimal
    uint8_t r = HexToInt(hex.substr(0, 2));
    uint8_t g = HexToInt(hex.substr(2, 2));
    uint8_t b = HexToInt(hex.substr(4, 2));

    // Set the internal rgb values to the decoded hex values
    SetRGB(r, g, b);

    return this;
}

// Get the internal red value
uint8_t Color::GetR() {
    return mR;
}

// Get the internal green value
uint8_t Color::GetG() {
    return mG;
}

// Get the internal blue value
uint8_t Color::GetB() {
    return mB;
}

// Get the internal transparency state
bool Color::GetTransparent() {
    return mTransparent;
}

// Generate a vex::color object
vex::color Color::GetVexColor() {
    if(mTransparent) return vex::color::transparent;
    else return vex::color(mR, mG, mB);
}

Color* Color::transparent = (new Color)->SetTransparent(true);

Color* Color::white = (new Color)->SetRGB(255, 255, 255);
Color* Color::red = (new Color)->SetRGB(255, 0, 0);