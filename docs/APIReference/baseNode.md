# API Documentation: BaseNode

`BaseNode` is not a node itself and should not be used as one; 
it is instead the class that all nodes inherit from. It contains 
essential functions and variables that all nodes need to work, 
such as position and ID systems. When a pointer needs to reference 
any node type, polymorphism allows `BaseNode*` to be used, 
later casted once the specific functionality is known.

Functions with a return type of `[this]` are rewritten in derived 
node classes to return the type of the derived node instead 
of `BaseNode`. 

<br>

<a id="basenode-setx"></a>
```C++
[this]* SetX(int x)
```
Set the local X coordinate of the node. <br>
Default is `0`, same position as the parent node.

<br>

<a id="basenode-sety"></a>
```C++
[this]* SetY(int y)
```
Set the local Y coordinate of the node. <br>
Default is `0`, same position as the parent node.

<br>

<a id="basenode-setposition"></a>
```C++
[this]* SetPosition(int x, int y)
```
Shorthand to set both the local X and Y coordinate of the node. 

<br>

<a id="basenode-setwidth"></a>
```C++
[this]* SetWidth(int width)
```
Set the width of the node. <br>
Default is `KOWGUI::undefinedNumber`, which means that width 
is inherited from the parent node.

<br>

<a id="basenode-setheight"></a>
```C++
[this]* SetHeight(int height)
```
Set the height of the node. <br>
Default is `KOWGUI::undefinedNumber`, which means that height 
is inherited from the parent node.

<br>

<a id="basenode-setsize"></a>
```C++
[this]* SetSize(int width, int height)
```
Shorthand to set both the width and height of the node.

<br>

<a id="basenode-setid"></a>
```C++
[this]* SetID(std::string iD)
```
Set a unique identifier for the node. Attempting to reuse it 
will fail and produce a warning. <br>
This ID system has a fast, constant return time. <br>
See `GUI::FindID(...)`.

<br>

<a id="basenode-setshallowid"></a>
```C++
[this]* SetShallowID(std::string shallowID)
```
Set a reusable identifier for the node. <br>
This ID system has a variable return time dependent on how 
deep the search goes. <br>
See [`BaseNode::FindShallowID(...)`](#basenode-findshallowid).

<br>

<a id="basenode-setpretick"></a>
```C++
[this]* SetPreTick(void (*callback)(BaseNode*))
```
Set a custom function to call before any other processing on 
the node. <br>
Function must take a `BaseNode*` as a parameter, which is a 
pointer to the node that called it.

<br>

<a id="basenode-setdisabled"></a>
```C++
[this]* SetDisabled(bool disabled)
```
Set whether or not this and child nodes should be processed 
during `GUI::Tick()`.

<br>

<a id="basenode-clearpretick"></a>
```C++
[this]* ClearPreTick()
```
Remove the node's custom pre-tick function after calling [`BaseNode::SetPreTick(...)`](#basenode-setpretick)

<br>

<a id="basenode-addchildren"></a>
```C++
[this]* AddChildren(std::vector<BaseNode*> newChildren)
```
Set a list of nodes to be children of this node.

<br>

<a id="basenode-addchild"></a>
```C++
template <typename T>
T* AddChild(T* newChild)
```
Set a single node to be the child of this node. <br>
Unlike most other functions, this will return a pointer to 
the child node instead of this node. If you need to add a single 
child but return this node, call [`BaseNode::AddChildren(...)`](#basenode-addchildren) 
with a list of only one node. 

<br>

<a id="basenode-getx"></a>
```C++
int GetX()
```
Get the local X coordinate of the node.

<br>

<a id="basenode-calculatex"></a>
```C++
int CalculateX()
```
Get the global X coordinate of the node, a calculation of summing 
this and all parent node local positions.

<br>

<a id="basenode-gety"></a>
```C++
int GetY()
```
Get the local Y coordinate of the node.

<br>

<a id="basenode-calculatey"></a>
```C++
int CalculateY()
```
Get the global Y coordinate of the node, a calculation of summing 
this and all parent node local positions.

<br>

<a id="basenode-getwidth"></a>
```C++
int GetWidth()
```
Get the node's internal width variable. <br>
If never set, it will be `KOWGUI::undefinedNumber`. <br>
Not the correct function for most applications. See [`BaseNode::CalculateWidth()`](#basenode-calculatewidth).

<br>

<a id="basenode-calculatewidth"></a>
```C++
int CalculateWidth()
```
Get the node's width on screen, whether stored itself or inherited.

<br>

<a id="basenode-getheight"></a>
```C++
int GetHeight()
```
Get the node's internal height variable. <br>
If never set, it will be `KOWGUI::undefinedNumber`. <br>
Not the correct function for most applications. See [`BaseNode::CalculateHeight()`](#basenode-calculateheight).

<br>

<a id="basenode-calculateheight"></a>
```C++
int CalculateHeight()
```
Get the node's height on screen, whether stored itself or inherited.

<br>

<a id="basenode-getid"></a>
```C++
std::string GetID()
```
Get the ID of the node. <br>
To find a node from an ID, see `GUI::FindID(...)`.

<br>

<a id="basenode-getshallowid"></a>
```C++
std::string GetShallowID()
```
Get the shallow ID of the node. <br>
To find a node from a shallow ID, see [`BaseNode::FindShallowID(...)`](#basenode-findshallowid).

<br>

<a id="basenode-getdisabled"></a>
```C++
bool GetDisabled()
```
Get whether or not the node is disabled. That is, whether or 
not it and its children are processed during `GUI::Tick()`.

<br>

<a id="basenode-getrooted"></a>
```C++
bool GetRooted()
```
Get whether or not the node is rooted. That is, whether or 
not following parent nodes and climbing up the node tree will 
eventually lead to the node of `GUI::root`. <br>
Nodes must be rooted in order for them to be processed during 
`GUI::Tick()` and retrievable from `GUI::FindID(...)`.

<br>

<a id="basenode-findshallowid"></a>
```C++
BaseNode* FindShallowID(std::string shallowID)
```
Search through child nodes and return the first result with 
a matching shallow ID. <br>
Search time is dependent on child depth, looking first for 
direct children, then children of children, etc. 

<br>

<a id="basenode-scheduledeletion"></a>
```C++
void ScheduleDeletion()
```
Flag the node to be safely deleted when it is next processed. <br>
On a node that is not rooted, simply use the `delete` keyword 
instead. 