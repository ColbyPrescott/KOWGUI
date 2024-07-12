#include "KOWGUI/Prefabs/graph.h"

#include "KOWGUI/kowgui.h"

using namespace KOWGUI;

namespace {

    void TickGraph(BaseNode* thisNode) {
        // Get specific nodes from the graph prefab
        Data* pDataNode = (Data*)thisNode->FindShallowID("data");
        Group* pLineContainer = (Group*)thisNode->FindShallowID("lineContainer");
        // Get specific variables from the graph prefab
        std::vector<double> dataVector = *(std::vector<double>*)pDataNode->GetProperty("dataVector").get();

        // Create more line nodes if there's more data than lines
        for(int i = 0; i < dataVector.size() - pLineContainer->children.size(); i++) pLineContainer->AddChild(
            (new Line)->SetPositions(0, 0, 100, 100)->SetColor(Color::white)->SetLineWidth(2)
        );
    }

};

Group* Graph::CreateGraph(std::shared_ptr<std::vector<double>> dataVector, GraphFit fit) {
    return (new Group)->SetPreTick(TickGraph)->AddChildren({
        (new Data)->SetShallowID("data")->SetProperty("dataVector", dataVector),
        (new Group)->SetShallowID("lineContainer"),
    });
}