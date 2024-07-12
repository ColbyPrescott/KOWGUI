#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

#include <stdlib.h>

using namespace KOWGUI;

namespace {

    std::vector<double> testVector = {0, 5, -2, 6, 0};
    std::shared_ptr<std::vector<double>> pTestVector(&testVector);

    void AddPointToTestVector(BaseNode* thisNode) {
        testVector.push_back(rand() % 10);
    }

    void RemovePointFromTestVector(BaseNode* thisNode) {
        if(testVector.empty()) return;
        testVector.erase(testVector.begin() + (rand() % testVector.size()));
    }

}

void InitGUIGraphDemo() {
    panels.graphDemo->AddChildren({
        // Graph
        (new Rectangle)->SetPosition(20, 20)->SetSize(200, 200)->SetOutlineColor(Color::white)->AddChildren({
            Graph::CreateGraph(pTestVector),
        }),

        // Add data point button
        (new Clickable)->SetPosition(240, 20)->SetSize(30, 30)->SetRelease(AddPointToTestVector)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetPosition(1, 2)->SetText("+")->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
        }),

        // Remove data point button
        (new Clickable)->SetPosition(290, 20)->SetSize(30, 30)->SetRelease(RemovePointFromTestVector)->AddChildren({
            (new NFocused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonNFocused)}),
            (new Focused)->AddChildren({(new Rectangle)->SetFillColor(theme.buttonFocused)}),

            (new Text)->SetText("-")->SetAlignments(HorizontalAlign::center, VerticalAlign::middle),
        }),
    });
}