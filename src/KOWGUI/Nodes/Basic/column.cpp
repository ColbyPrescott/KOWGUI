#include "KOWGUI/Nodes/Basic/column.h"

#include <math.h>

using namespace KOWGUI;

// Set number of pixels between child nodes
Column* Column::SetSpacing(int spacing) {
    mSpacing = spacing;
    return this;
}

// Set whether or not child nodes should be equally scaled to fit within this node's height 
Column* Column::SetScaleToFit(bool scaleToFit) {
    mScaleToFit = scaleToFit;
    return this;
}



// Organize children one after the other such that a taller node will push the next farther down
void Column::OrganizeUnique() {
    // Keep track of where the current node is being positioned
    int currentY = 0;

    // Keep track of widest node's width
    int maxWidth = 0;

    // Loop through all child nodes
    for(int i = 0; i < children.size(); i++) {
        // Ignore node if disabled
        if(children[i]->GetDisabled()) continue;
        // Set position of child node
        children[i]->SetY(currentY);
        // Add child node's height to the sum
        currentY += children[i]->CalculateHeight();
        // Additionally add the spacing to the sum
        currentY += mSpacing;
        // Increase note of widest width if wider
        if(children[i]->CalculateWidth() > maxWidth) maxWidth = children[i]->CalculateWidth();
    }

    // Update this node's size to contain everything inside
    SetHeight(currentY - mSpacing);
    SetWidth(maxWidth);
}

// Organize children one after the other, equally scaling all of them to fit within this node's height
void Column::OrganizeUniform() {
    // Get number of nodes that are supposed to fit within this node's height
    int numEnabledChildren = 0;
    // Loop through each node and increment count if not disabled
    for(int i = 0; i < children.size(); i++) if(!children[i]->GetDisabled()) numEnabledChildren++;

    // Prevent a division by zero error
    if(numEnabledChildren == 0) return;

    // Calculate what size each child node should be. Amount of total space is removed from total height, which is then divided by number of child nodes
    int nodeHeight = round((CalculateHeight() - mSpacing * (numEnabledChildren - 1)) / (double)numEnabledChildren);


    // Keep track of where the current node is being positioned
    int currentY = 0;

    // Loop through all child nodes, updating their height and position
    for(int i = 0; i < children.size(); i++) {
        // Ignore node if disabled
        if(children[i]->GetDisabled()) continue;
        // Update child node height
        children[i]->SetHeight(nodeHeight);
        // Update child node position
        children[i]->SetY(currentY);
        // Add to currentY for next enabled node
        currentY += nodeHeight + mSpacing;
    }
}

// Organize all child nodes into a column
void Column::Tick() {
    if(mScaleToFit) OrganizeUniform();
    else OrganizeUnique();
}