#include "KOWGUI/Prefabs/graph.h"

#include "KOWGUI/kowgui.h"

#include <bits/stdc++.h>

using namespace KOWGUI;

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
        }

        // The last Line node does not have a next data point to connect to. Set it separately
        Line* pLastLine = (Line*)pLineContainer->children.back();
        pLastLine->SetX1(graphWidth);
        pLastLine->SetX2(graphWidth);
        pLastLine->SetY1((rDataVector.back() - dataMinValue) / (dataMaxValue - dataMinValue) * (-graphHeight) + graphHeight);
        pLastLine->SetY2((rDataVector.back() - dataMinValue) / (dataMaxValue - dataMinValue) * (-graphHeight) + graphHeight);
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
        for(int i = 0; i < numDataNodeDifference; i++) {
            pLineContainer->AddChild(
                (new Line)->SetColor(Color::white)->SetLineWidth(1)->AddChildren({
                    (new Circle)->SetCentered(true)->SetWidth(6)->SetFillColor(Color::white)->AddChildren({
                        // TO DO Experimental labels on graph points
                        // (new Toggleable)->SetPosition(-5, -5)->SetSize(10, 10)->AddChildren({
                        //     (new Activated)->AddChildren({
                        //         (new Rectangle)->SetX(10)->SetSize(70, 20)->SetFillColor(Color::gray)->AddChildren({
                        //             (new Text)->SetText("(x, y)")->SetFontSize(18)->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetOverflow(Overflow::visible),
                        //         }),

                        //         (new Rectangle)->SetFillColor(Color::red),
                        //     }),
                        // }),
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