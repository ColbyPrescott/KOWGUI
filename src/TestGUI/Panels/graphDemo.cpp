#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

std::vector<double> testVector = {0, 5, -2, 6, 0};
std::shared_ptr<std::vector<double>> pTestVector(&testVector);

void InitGUIGraphDemo() {
    panels.graphDemo->AddChildren({
        (new Rectangle)->SetPosition(20, 20)->SetSize(200, 200)->SetOutlineColor(Color::white)->AddChildren({
            Graph::CreateGraph(pTestVector),
        }),
    });
}