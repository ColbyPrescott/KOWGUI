#ifndef KOWGUI_COLOR_H
#define KOWGUI_COLOR_H

#include "v5.h"
#include "v5_vcs.h"

#include <stdint.h>
#include <string>

namespace KOWGUI {

    class Color {
        private:
            // Red component
            uint8_t mR = 0;
            // Green component
            uint8_t mG = 0;
            // Blue component
            uint8_t mB = 0;
            // Whether or not this color should be drawn
            bool mTransparent = false;

        public:
            Color* SetTransparent(bool transparent);
            Color* SetRGB(uint8_t red, uint8_t green, uint8_t blue);
            Color* SetHex(std::string hex);

            uint8_t GetR();
            uint8_t GetG();
            uint8_t GetB();
            bool GetTransparent();
            
            vex::color GetVexColor();

            static Color* transparent;

            static Color* aliceBlue;
            static Color* antiqueWhite;
            static Color* aqua;
            static Color* aquamarine;
            static Color* azure;
            static Color* beige;
            static Color* bisque;
            static Color* black;
            static Color* blanchedAlmond;
            static Color* blue;
            static Color* blueViolet;
            static Color* brown;
            static Color* burlyWood;
            static Color* cadetBlue;
            static Color* chartreuse;
            static Color* chocolate;
            static Color* coral;
            static Color* cornflowerBlue;
            static Color* cornsilk;
            static Color* crimson;
            static Color* cyan;
            static Color* darkBlue;
            static Color* darkCyan;
            static Color* darkGoldenRod;
            static Color* darkGray;
            static Color* darkGrey;
            static Color* darkGreen;
            static Color* darkKhaki;
            static Color* darkMagenta;
            static Color* darkOliveGreen;
            static Color* darkOrange;
            static Color* darkOrchid;
            static Color* darkRed;
            static Color* darkSalmon;
            static Color* darkSeaGreen;
            static Color* darkSlateBlue;
            static Color* darkSlateGray;
            static Color* darkSlateGrey;
            static Color* darkTurquoise;
            static Color* darkViolet;
            static Color* deepPink;
            static Color* deepSkyBlue;
            static Color* dimGray;
            static Color* dimGrey;
            static Color* dodgerBlue;
            static Color* fireBrick;
            static Color* floralWhite;
            static Color* forestGreen;
            static Color* fuchsia;
            static Color* gainsboro;
            static Color* ghostWhite;
            static Color* gold;
            static Color* goldenRod;
            static Color* gray;
            static Color* grey;
            static Color* green;
            static Color* greenYellow;
            static Color* honeyDew;
            static Color* hotPink;
            static Color* indianRed;
            static Color* indigo;
            static Color* ivory;
            static Color* khaki;
            static Color* lavender;
            static Color* lavenderBlush;
            static Color* lawnGreen;
            static Color* lemonChiffon;
            static Color* lightBlue;
            static Color* lightCoral;
            static Color* lightCyan;
            static Color* lightGoldenRodYellow;
            static Color* lightGray;
            static Color* lightGrey;
            static Color* lightGreen;
            static Color* lightPink;
            static Color* lightSalmon;
            static Color* lightSeaGreen;
            static Color* lightSkyBlue;
            static Color* lightSlateGray;
            static Color* lightSlateGrey;
            static Color* lightSteelBlue;
            static Color* lightYellow;
            static Color* lime;
            static Color* limeGreen;
            static Color* linen;
            static Color* magenta;
            static Color* maroon;
            static Color* mediumAquaMarine;
            static Color* mediumBlue;
            static Color* mediumOrchid;
            static Color* mediumPurple;
            static Color* mediumSeaGreen;
            static Color* mediumSlateBlue;
            static Color* mediumSpringGreen;
            static Color* mediumTurquoise;
            static Color* mediumVioletRed;
            static Color* midnightBlue;
            static Color* mintCream;
            static Color* mistyRose;
            static Color* moccasin;
            static Color* navajoWhite;
            static Color* navy;
            static Color* oldLace;
            static Color* olive;
            static Color* oliveDrab;
            static Color* orange;
            static Color* orangeRed;
            static Color* orchid;
            static Color* paleGoldenRod;
            static Color* paleGreen;
            static Color* paleTurquoise;
            static Color* paleVioletRed;
            static Color* papayaWhip;
            static Color* peachPuff;
            static Color* peru;
            static Color* pink;
            static Color* plum;
            static Color* powderBlue;
            static Color* purple;
            static Color* rebeccaPurple;
            static Color* red;
            static Color* rosyBrown;
            static Color* royalBlue;
            static Color* saddleBrown;
            static Color* salmon;
            static Color* sandyBrown;
            static Color* seaGreen;
            static Color* seaShell;
            static Color* sienna;
            static Color* silver;
            static Color* skyBlue;
            static Color* slateBlue;
            static Color* slateGray;
            static Color* slateGrey;
            static Color* snow;
            static Color* springGreen;
            static Color* steelBlue;
            static Color* tan;
            static Color* teal;
            static Color* thistle;
            static Color* tomato;
            static Color* turquoise;
            static Color* violet;
            static Color* wheat;
            static Color* white;
            static Color* whiteSmoke;
            static Color* yellow;
            static Color* yellowGreen;
    };

    

}

#endif