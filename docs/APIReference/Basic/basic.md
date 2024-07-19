# What Are Basic Nodes?

Basic nodes inherit from the `BaseNode` class, providing 
the most bare-bones template for a node. Their processing does 
not require any extra information from `GUI::Tick()` such as 
input position, nor do they need low level access to the processing 
queue such as the soft disabling feature of feedback nodes. 
Any special features of a basic node such as organizing child 
nodes are implemented entirely by overwriting the virtual `BaseNode::Tick()` 
function.

In other words, basic nodes don't always have basic functionality, 
they just don't have as clear of a generizable purpose. Visible 
nodes are visible, interactable nodes react to input, and feedback 
nodes react to interactable nodes, but basic nodes could be 
anything. 