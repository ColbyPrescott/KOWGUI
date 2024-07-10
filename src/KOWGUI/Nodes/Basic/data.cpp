#include "KOWGUI/Nodes/Basic/data.h"

#include "vex.h"

#include <iostream>

using namespace KOWGUI;

// Add a custom piece of data to this node
Data* Data::SetProperty(std::string name, std::shared_ptr<void> value) {
    mCustomProperties[name] = value;
    return this;
}

// Get a custom piece of data from this node. 
// This void* must be cast back into the original data type. Returns nullptr if not found
std::shared_ptr<void> Data::GetProperty(std::string name) {
    // Return value if found
    if(mCustomProperties.find(name) != mCustomProperties.end()) return mCustomProperties[name];

    // Otherwise print warning
    std::cerr << "KOWGUI: Could not find custom property " << name << std::endl;
    vex::this_thread::sleep_for(5);
    return nullptr;
}