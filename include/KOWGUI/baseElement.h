#ifndef BASE_ELEMENT_H
#define BASE_ELEMENT_H

namespace KOWGUI {

    class BaseElement {
        public:
            int x;
            int y;
            int width;
            int height;

            BaseElement* parentElement;
    };

}

#endif