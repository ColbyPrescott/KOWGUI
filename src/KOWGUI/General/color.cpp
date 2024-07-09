#include "KOWGUI/General/color.h"

#include <sstream>

using namespace KOWGUI;

// Set whether or not this color will be drawn
std::shared_ptr<Color> Color::SetTransparent(bool transparent) {
    mTransparent = transparent;
    return shared_from_this();
}

// Set the color with red, green, and blue values ranging 0 - 255
std::shared_ptr<Color> Color::SetRGB(uint8_t red, uint8_t green, uint8_t blue) {
    mR = red;
    mG = green;
    mB = blue;
    return shared_from_this();
}

// Set the color with a hexidecimal color code value, "#xxxxxx"
std::shared_ptr<Color> Color::SetHex(std::string hex) {
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

    return shared_from_this();
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

std::shared_ptr<Color> Color::transparent = std::make_shared<Color>()->SetTransparent(true);

std::shared_ptr<Color> Color::aliceBlue = std::make_shared<Color>()->SetHex("#F0F8FF");
std::shared_ptr<Color> Color::antiqueWhite = std::make_shared<Color>()->SetHex("#FAEBD7");
std::shared_ptr<Color> Color::aqua = std::make_shared<Color>()->SetHex("#00FFFF");
std::shared_ptr<Color> Color::aquamarine = std::make_shared<Color>()->SetHex("#7FFFD4");
std::shared_ptr<Color> Color::azure = std::make_shared<Color>()->SetHex("#F0FFFF");
std::shared_ptr<Color> Color::beige = std::make_shared<Color>()->SetHex("#F5F5DC");
std::shared_ptr<Color> Color::bisque = std::make_shared<Color>()->SetHex("#FFE4C4");
std::shared_ptr<Color> Color::black = std::make_shared<Color>()->SetHex("#000000");
std::shared_ptr<Color> Color::blanchedAlmond = std::make_shared<Color>()->SetHex("#FFEBCD");
std::shared_ptr<Color> Color::blue = std::make_shared<Color>()->SetHex("#0000FF");
std::shared_ptr<Color> Color::blueViolet = std::make_shared<Color>()->SetHex("#8A2BE2");
std::shared_ptr<Color> Color::brown = std::make_shared<Color>()->SetHex("#A52A2A");
std::shared_ptr<Color> Color::burlyWood = std::make_shared<Color>()->SetHex("#DEB887");
std::shared_ptr<Color> Color::cadetBlue = std::make_shared<Color>()->SetHex("#5F9EA0");
std::shared_ptr<Color> Color::chartreuse = std::make_shared<Color>()->SetHex("#7FFF00");
std::shared_ptr<Color> Color::chocolate = std::make_shared<Color>()->SetHex("#D2691E");
std::shared_ptr<Color> Color::coral = std::make_shared<Color>()->SetHex("#FF7F50");
std::shared_ptr<Color> Color::cornflowerBlue = std::make_shared<Color>()->SetHex("#6495ED");
std::shared_ptr<Color> Color::cornsilk = std::make_shared<Color>()->SetHex("#FFF8DC");
std::shared_ptr<Color> Color::crimson = std::make_shared<Color>()->SetHex("#DC143C");
std::shared_ptr<Color> Color::cyan = std::make_shared<Color>()->SetHex("#00FFFF");
std::shared_ptr<Color> Color::darkBlue = std::make_shared<Color>()->SetHex("#00008B");
std::shared_ptr<Color> Color::darkCyan = std::make_shared<Color>()->SetHex("#008B8B");
std::shared_ptr<Color> Color::darkGoldenRod = std::make_shared<Color>()->SetHex("#B8860B");
std::shared_ptr<Color> Color::darkGray = std::make_shared<Color>()->SetHex("#A9A9A9");
std::shared_ptr<Color> Color::darkGrey = std::make_shared<Color>()->SetHex("#A9A9A9");
std::shared_ptr<Color> Color::darkGreen = std::make_shared<Color>()->SetHex("#006400");
std::shared_ptr<Color> Color::darkKhaki = std::make_shared<Color>()->SetHex("#BDB76B");
std::shared_ptr<Color> Color::darkMagenta = std::make_shared<Color>()->SetHex("#8B008B");
std::shared_ptr<Color> Color::darkOliveGreen = std::make_shared<Color>()->SetHex("#556B2F");
std::shared_ptr<Color> Color::darkOrange = std::make_shared<Color>()->SetHex("#FF8C00");
std::shared_ptr<Color> Color::darkOrchid = std::make_shared<Color>()->SetHex("#9932CC");
std::shared_ptr<Color> Color::darkRed = std::make_shared<Color>()->SetHex("#8B0000");
std::shared_ptr<Color> Color::darkSalmon = std::make_shared<Color>()->SetHex("#E9967A");
std::shared_ptr<Color> Color::darkSeaGreen = std::make_shared<Color>()->SetHex("#8FBC8F");
std::shared_ptr<Color> Color::darkSlateBlue = std::make_shared<Color>()->SetHex("#483D8B");
std::shared_ptr<Color> Color::darkSlateGray = std::make_shared<Color>()->SetHex("#2F4F4F");
std::shared_ptr<Color> Color::darkSlateGrey = std::make_shared<Color>()->SetHex("#2F4F4F");
std::shared_ptr<Color> Color::darkTurquoise = std::make_shared<Color>()->SetHex("#00CED1");
std::shared_ptr<Color> Color::darkViolet = std::make_shared<Color>()->SetHex("#9400D3");
std::shared_ptr<Color> Color::deepPink = std::make_shared<Color>()->SetHex("#FF1493");
std::shared_ptr<Color> Color::deepSkyBlue = std::make_shared<Color>()->SetHex("#00BFFF");
std::shared_ptr<Color> Color::dimGray = std::make_shared<Color>()->SetHex("#696969");
std::shared_ptr<Color> Color::dimGrey = std::make_shared<Color>()->SetHex("#696969");
std::shared_ptr<Color> Color::dodgerBlue = std::make_shared<Color>()->SetHex("#1E90FF");
std::shared_ptr<Color> Color::fireBrick = std::make_shared<Color>()->SetHex("#B22222");
std::shared_ptr<Color> Color::floralWhite = std::make_shared<Color>()->SetHex("#FFFAF0");
std::shared_ptr<Color> Color::forestGreen = std::make_shared<Color>()->SetHex("#228B22");
std::shared_ptr<Color> Color::fuchsia = std::make_shared<Color>()->SetHex("#FF00FF");
std::shared_ptr<Color> Color::gainsboro = std::make_shared<Color>()->SetHex("#DCDCDC");
std::shared_ptr<Color> Color::ghostWhite = std::make_shared<Color>()->SetHex("#F8F8FF");
std::shared_ptr<Color> Color::gold = std::make_shared<Color>()->SetHex("#FFD700");
std::shared_ptr<Color> Color::goldenRod = std::make_shared<Color>()->SetHex("#DAA520");
std::shared_ptr<Color> Color::gray = std::make_shared<Color>()->SetHex("#808080");
std::shared_ptr<Color> Color::grey = std::make_shared<Color>()->SetHex("#808080");
std::shared_ptr<Color> Color::green = std::make_shared<Color>()->SetHex("#008000");
std::shared_ptr<Color> Color::greenYellow = std::make_shared<Color>()->SetHex("#ADFF2F");
std::shared_ptr<Color> Color::honeyDew = std::make_shared<Color>()->SetHex("#F0FFF0");
std::shared_ptr<Color> Color::hotPink = std::make_shared<Color>()->SetHex("#FF69B4");
std::shared_ptr<Color> Color::indianRed = std::make_shared<Color>()->SetHex("#CD5C5C");
std::shared_ptr<Color> Color::indigo = std::make_shared<Color>()->SetHex("#4B0082");
std::shared_ptr<Color> Color::ivory = std::make_shared<Color>()->SetHex("#FFFFF0");
std::shared_ptr<Color> Color::khaki = std::make_shared<Color>()->SetHex("#F0E68C");
std::shared_ptr<Color> Color::lavender = std::make_shared<Color>()->SetHex("#E6E6FA");
std::shared_ptr<Color> Color::lavenderBlush = std::make_shared<Color>()->SetHex("#FFF0F5");
std::shared_ptr<Color> Color::lawnGreen = std::make_shared<Color>()->SetHex("#7CFC00");
std::shared_ptr<Color> Color::lemonChiffon = std::make_shared<Color>()->SetHex("#FFFACD");
std::shared_ptr<Color> Color::lightBlue = std::make_shared<Color>()->SetHex("#ADD8E6");
std::shared_ptr<Color> Color::lightCoral = std::make_shared<Color>()->SetHex("#F08080");
std::shared_ptr<Color> Color::lightCyan = std::make_shared<Color>()->SetHex("#E0FFFF");
std::shared_ptr<Color> Color::lightGoldenRodYellow = std::make_shared<Color>()->SetHex("#FAFAD2");
std::shared_ptr<Color> Color::lightGray = std::make_shared<Color>()->SetHex("#D3D3D3");
std::shared_ptr<Color> Color::lightGrey = std::make_shared<Color>()->SetHex("#D3D3D3");
std::shared_ptr<Color> Color::lightGreen = std::make_shared<Color>()->SetHex("#90EE90");
std::shared_ptr<Color> Color::lightPink = std::make_shared<Color>()->SetHex("#FFB6C1");
std::shared_ptr<Color> Color::lightSalmon = std::make_shared<Color>()->SetHex("#FFA07A");
std::shared_ptr<Color> Color::lightSeaGreen = std::make_shared<Color>()->SetHex("#20B2AA");
std::shared_ptr<Color> Color::lightSkyBlue = std::make_shared<Color>()->SetHex("#87CEFA");
std::shared_ptr<Color> Color::lightSlateGray = std::make_shared<Color>()->SetHex("#778899");
std::shared_ptr<Color> Color::lightSlateGrey = std::make_shared<Color>()->SetHex("#778899");
std::shared_ptr<Color> Color::lightSteelBlue = std::make_shared<Color>()->SetHex("#B0C4DE");
std::shared_ptr<Color> Color::lightYellow = std::make_shared<Color>()->SetHex("#FFFFE0");
std::shared_ptr<Color> Color::lime = std::make_shared<Color>()->SetHex("#00FF00");
std::shared_ptr<Color> Color::limeGreen = std::make_shared<Color>()->SetHex("#32CD32");
std::shared_ptr<Color> Color::linen = std::make_shared<Color>()->SetHex("#FAF0E6");
std::shared_ptr<Color> Color::magenta = std::make_shared<Color>()->SetHex("#FF00FF");
std::shared_ptr<Color> Color::maroon = std::make_shared<Color>()->SetHex("#800000");
std::shared_ptr<Color> Color::mediumAquaMarine = std::make_shared<Color>()->SetHex("#66CDAA");
std::shared_ptr<Color> Color::mediumBlue = std::make_shared<Color>()->SetHex("#0000CD");
std::shared_ptr<Color> Color::mediumOrchid = std::make_shared<Color>()->SetHex("#BA55D3");
std::shared_ptr<Color> Color::mediumPurple = std::make_shared<Color>()->SetHex("#9370DB");
std::shared_ptr<Color> Color::mediumSeaGreen = std::make_shared<Color>()->SetHex("#3CB371");
std::shared_ptr<Color> Color::mediumSlateBlue = std::make_shared<Color>()->SetHex("#7B68EE");
std::shared_ptr<Color> Color::mediumSpringGreen = std::make_shared<Color>()->SetHex("#00FA9A");
std::shared_ptr<Color> Color::mediumTurquoise = std::make_shared<Color>()->SetHex("#48D1CC");
std::shared_ptr<Color> Color::mediumVioletRed = std::make_shared<Color>()->SetHex("#C71585");
std::shared_ptr<Color> Color::midnightBlue = std::make_shared<Color>()->SetHex("#191970");
std::shared_ptr<Color> Color::mintCream = std::make_shared<Color>()->SetHex("#F5FFFA");
std::shared_ptr<Color> Color::mistyRose = std::make_shared<Color>()->SetHex("#FFE4E1");
std::shared_ptr<Color> Color::moccasin = std::make_shared<Color>()->SetHex("#FFE4B5");
std::shared_ptr<Color> Color::navajoWhite = std::make_shared<Color>()->SetHex("#FFDEAD");
std::shared_ptr<Color> Color::navy = std::make_shared<Color>()->SetHex("#000080");
std::shared_ptr<Color> Color::oldLace = std::make_shared<Color>()->SetHex("#FDF5E6");
std::shared_ptr<Color> Color::olive = std::make_shared<Color>()->SetHex("#808000");
std::shared_ptr<Color> Color::oliveDrab = std::make_shared<Color>()->SetHex("#6B8E23");
std::shared_ptr<Color> Color::orange = std::make_shared<Color>()->SetHex("#FFA500");
std::shared_ptr<Color> Color::orangeRed = std::make_shared<Color>()->SetHex("#FF4500");
std::shared_ptr<Color> Color::orchid = std::make_shared<Color>()->SetHex("#DA70D6");
std::shared_ptr<Color> Color::paleGoldenRod = std::make_shared<Color>()->SetHex("#EEE8AA");
std::shared_ptr<Color> Color::paleGreen = std::make_shared<Color>()->SetHex("#98FB98");
std::shared_ptr<Color> Color::paleTurquoise = std::make_shared<Color>()->SetHex("#AFEEEE");
std::shared_ptr<Color> Color::paleVioletRed = std::make_shared<Color>()->SetHex("#DB7093");
std::shared_ptr<Color> Color::papayaWhip = std::make_shared<Color>()->SetHex("#FFEFD5");
std::shared_ptr<Color> Color::peachPuff = std::make_shared<Color>()->SetHex("#FFDAB9");
std::shared_ptr<Color> Color::peru = std::make_shared<Color>()->SetHex("#CD853F");
std::shared_ptr<Color> Color::pink = std::make_shared<Color>()->SetHex("#FFC0CB");
std::shared_ptr<Color> Color::plum = std::make_shared<Color>()->SetHex("#DDA0DD");
std::shared_ptr<Color> Color::powderBlue = std::make_shared<Color>()->SetHex("#B0E0E6");
std::shared_ptr<Color> Color::purple = std::make_shared<Color>()->SetHex("#800080");
std::shared_ptr<Color> Color::rebeccaPurple = std::make_shared<Color>()->SetHex("#663399");
std::shared_ptr<Color> Color::red = std::make_shared<Color>()->SetHex("#FF0000");
std::shared_ptr<Color> Color::rosyBrown = std::make_shared<Color>()->SetHex("#BC8F8F");
std::shared_ptr<Color> Color::royalBlue = std::make_shared<Color>()->SetHex("#4169E1");
std::shared_ptr<Color> Color::saddleBrown = std::make_shared<Color>()->SetHex("#8B4513");
std::shared_ptr<Color> Color::salmon = std::make_shared<Color>()->SetHex("#FA8072");
std::shared_ptr<Color> Color::sandyBrown = std::make_shared<Color>()->SetHex("#F4A460");
std::shared_ptr<Color> Color::seaGreen = std::make_shared<Color>()->SetHex("#2E8B57");
std::shared_ptr<Color> Color::seaShell = std::make_shared<Color>()->SetHex("#FFF5EE");
std::shared_ptr<Color> Color::sienna = std::make_shared<Color>()->SetHex("#A0522D");
std::shared_ptr<Color> Color::silver = std::make_shared<Color>()->SetHex("#C0C0C0");
std::shared_ptr<Color> Color::skyBlue = std::make_shared<Color>()->SetHex("#87CEEB");
std::shared_ptr<Color> Color::slateBlue = std::make_shared<Color>()->SetHex("#6A5ACD");
std::shared_ptr<Color> Color::slateGray = std::make_shared<Color>()->SetHex("#708090");
std::shared_ptr<Color> Color::slateGrey = std::make_shared<Color>()->SetHex("#708090");
std::shared_ptr<Color> Color::snow = std::make_shared<Color>()->SetHex("#FFFAFA");
std::shared_ptr<Color> Color::springGreen = std::make_shared<Color>()->SetHex("#00FF7F");
std::shared_ptr<Color> Color::steelBlue = std::make_shared<Color>()->SetHex("#4682B4");
std::shared_ptr<Color> Color::tan = std::make_shared<Color>()->SetHex("#D2B48C");
std::shared_ptr<Color> Color::teal = std::make_shared<Color>()->SetHex("#008080");
std::shared_ptr<Color> Color::thistle = std::make_shared<Color>()->SetHex("#D8BFD8");
std::shared_ptr<Color> Color::tomato = std::make_shared<Color>()->SetHex("#FF6347");
std::shared_ptr<Color> Color::turquoise = std::make_shared<Color>()->SetHex("#40E0D0");
std::shared_ptr<Color> Color::violet = std::make_shared<Color>()->SetHex("#EE82EE");
std::shared_ptr<Color> Color::wheat = std::make_shared<Color>()->SetHex("#F5DEB3");
std::shared_ptr<Color> Color::white = std::make_shared<Color>()->SetHex("#FFFFFF");
std::shared_ptr<Color> Color::whiteSmoke = std::make_shared<Color>()->SetHex("#F5F5F5");
std::shared_ptr<Color> Color::yellow = std::make_shared<Color>()->SetHex("#FFFF00");
std::shared_ptr<Color> Color::yellowGreen = std::make_shared<Color>()->SetHex("#9ACD32");