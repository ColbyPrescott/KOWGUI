#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

std::vector<double> testVector = {1, 2, 3, 10, 2, 1};
std::shared_ptr<std::vector<double>> pTestVector(&testVector);

void InitGUIGraphDemo() {
    panels.graphDemo->AddChildren({
        (new Rectangle)->SetPosition(20, 20)->SetSize(200, 200)->SetOutlineColor(Color::white)->AddChildren({
            Graph::CreateGraph(pTestVector),
        }),
    });
}