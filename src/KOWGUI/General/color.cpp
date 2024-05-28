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

Color* Color::aliceBlue = (new Color)->SetHex("#F0F8FF");
Color* Color::antiqueWhite = (new Color)->SetHex("#FAEBD7");
Color* Color::aqua = (new Color)->SetHex("#00FFFF");
Color* Color::aquamarine = (new Color)->SetHex("#7FFFD4");
Color* Color::azure = (new Color)->SetHex("#F0FFFF");
Color* Color::beige = (new Color)->SetHex("#F5F5DC");
Color* Color::bisque = (new Color)->SetHex("#FFE4C4");
Color* Color::black = (new Color)->SetHex("#000000");
Color* Color::blanchedAlmond = (new Color)->SetHex("#FFEBCD");
Color* Color::blue = (new Color)->SetHex("#0000FF");
Color* Color::blueViolet = (new Color)->SetHex("#8A2BE2");
Color* Color::brown = (new Color)->SetHex("#A52A2A");
Color* Color::burlyWood = (new Color)->SetHex("#DEB887");
Color* Color::cadetBlue = (new Color)->SetHex("#5F9EA0");
Color* Color::chartreuse = (new Color)->SetHex("#7FFF00");
Color* Color::chocolate = (new Color)->SetHex("#D2691E");
Color* Color::coral = (new Color)->SetHex("#FF7F50");
Color* Color::cornflowerBlue = (new Color)->SetHex("#6495ED");
Color* Color::cornsilk = (new Color)->SetHex("#FFF8DC");
Color* Color::crimson = (new Color)->SetHex("#DC143C");
Color* Color::cyan = (new Color)->SetHex("#00FFFF");
Color* Color::darkBlue = (new Color)->SetHex("#00008B");
Color* Color::darkCyan = (new Color)->SetHex("#008B8B");
Color* Color::darkGoldenRod = (new Color)->SetHex("#B8860B");
Color* Color::darkGray = (new Color)->SetHex("#A9A9A9");
Color* Color::darkGrey = (new Color)->SetHex("#A9A9A9");
Color* Color::darkGreen = (new Color)->SetHex("#006400");
Color* Color::darkKhaki = (new Color)->SetHex("#BDB76B");
Color* Color::darkMagenta = (new Color)->SetHex("#8B008B");
Color* Color::darkOliveGreen = (new Color)->SetHex("#556B2F");
Color* Color::darkOrange = (new Color)->SetHex("#FF8C00");
Color* Color::darkOrchid = (new Color)->SetHex("#9932CC");
Color* Color::darkRed = (new Color)->SetHex("#8B0000");
Color* Color::darkSalmon = (new Color)->SetHex("#E9967A");
Color* Color::darkSeaGreen = (new Color)->SetHex("#8FBC8F");
Color* Color::darkSlateBlue = (new Color)->SetHex("#483D8B");
Color* Color::darkSlateGray = (new Color)->SetHex("#2F4F4F");
Color* Color::darkSlateGrey = (new Color)->SetHex("#2F4F4F");
Color* Color::darkTurquoise = (new Color)->SetHex("#00CED1");
Color* Color::darkViolet = (new Color)->SetHex("#9400D3");
Color* Color::deepPink = (new Color)->SetHex("#FF1493");
Color* Color::deepSkyBlue = (new Color)->SetHex("#00BFFF");
Color* Color::dimGray = (new Color)->SetHex("#696969");
Color* Color::dimGrey = (new Color)->SetHex("#696969");
Color* Color::dodgerBlue = (new Color)->SetHex("#1E90FF");
Color* Color::fireBrick = (new Color)->SetHex("#B22222");
Color* Color::floralWhite = (new Color)->SetHex("#FFFAF0");
Color* Color::forestGreen = (new Color)->SetHex("#228B22");
Color* Color::fuchsia = (new Color)->SetHex("#FF00FF");
Color* Color::gainsboro = (new Color)->SetHex("#DCDCDC");
Color* Color::ghostWhite = (new Color)->SetHex("#F8F8FF");
Color* Color::gold = (new Color)->SetHex("#FFD700");
Color* Color::goldenRod = (new Color)->SetHex("#DAA520");
Color* Color::gray = (new Color)->SetHex("#808080");
Color* Color::grey = (new Color)->SetHex("#808080");
Color* Color::green = (new Color)->SetHex("#008000");
Color* Color::greenYellow = (new Color)->SetHex("#ADFF2F");
Color* Color::honeyDew = (new Color)->SetHex("#F0FFF0");
Color* Color::hotPink = (new Color)->SetHex("#FF69B4");
Color* Color::indianRed = (new Color)->SetHex("#CD5C5C");
Color* Color::indigo = (new Color)->SetHex("#4B0082");
Color* Color::ivory = (new Color)->SetHex("#FFFFF0");
Color* Color::khaki = (new Color)->SetHex("#F0E68C");
Color* Color::lavender = (new Color)->SetHex("#E6E6FA");
Color* Color::lavenderBlush = (new Color)->SetHex("#FFF0F5");
Color* Color::lawnGreen = (new Color)->SetHex("#7CFC00");
Color* Color::lemonChiffon = (new Color)->SetHex("#FFFACD");
Color* Color::lightBlue = (new Color)->SetHex("#ADD8E6");
Color* Color::lightCoral = (new Color)->SetHex("#F08080");
Color* Color::lightCyan = (new Color)->SetHex("#E0FFFF");
Color* Color::lightGoldenRodYellow = (new Color)->SetHex("#FAFAD2");
Color* Color::lightGray = (new Color)->SetHex("#D3D3D3");
Color* Color::lightGrey = (new Color)->SetHex("#D3D3D3");
Color* Color::lightGreen = (new Color)->SetHex("#90EE90");
Color* Color::lightPink = (new Color)->SetHex("#FFB6C1");
Color* Color::lightSalmon = (new Color)->SetHex("#FFA07A");
Color* Color::lightSeaGreen = (new Color)->SetHex("#20B2AA");
Color* Color::lightSkyBlue = (new Color)->SetHex("#87CEFA");
Color* Color::lightSlateGray = (new Color)->SetHex("#778899");
Color* Color::lightSlateGrey = (new Color)->SetHex("#778899");
Color* Color::lightSteelBlue = (new Color)->SetHex("#B0C4DE");
Color* Color::lightYellow = (new Color)->SetHex("#FFFFE0");
Color* Color::lime = (new Color)->SetHex("#00FF00");
Color* Color::limeGreen = (new Color)->SetHex("#32CD32");
Color* Color::linen = (new Color)->SetHex("#FAF0E6");
Color* Color::magenta = (new Color)->SetHex("#FF00FF");
Color* Color::maroon = (new Color)->SetHex("#800000");
Color* Color::mediumAquaMarine = (new Color)->SetHex("#66CDAA");
Color* Color::mediumBlue = (new Color)->SetHex("#0000CD");
Color* Color::mediumOrchid = (new Color)->SetHex("#BA55D3");
Color* Color::mediumPurple = (new Color)->SetHex("#9370DB");
Color* Color::mediumSeaGreen = (new Color)->SetHex("#3CB371");
Color* Color::mediumSlateBlue = (new Color)->SetHex("#7B68EE");
Color* Color::mediumSpringGreen = (new Color)->SetHex("#00FA9A");
Color* Color::mediumTurquoise = (new Color)->SetHex("#48D1CC");
Color* Color::mediumVioletRed = (new Color)->SetHex("#C71585");
Color* Color::midnightBlue = (new Color)->SetHex("#191970");
Color* Color::mintCream = (new Color)->SetHex("#F5FFFA");
Color* Color::mistyRose = (new Color)->SetHex("#FFE4E1");
Color* Color::moccasin = (new Color)->SetHex("#FFE4B5");
Color* Color::navajoWhite = (new Color)->SetHex("#FFDEAD");
Color* Color::navy = (new Color)->SetHex("#000080");
Color* Color::oldLace = (new Color)->SetHex("#FDF5E6");
Color* Color::olive = (new Color)->SetHex("#808000");
Color* Color::oliveDrab = (new Color)->SetHex("#6B8E23");
Color* Color::orange = (new Color)->SetHex("#FFA500");
Color* Color::orangeRed = (new Color)->SetHex("#FF4500");
Color* Color::orchid = (new Color)->SetHex("#DA70D6");
Color* Color::paleGoldenRod = (new Color)->SetHex("#EEE8AA");
Color* Color::paleGreen = (new Color)->SetHex("#98FB98");
Color* Color::paleTurquoise = (new Color)->SetHex("#AFEEEE");
Color* Color::paleVioletRed = (new Color)->SetHex("#DB7093");
Color* Color::papayaWhip = (new Color)->SetHex("#FFEFD5");
Color* Color::peachPuff = (new Color)->SetHex("#FFDAB9");
Color* Color::peru = (new Color)->SetHex("#CD853F");
Color* Color::pink = (new Color)->SetHex("#FFC0CB");
Color* Color::plum = (new Color)->SetHex("#DDA0DD");
Color* Color::powderBlue = (new Color)->SetHex("#B0E0E6");
Color* Color::purple = (new Color)->SetHex("#800080");
Color* Color::rebeccaPurple = (new Color)->SetHex("#663399");
Color* Color::red = (new Color)->SetHex("#FF0000");
Color* Color::rosyBrown = (new Color)->SetHex("#BC8F8F");
Color* Color::royalBlue = (new Color)->SetHex("#4169E1");
Color* Color::saddleBrown = (new Color)->SetHex("#8B4513");
Color* Color::salmon = (new Color)->SetHex("#FA8072");
Color* Color::sandyBrown = (new Color)->SetHex("#F4A460");
Color* Color::seaGreen = (new Color)->SetHex("#2E8B57");
Color* Color::seaShell = (new Color)->SetHex("#FFF5EE");
Color* Color::sienna = (new Color)->SetHex("#A0522D");
Color* Color::silver = (new Color)->SetHex("#C0C0C0");
Color* Color::skyBlue = (new Color)->SetHex("#87CEEB");
Color* Color::slateBlue = (new Color)->SetHex("#6A5ACD");
Color* Color::slateGray = (new Color)->SetHex("#708090");
Color* Color::slateGrey = (new Color)->SetHex("#708090");
Color* Color::snow = (new Color)->SetHex("#FFFAFA");
Color* Color::springGreen = (new Color)->SetHex("#00FF7F");
Color* Color::steelBlue = (new Color)->SetHex("#4682B4");
Color* Color::tan = (new Color)->SetHex("#D2B48C");
Color* Color::teal = (new Color)->SetHex("#008080");
Color* Color::thistle = (new Color)->SetHex("#D8BFD8");
Color* Color::tomato = (new Color)->SetHex("#FF6347");
Color* Color::turquoise = (new Color)->SetHex("#40E0D0");
Color* Color::violet = (new Color)->SetHex("#EE82EE");
Color* Color::wheat = (new Color)->SetHex("#F5DEB3");
Color* Color::white = (new Color)->SetHex("#FFFFFF");
Color* Color::whiteSmoke = (new Color)->SetHex("#F5F5F5");
Color* Color::yellow = (new Color)->SetHex("#FFFF00");
Color* Color::yellowGreen = (new Color)->SetHex("#9ACD32");