#ifndef KOWGUI_GLOBAL_SYSTEMS_H
#define KOWGUI_GLOBAL_SYSTEMS_H

#include <string>

namespace KOWGUI {

    static const int undefinedNumber = -1;
    static const std::string undefinedString = "";

    enum NodeType {
        // Other
        group,

        // Interactable
        clickable,

        // Visible
        rectangle
    };

}

#endif