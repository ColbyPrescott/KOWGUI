#ifndef KOWGUI_GRAPH_PREFAB_H
#define KOWGUI_GRAPH_PREFAB_H

#include "KOWGUI/Nodes/Basic/group.h"

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

        Group* CreateGraph(std::shared_ptr<std::vector<double>> dataVector, Fit fit = Fit::scale); // TO DO Line and dot templates
        // Group* CreateGraph(Fit fit = Fit::scale); // TO DO

    }
}

#endif