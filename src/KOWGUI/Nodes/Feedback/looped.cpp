#include "KOWGUI/Nodes/Feedback/looped.h"

#include "KOWGUI/Nodes/Interactable/toggleable.h"

using namespace KOWGUI;

// Set how many states there are before repetition
Looped* Looped::SetLoopLength(int loopLength) {
    mLoopLength = loopLength;
    return this;
}

// Set the target modulo state that will stop this node from soft disabling
Looped* Looped::SetLoopTarget(int loopTarget) {
    mLoopTargets.clear();
    mLoopTargets.push_back(loopTarget);
    return this;
}

// Set multiple target modulo states that will stop this node from soft disabling
Looped* Looped::SetLoopTargets(std::vector<int> loopTargets) {
    mLoopTargets = loopTargets;
    return this;
}

// Get whether or not this node should soft disable itself based on whether a higher toggleable's number of checks
bool Looped::GetFeedbackState() {
    // Climb tree until a Toggleable node is found
    BaseNode* currentNode = this;
    while(dynamic_cast<Toggleable*>(currentNode) == nullptr) {
        // Return default if top of tree was reached
        if(currentNode->parent == nullptr) return false;
        // Climb to parent node
        currentNode = currentNode->parent; 
    }

    // Return whether or not the toggleable node's number of checks matches any targets within a loop
    for(int i = 0; i < mLoopTargets.size(); i++) if(((Toggleable*)currentNode)->GetClicks() % mLoopLength == mLoopTargets[i]) return true;
    return false;
}