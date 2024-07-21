# API Reference: Rectangle Node

The `Rectangle` visible node will draw a rectangle inside the 
node's area.

<details>
<summary>BaseNode functions</summary>

<br>

### `Rectangle* SetX(int x)`
Set the local X coordinate of the node. <br>
Default is `0`, same position as the parent node.

<br>

### `Rectangle* SetY(int y)`
Set the local Y coordinate of the node. <br>
Default is `0`, same position as the parent node.

<br>

### `Rectangle* SetPosition(int x, int y)`
Shorthand to set both the local X and Y coordinate of the node. 

<br>

### `Rectangle* SetWidth(int width)`
Set the width of the node. <br>
Default is `KOWGUI::undefinedNumber`, which means that width 
is inherited from the parent node.

<br>

### `Rectangle* SetHeight(int height)`
Set the height of the node. <br>
Default is `KOWGUI::undefinedNumber`, which means that height 
is inherited from the parent node.

<br>

### `Rectangle* SetSize(int width, int height)`
Shorthand to set both the width and height of the node.

<br>

### `Rectangle* SetID(std::string iD)`
Set a unique identifier for the node. Attempting to reuse it 
will fail and produce a warning. <br>
This ID system has a fast, constant return time. <br>
See `GUI::FindID(std::string iD)`.

<br>

### `Rectangle* SetShallowID(std::string shallowID)`
Set a reusable identifier for the node. <br>
This ID system has a variable return time dependent on how 
deep the search goes. <br>
See [`BaseNode::FindShallowID(std::string shallowID)`](#basenode-findshallowidstdstring-shallowid).

<br>

### `Rectangle* SetPreTick(void (*callback)(BaseNode*))`
Set a custom function to call before any other processing on 
the node. <br>
Function must take a `BaseNode*` as a parameter, which is a 
pointer to the node that called it.

<br>

### `Rectangle* SetDisabled(bool disabled)`
Set whether or not this and child nodes should be processed 
during `GUI::Tick()`.

<br>

### `Rectangle* ClearPreTick()`
Remove the node's custom pre-tick function after calling `BaseNode::SetPreTick(void (*callback)(BaseNode*))`

<br>

### `Rectangle* AddChildren(std::vector<BaseNode*> newChildren)`
Set a list of nodes to be children of this node.

<br>

### `template <typename T> T* AddChild(T* newChild)`
Set a single node to be the child of this node. <br>
Unlike most other functions, this will return a pointer to 
the child node instead of this node. If you need to add a single 
child but return this node, call `BaseNode::AddChildren(std::vector<BaseNode*> newChildren)` 
with a list of only one node. 

<br>

### `int GetX()`
Get the local X coordinate of the node.

<br>

### `int CalculateX()`
Get the global X coordinate of the node, a calculation of summing 
this and all parent node local positions.

<br>

### `int GetY()`
Get the local Y coordinate of the node.

<br>

### `int CalculateY()`
Get the global Y coordinate of the node, a calculation of summing 
this and all parent node local positions.

<br>

### `int GetWidth()`
Get the node's internal width variable. <br>
If never set, it will be `KOWGUI::undefinedNumber`. <br>
Not the correct function for most applications. See [`BaseNode::CalculateWidth()`](#int-calculatewidth).

<br>

### `int CalculateWidth()`
Get the node's width on screen, whether stored itself or inherited.

<br>

### `int GetHeight()`
Get the node's internal height variable. <br>
If never set, it will be `KOWGUI::undefinedNumber`. <br>
Not the correct function for most applications. See [`BaseNode::CalculateHeight()`](#int-calculateheight).

<br>

### `int CalculateHeight()`
Get the node's height on screen, whether stored itself or inherited.

<br>

### `std::string GetID()`
Get the ID of the node. <br>
To find a node from an ID, see `GUI::FindID(std::string iD)`.

<br>

### `std::string GetShallowID()`
Get the shallow ID of the node. <br>
To find a node from a shallow ID, see [`BaseNode::FindShallowID(std::string iD)`](#basenode-findshallowidstdstring-shallowid).

<br>

### `bool GetDisabled()`
Get whether or not the node is disabled. That is, whether or 
not it and its children are processed during `GUI::Tick()`.

<br>

### `bool GetRooted()`
Get whether or not the node is rooted. That is, whether or 
not following parent nodes and climbing up the node tree will 
eventually lead to the node of `GUI::root`. <br>
Nodes must be rooted in order for them to be processed during 
`GUI::Tick()` and retrievable from `GUI::FindID(std::string iD)`.

<br>

### `BaseNode* FindShallowID(std::string shallowID)`
Search through child nodes and return the first result with 
a matching shallow ID. <br>
Search time is dependent on child depth, looking first for 
direct children, then children of children, etc. 

<br>


### `void ScheduleDeletion()`
Flag the node to be safely deleted when it is next processed. <br>
On a node that is not rooted, simply use the `delete` keyword 
instead. 

<br>

---

</details>

<br>

### `Rectangle* SetFillColor(std::shared_ptr<Color> fillColor)`
Set the color that will fill in the rectangle. <br>
Default is `Color::transparent`, making it invisible.

<br>

### `Rectangle* SetOutlineColor(std::shared_ptr<Color> outlineColor)`
Set the color that will outline and draw around the rectangle. <br>
Default is `Color::transparent`, making it invisible.

<br>

### `Rectangle* SetOutlineWidth(int outlineWidth)`
Set the width of the outline around the rectangle. <br>
Default is `1` pixel.