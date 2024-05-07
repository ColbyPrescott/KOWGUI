#ifndef KOWGUI_FEEDBACK_BASE_NODE_H
#define KOWGUI_FEEDBACK_BASE_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    // Node that will soft disable itself based on some property, usually based on the closest interactable node up the tree
    class FeedbackBaseNode : public BaseNode {
        public:
            virtual bool GetFeedbackState() {return false;}
    };

}

#endif