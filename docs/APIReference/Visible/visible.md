# What Are Visible Nodes?

Visible nodes inherit from the `VisibleBaseNode` class, providing 
`BaseNode` functionality as well as a function to draw itself 
to the screen. This function is called automatically during 
`GUI::Tick()` in the back to front pass so that nodes defined 
last at the bottom of the node tree are rendered above nodes 
defined first at the top of the node tree. In other words, 
child nodes render on top of their parent.