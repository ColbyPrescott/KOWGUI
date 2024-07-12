#ifndef KOWGUI_GRAPH_PREFAB_H
#define KOWGUI_GRAPH_PREFAB_H

#include "KOWGUI/Nodes/Basic/group.h"

#include <memory>
#include <vector>

namespace KOWGUI {

    enum class GraphFit {
        // scroll,
        scale,
        // overwrite,

    };

    // TO DO Min and max graph Y range
    // TO DO Max number of data points

    namespace Graph {

        Group* CreateGraph(std::shared_ptr<std::vector<double>> dataVector, GraphFit fit = GraphFit::scale); // TO DO Line and dot templates
        // Group* CreateGraph(GraphFit fit = GraphFit::scale); // TO DO

    }
}

#endif