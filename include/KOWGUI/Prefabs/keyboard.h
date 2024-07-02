#ifndef KOWGUI_KEYBOARD_PREFAB_H
#define KOWGUI_KEYBOARD_PREFAB_H

#include "KOWGUI/Nodes/Basic/group.h"
#include "KOWGUI/General/color.h"

#include <string>

namespace KOWGUI {
    namespace Keyboard {

        Group* CreateKeyboard(Color* customBackgroundColor = nullptr, Color* customButtonNFocusedColor = nullptr, Color* customButtonFocusedColor = nullptr, Color* customHighlightColor = nullptr);
        Group* CreateNumpad(int x = 10, int y = 10, int width = 100, int height = 150, bool movable = true, bool resizable = true);

        void Open(Group* keyboard, std::string& str);
        void Open(Group* keyboard, std::string startStr, void (*closeCallback)(std::string));
        void Open(Group* numpad, int startNum, void (*closeCalback)(int));
        // void Open(Group* numpad, double num, void (*closeCalback)(double));

    }
}

#endif