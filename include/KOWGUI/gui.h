#ifndef KOW_GUI_H
#define KOW_GUI_H

namespace KOWGUI {

    enum ElementType {
        Button,
        Text
    };

    struct vagueElement {
        void* pElement;
        ElementType type;
    };

    class GUI {
        private:

        public:
            // Slide vector...
            // Slide is vector of vagueElements...
    };

}

#endif