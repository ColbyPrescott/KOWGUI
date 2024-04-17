#ifndef KOWGUI_COLOR_H
#define KOWGUI_COLOR_H

#include "v5.h"
#include "v5_vcs.h"

#include <stdint.h>


namespace KOWGUI {

    class Color {
        private:
            uint8_t mR = 0;
            uint8_t mG = 0;
            uint8_t mB = 0;
            bool mTransparent = false;

        public:
            Color* SetRGB(uint8_t red, uint8_t green, uint8_t blue);

            vex::color GetVexColor();
    };

}

#endif