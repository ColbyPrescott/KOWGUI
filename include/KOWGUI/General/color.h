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

            static Color* white;
            static Color* red;
    };

    

}

#endif