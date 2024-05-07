#ifndef KOWGUI_FEEDBACK_BASE_NODE_H
#define KOWGUI_FEEDBACK_BASE_NODE_H

#include "KOWGUI/BaseNodes/baseNode.h"

namespace KOWGUI {

    // Node that will soft disable itself based on some property, usually based on the closest interactable node up the tree
    class FeedbackBaseNode : public BaseNode {
        protected:
            // TO DO mReversed -> mInverted --- Actually no replace inverted feedback nodes with NName
            bool mReversed = false;

        public:
            virtual FeedbackBaseNode* SetReversed(bool reversed);

            virtual bool GetFeedbackState();
    };

}

#endif