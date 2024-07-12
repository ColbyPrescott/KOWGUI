#include "KOWGUI/Prefabs/graph.h"

#include "KOWGUI/kowgui.h"

#include <iostream> // DEBUG
#include <bits/stdc++.h>

using namespace KOWGUI;

namespace {

    void DrawGraphScale(std::vector<double>& rDataVector, Group* pLineContainer, int graphWidth, int graphHeight) {
        // Calculate extends of data range
        double dataMinValue = *std::min_element(rDataVector.begin(), rDataVector.end());
        double dataMaxValue = *std::max_element(rDataVector.begin(), rDataVector.end());

        // Loop through every data point and update the Line node
        for(int i = 0; i < rDataVector.size() - 1; i++) {
            double currentValue = rDataVector[i];
            double nextValue = rDataVector[i + 1];
            Line* pCurrentLine = (Line*)(pLineContainer->children[i]);

            pCurrentLine->
                // X coordinate calculated as the index multiplied by the X screen distance of eqully spaced data points
                SetX1((i + 0) * ((double)graphWidth / (rDataVector.size() - 1)))->
                SetX2((i + 1) * ((double)graphWidth / (rDataVector.size() - 1)))->
                // Y coordinate calculated like (num - min1) / (max1 - min1) * (max2 - min2) + min2. Maps number from one range to another
                SetY1((currentValue - dataMinValue) / (dataMaxValue - dataMinValue) * (-graphHeight) + graphHeight)->
                SetY2((nextValue - dataMinValue) / (dataMaxValue - dataMinValue) * (-graphHeight) + graphHeight);
        }
    }

    void UpdateGraph(BaseNode* thisNode) {
        // Get specific nodes from the graph prefab
        Data* pDataNode = (Data*)thisNode->FindShallowID("data");
        Group* pLineContainer = (Group*)thisNode->FindShallowID("lineContainer");
        // Get specific variables from the graph prefab
        std::vector<double> dataVector = *(std::vector<double>*)pDataNode->GetProperty("dataVector").get();
        int graphWidth = thisNode->CalculateWidth();
        int graphHeight = thisNode->CalculateHeight();

        // Calculate how many more data points there are than Line nodes
        int numDataNodeDifference = dataVector.size() - pLineContainer->children.size();

        // Create more Line nodes if there's more data than lines
        for(int i = 0; i < numDataNodeDifference - 1; i++) {
            pLineContainer->AddChild(
                (new Line)->SetColor(Color::white)->SetLineWidth(1)
            );
        }

        // TO DO Delete Line nodes if there's less data than lines

        // TO DO Replace with switch statement once graph fit is actually saved
        if(true) DrawGraphScale(dataVector, pLineContainer, graphWidth, graphHeight);
    }

};

Group* Graph::CreateGraph(std::shared_ptr<std::vector<double>> dataVector, GraphFit fit) {
    return (new Group)->SetPreTick(UpdateGraph)->AddChildren({
        (new Data)->SetShallowID("data")->SetProperty("dataVector", dataVector),
        (new Group)->SetShallowID("lineContainer"),
    });
}