#include "KOWGUI/Nodes/Basic/row.h"

#include <math.h>

using namespace KOWGUI;

// Set number of pixels between child nodes
Row* Row::SetSpacing(int spacing) {
    mSpacing = spacing;
    return this;
}

// Set whether or not child nodes should be equally scaled to fit within this node's width 
Row* Row::SetScaleToFit(bool scaleToFit) {
    mScaleToFit = scaleToFit;
    return this;
}



// Organize children one after the other such that a wider node will push the next farther right
void Row::OrganizeUnique() {
    // Keep track of where the current node is being positioned
    int currentX = 0;

    // Keep track of tallest node's height
    int maxHeight = 0;

    // TO DO I'm going to guess that disabling a node inside a row won't take it out of the calculations... should it be taken out?

    // Loop through all child nodes
    for(int i = 0; i < children.size(); i++) {
        // Set position of child node
        children[i]->SetX(currentX);
        // Add child node's width to the sum
        currentX += children[i]->CalculateWidth();
        // Additionally add the spacing to the sum
        currentX += mSpacing;
        // Increase note of tallest height if taller
        if(children[i]->CalculateHeight() > maxHeight) maxHeight = children[i]->CalculateHeight();
    }

    // Update this node's size to contain everything inside
    SetWidth(currentX - mSpacing);
    SetHeight(maxHeight);
}

// Organize children one after the other, equally scaling all of them to fit within this node's width
void Row::OrganizeUniform() {
    // Get number of nodes that are supposed to fit within this node's width
    int numChildren = children.size();

    // Calculate what size each child node should be. Amount of total space is removed from total width, which is then divided by number of child nodes
    int nodeWidth = round((CalculateWidth() - mSpacing * (numChildren - 1)) / (double)numChildren);

    // Loop through all child nodes, updating their width and position
    for(int i = 0; i < numChildren; i++) {
        children[i]->SetWidth(nodeWidth);
        children[i]->SetX((nodeWidth + mSpacing) * i);
    }
}

// Organize all child nodes into a row
void Row::Tick() {
    if(mScaleToFit) OrganizeUniform();
    else OrganizeUnique();
}