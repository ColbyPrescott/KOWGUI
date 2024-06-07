#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include <math.h>

using namespace KOWGUI;

void InitGUIPreTickDemo() {
    void (*hoverAnimation)(BaseNode*) = [](BaseNode* thisNode){
        thisNode->SetY((sin(vexSystemTimeGet() / 1000.0) + 1) / 2.0 * 200);
        ((Text*)thisNode)->SetText("This node is animated! %d", (int)(vexSystemTimeGet() / 1000.0 * 2.0) % 10);
    };

    panels.preTickDemo->AddChildren({
        (new Text)->SetText("This node is animated!")->SetVerticalAlign(VerticalAlign::ascender)->SetPreTick(hoverAnimation)
    });
}