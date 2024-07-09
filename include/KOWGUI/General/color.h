#ifndef KOWGUI_COLOR_H
#define KOWGUI_COLOR_H

#include "v5.h"
#include "v5_vcs.h"

#include <stdint.h>
#include <string>
#include <memory>

namespace KOWGUI {

    class Color : public std::enable_shared_from_this<Color> { // TO DO oohhhhhhhh, THAT'S how I can template all the BaseNode functions, maybe
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
            std::shared_ptr<Color> SetTransparent(bool transparent);
            std::shared_ptr<Color> SetRGB(uint8_t red, uint8_t green, uint8_t blue);
            std::shared_ptr<Color> SetHex(std::string hex);

            uint8_t GetR();
            uint8_t GetG();
            uint8_t GetB();
            bool GetTransparent();
            
            vex::color GetVexColor();

            static std::shared_ptr<Color> transparent;

            static std::shared_ptr<Color> aliceBlue;
            static std::shared_ptr<Color> antiqueWhite;
            static std::shared_ptr<Color> aqua;
            static std::shared_ptr<Color> aquamarine;
            static std::shared_ptr<Color> azure;
            static std::shared_ptr<Color> beige;
            static std::shared_ptr<Color> bisque;
            static std::shared_ptr<Color> black;
            static std::shared_ptr<Color> blanchedAlmond;
            static std::shared_ptr<Color> blue;
            static std::shared_ptr<Color> blueViolet;
            static std::shared_ptr<Color> brown;
            static std::shared_ptr<Color> burlyWood;
            static std::shared_ptr<Color> cadetBlue;
            static std::shared_ptr<Color> chartreuse;
            static std::shared_ptr<Color> chocolate;
            static std::shared_ptr<Color> coral;
            static std::shared_ptr<Color> cornflowerBlue;
            static std::shared_ptr<Color> cornsilk;
            static std::shared_ptr<Color> crimson;
            static std::shared_ptr<Color> cyan;
            static std::shared_ptr<Color> darkBlue;
            static std::shared_ptr<Color> darkCyan;
            static std::shared_ptr<Color> darkGoldenRod;
            static std::shared_ptr<Color> darkGray;
            static std::shared_ptr<Color> darkGrey;
            static std::shared_ptr<Color> darkGreen;
            static std::shared_ptr<Color> darkKhaki;
            static std::shared_ptr<Color> darkMagenta;
            static std::shared_ptr<Color> darkOliveGreen;
            static std::shared_ptr<Color> darkOrange;
            static std::shared_ptr<Color> darkOrchid;
            static std::shared_ptr<Color> darkRed;
            static std::shared_ptr<Color> darkSalmon;
            static std::shared_ptr<Color> darkSeaGreen;
            static std::shared_ptr<Color> darkSlateBlue;
            static std::shared_ptr<Color> darkSlateGray;
            static std::shared_ptr<Color> darkSlateGrey;
            static std::shared_ptr<Color> darkTurquoise;
            static std::shared_ptr<Color> darkViolet;
            static std::shared_ptr<Color> deepPink;
            static std::shared_ptr<Color> deepSkyBlue;
            static std::shared_ptr<Color> dimGray;
            static std::shared_ptr<Color> dimGrey;
            static std::shared_ptr<Color> dodgerBlue;
            static std::shared_ptr<Color> fireBrick;
            static std::shared_ptr<Color> floralWhite;
            static std::shared_ptr<Color> forestGreen;
            static std::shared_ptr<Color> fuchsia;
            static std::shared_ptr<Color> gainsboro;
            static std::shared_ptr<Color> ghostWhite;
            static std::shared_ptr<Color> gold;
            static std::shared_ptr<Color> goldenRod;
            static std::shared_ptr<Color> gray;
            static std::shared_ptr<Color> grey;
            static std::shared_ptr<Color> green;
            static std::shared_ptr<Color> greenYellow;
            static std::shared_ptr<Color> honeyDew;
            static std::shared_ptr<Color> hotPink;
            static std::shared_ptr<Color> indianRed;
            static std::shared_ptr<Color> indigo;
            static std::shared_ptr<Color> ivory;
            static std::shared_ptr<Color> khaki;
            static std::shared_ptr<Color> lavender;
            static std::shared_ptr<Color> lavenderBlush;
            static std::shared_ptr<Color> lawnGreen;
            static std::shared_ptr<Color> lemonChiffon;
            static std::shared_ptr<Color> lightBlue;
            static std::shared_ptr<Color> lightCoral;
            static std::shared_ptr<Color> lightCyan;
            static std::shared_ptr<Color> lightGoldenRodYellow;
            static std::shared_ptr<Color> lightGray;
            static std::shared_ptr<Color> lightGrey;
            static std::shared_ptr<Color> lightGreen;
            static std::shared_ptr<Color> lightPink;
            static std::shared_ptr<Color> lightSalmon;
            static std::shared_ptr<Color> lightSeaGreen;
            static std::shared_ptr<Color> lightSkyBlue;
            static std::shared_ptr<Color> lightSlateGray;
            static std::shared_ptr<Color> lightSlateGrey;
            static std::shared_ptr<Color> lightSteelBlue;
            static std::shared_ptr<Color> lightYellow;
            static std::shared_ptr<Color> lime;
            static std::shared_ptr<Color> limeGreen;
            static std::shared_ptr<Color> linen;
            static std::shared_ptr<Color> magenta;
            static std::shared_ptr<Color> maroon;
            static std::shared_ptr<Color> mediumAquaMarine;
            static std::shared_ptr<Color> mediumBlue;
            static std::shared_ptr<Color> mediumOrchid;
            static std::shared_ptr<Color> mediumPurple;
            static std::shared_ptr<Color> mediumSeaGreen;
            static std::shared_ptr<Color> mediumSlateBlue;
            static std::shared_ptr<Color> mediumSpringGreen;
            static std::shared_ptr<Color> mediumTurquoise;
            static std::shared_ptr<Color> mediumVioletRed;
            static std::shared_ptr<Color> midnightBlue;
            static std::shared_ptr<Color> mintCream;
            static std::shared_ptr<Color> mistyRose;
            static std::shared_ptr<Color> moccasin;
            static std::shared_ptr<Color> navajoWhite;
            static std::shared_ptr<Color> navy;
            static std::shared_ptr<Color> oldLace;
            static std::shared_ptr<Color> olive;
            static std::shared_ptr<Color> oliveDrab;
            static std::shared_ptr<Color> orange;
            static std::shared_ptr<Color> orangeRed;
            static std::shared_ptr<Color> orchid;
            static std::shared_ptr<Color> paleGoldenRod;
            static std::shared_ptr<Color> paleGreen;
            static std::shared_ptr<Color> paleTurquoise;
            static std::shared_ptr<Color> paleVioletRed;
            static std::shared_ptr<Color> papayaWhip;
            static std::shared_ptr<Color> peachPuff;
            static std::shared_ptr<Color> peru;
            static std::shared_ptr<Color> pink;
            static std::shared_ptr<Color> plum;
            static std::shared_ptr<Color> powderBlue;
            static std::shared_ptr<Color> purple;
            static std::shared_ptr<Color> rebeccaPurple;
            static std::shared_ptr<Color> red;
            static std::shared_ptr<Color> rosyBrown;
            static std::shared_ptr<Color> royalBlue;
            static std::shared_ptr<Color> saddleBrown;
            static std::shared_ptr<Color> salmon;
            static std::shared_ptr<Color> sandyBrown;
            static std::shared_ptr<Color> seaGreen;
            static std::shared_ptr<Color> seaShell;
            static std::shared_ptr<Color> sienna;
            static std::shared_ptr<Color> silver;
            static std::shared_ptr<Color> skyBlue;
            static std::shared_ptr<Color> slateBlue;
            static std::shared_ptr<Color> slateGray;
            static std::shared_ptr<Color> slateGrey;
            static std::shared_ptr<Color> snow;
            static std::shared_ptr<Color> springGreen;
            static std::shared_ptr<Color> steelBlue;
            static std::shared_ptr<Color> tan;
            static std::shared_ptr<Color> teal;
            static std::shared_ptr<Color> thistle;
            static std::shared_ptr<Color> tomato;
            static std::shared_ptr<Color> turquoise;
            static std::shared_ptr<Color> violet;
            static std::shared_ptr<Color> wheat;
            static std::shared_ptr<Color> white;
            static std::shared_ptr<Color> whiteSmoke;
            static std::shared_ptr<Color> yellow;
            static std::shared_ptr<Color> yellowGreen;
    };

    

}

#endif