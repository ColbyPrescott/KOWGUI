#include "KOWGUI/BaseNodes/feedbackBaseNode.h"

using namespace KOWGUI;

FeedbackBaseNode* FeedbackBaseNode::SetReversed(bool reversed) {
    mReversed = reversed;
    return this;
}

bool FeedbackBaseNode::GetFeedbackState() {
    return true ^ mReversed; // Bitwise XOR will basically flip the result if mReversed is true
}