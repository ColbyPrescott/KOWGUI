#ifndef TEXT_ELEMENT_H
#define TEXT_ELEMENT_H

#include "KOWGUI/baseElement.h"

#include <string>

namespace KOWGUI {

    class Text : BaseElement {
        public:
            std::string text;
    };

}

#endif