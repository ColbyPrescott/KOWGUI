#include "KOWGUI/Prefabs/graph.h"

#include "KOWGUI/kowgui.h"

#include <bits/stdc++.h>

using namespace KOWGUI;

// Set a Text node to show the coordinate of the graph point it is a child of
void Graph::SetTextToDataPoint(BaseNode* thisNode) {
    // Climb parent tree until the graphLine is reached
    // TO DO Once created, replace this with FindParentShallowID
    BaseNode* pCurrentNode = thisNode;
    while(pCurrentNode->GetShallowID() != "graphLine") pCurrentNode = pCurrentNode->parent;

    // Get data from the line
    Data* pDataNode = (Data*)pCurrentNode->FindShallowID("vectorPositionData");
    int vectorPositionX = *(int*)pDataNode->GetProperty("vectorPositionX").get();
    double vectorPositionY = *(double*)pDataNode->GetProperty("vectorPositionY").get();

    ((Text*)thisNode)->SetText("(%d, %.1f)", vectorPositionX, vectorPositionY);
}

namespace {

    // Update nodes inside a graph in a way that scales everything to fit the graph area
    void UpdateGraphScale(std::vector<double>& rDataVector, Group* pLineContainer, int graphWidth, int graphHeight) {
        // Don't attempt to organize data if there's no data
        if(rDataVector.empty()) return;

        // Calculate extends of data range
        double dataMinValue = *std::min_element(rDataVector.begin(), rDataVector.end());
        double dataMaxValue = *std::max_element(rDataVector.begin(), rDataVector.end());

        // If all data is the same and dividing by the difference will be a division by zero, add a small amount of variability
        if(dataMinValue == dataMaxValue) dataMaxValue++;

        // Loop through most data points and connect the line from one data point to the next
        for(int i = 0; i < rDataVector.size() - 1; i++) {
            double currentValue = rDataVector[i];
            double nextValue = rDataVector[i + 1];
            Line* pCurrentLine = (Line*)pLineContainer->children[i];

            // X coordinate calculated as the index multiplied by the X screen distance of eqully spaced data points
            pCurrentLine->SetX1((i + 0) * ((double)graphWidth / (rDataVector.size() - 1)));
            pCurrentLine->SetX2((i + 1) * ((double)graphWidth / (rDataVector.size() - 1)));
            // Y coordinate calculated like (num - min1) / (max1 - min1) * (max2 - min2) + min2. Maps number from one range to another
            pCurrentLine->SetY1((currentValue - dataMinValue) / (dataMaxValue - dataMinValue) * (-graphHeight) + graphHeight);
            pCurrentLine->SetY2((nextValue - dataMinValue) / (dataMaxValue - dataMinValue) * (-graphHeight) + graphHeight);

            // Give line its own position data
            *(int*)((Data*)pCurrentLine->FindShallowID("vectorPositionData"))->GetProperty("vectorPositionX").get() = i;
            *(double*)((Data*)pCurrentLine->FindShallowID("vectorPositionData"))->GetProperty("vectorPositionY").get() = currentValue;
        }

        // The last Line node does not have a next data point to connect to. Set it separately
        Line* pLastLine = (Line*)pLineContainer->children.back();
        pLastLine->SetX1(graphWidth);
        pLastLine->SetX2(graphWidth);
        pLastLine->SetY1((rDataVector.back() - dataMinValue) / (dataMaxValue - dataMinValue) * (-graphHeight) + graphHeight);
        pLastLine->SetY2((rDataVector.back() - dataMinValue) / (dataMaxValue - dataMinValue) * (-graphHeight) + graphHeight);
        *(int*)((Data*)pLastLine->FindShallowID("vectorPositionData"))->GetProperty("vectorPositionX").get() = pLineContainer->children.size() - 1;
        *(double*)((Data*)pLastLine->FindShallowID("vectorPositionData"))->GetProperty("vectorPositionY").get() = rDataVector.back();
    }

    // Update nodes inside the graph to represent the data
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
        int dotWidth = 6;
        int labelButtonWidth = 15;
        for(int i = 0; i < numDataNodeDifference; i++) {
            pLineContainer->AddChild(
                (new Line)->SetShallowID("graphLine")->SetColor(Color::white)->SetLineWidth(1)->AddChildren({ // TO DO Set shallowID automatically once replaced with changable template
                    // Data for updating the label text
                    (new Data)->SetShallowID("vectorPositionData")->SetProperty("vectorPositionX", std::make_shared<int>())->SetProperty("vectorPositionY", std::make_shared<double>()), // TO DO Also add this automatically
                    // Dot
                    (new Circle)->SetCentered(true)->SetWidth(dotWidth)->SetFillColor(Color::white)->AddChildren({
                        // Toggleable label
                        (new Toggleable)->SetPosition(-labelButtonWidth / 2, -labelButtonWidth / 2)->SetSize(labelButtonWidth, labelButtonWidth)->AddChildren({
                            (new Activated)->AddChildren({
                                // Background
                                (new Rectangle)->SetX(labelButtonWidth)->SetWidth(70)->SetFillColor(Color::gray)->AddChildren({
                                    // Label text
                                    (new Text)->SetText("(x, y)")->SetFontSize(12)->SetAlignments(Text::HorizontalAlign::center, Text::VerticalAlign::middle)->SetOverflow(Text::Overflow::visible)->SetPreTick(Graph::SetTextToDataPoint),
                                }),

                                // Visible part of close button
                                (new Rectangle)->SetFillColor(Color::red),
                            }),
                        }),
                    }),
                })
            );
        }

        // Delete Line nodes if there's less data than lines
        for(int i = 0; i < -numDataNodeDifference; i++) if(!pLineContainer->children.empty()) delete pLineContainer->children[0];

        // TO DO Replace with switch statement once graph fit is actually saved
        if(true) UpdateGraphScale(dataVector, pLineContainer, graphWidth, graphHeight);
    }

};

Group* Graph::CreateGraph(std::shared_ptr<std::vector<double>> dataVector, Fit fit) {
    return (new Group)->SetPreTick(UpdateGraph)->AddChildren({
        (new Data)->SetShallowID("data")->SetProperty("dataVector", dataVector),
        (new Group)->SetShallowID("lineContainer"),
    });
}