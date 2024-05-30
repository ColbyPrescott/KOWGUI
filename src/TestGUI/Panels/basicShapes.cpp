#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace KOWGUI;

void InitGUIBasicShapes() {
    panels.basicShapes->AddChildren({
        (new Rectangle)->SetPosition(50, 50)->SetSize(75, 75)->SetFillColor(Color::lime),
        (new Circle)->SetPosition(200, 50)->SetSize(100, 100)->SetFillColor(Color::crimson)->SetOutlineColor(Color::white)->SetOutlineWidth(5)
    });
}