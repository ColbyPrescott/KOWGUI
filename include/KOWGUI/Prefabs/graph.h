#ifndef KOWGUI_GRAPH_PREFAB_H
#define KOWGUI_GRAPH_PREFAB_H

#include "KOWGUI/BaseNodes/baseNode.h"
#include "KOWGUI/Nodes/Basic/group.h"
#include "KOWGUI/Nodes/Visible/line.h"

#include <memory>
#include <vector>

namespace KOWGUI {


    // TO DO Min and max graph Y range
    // TO DO Max number of data points

    namespace Graph {
        
        enum class Fit {
            // scroll,
            scale,
            // overwrite,

        };

        void SetTextToDataPoint(BaseNode* thisNode);
        Line* CreateDefaultGraphLine();

        Group* CreateGraph(std::shared_ptr<std::vector<double>> dataVector, Fit fit = Fit::scale, Line* (*linePrefab)(void) = CreateDefaultGraphLine); // TO DO I like this not having "custom" before linePrefab. Do the same with colors on the Keyboard?
        // Group* CreateGraph(Fit fit = Fit::scale); // TO DO

    }
}

#endif