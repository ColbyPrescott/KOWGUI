#ifndef KOWGUI_KEYBOARD_PREFAB_H
#define KOWGUI_KEYBOARD_PREFAB_H

#include "KOWGUI/Nodes/Basic/group.h"

#include <string>

namespace KOWGUI {
    namespace Keyboard {

        Group* CreateKeyboard();
        // void CreateNumpad(int x, int y, int width, int height, bool movable, bool resizable);

        void Open(Group* keyboard, std::string& str);
        void Open(Group* keyboard, std::string startStr, void (*closeCallback)(std::string));
        // void Open(Group* numpad, int num, void (*closeCalback)(int));
        // void Open(Group* numpad, double num, void (*closeCalback)(double));

    }
}

#endif