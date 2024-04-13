#ifndef BUTTON_ELEMENT_H
#define BUTTON_ELEMENT_H

#include "KOWGUI/baseElement.h"

namespace KOWGUI {

    class Button : BaseElement {
        public:
            void (*pFunc)();
    };

}

#endif