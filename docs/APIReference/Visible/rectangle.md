<!-- 
virtual BaseNode* SetX(int x);
virtual BaseNode* SetY(int y);
virtual BaseNode* SetPosition(int x, int y);
virtual BaseNode* SetWidth(int width);
virtual BaseNode* SetHeight(int height);
virtual BaseNode* SetSize(int width, int height);
virtual BaseNode* SetID(std::string iD);
virtual BaseNode* SetShallowID(std::string shallowID);
virtual BaseNode* SetPreTick(void (*callback)(BaseNode*));
virtual BaseNode* SetDisabled(bool disabled);

virtual BaseNode* ClearPreTick();

virtual BaseNode* AddChildren(std::vector<BaseNode*> newChildren);

// Add one node under this node, returning the new node
template <typename T>
T* AddChild(T* newChild) {
    LinkChild(newChild);

    return newChild;
}

int GetX();
int CalculateX();
int GetY();
int CalculateY();
int GetWidth();
int CalculateWidth();
int GetHeight();
int CalculateHeight();
std::string GetID();
std::string GetShallowID();
bool GetDisabled();
bool GetRooted();

BaseNode* FindShallowID(std::string shallowID);

void ScheduleDeletion();

Rectangle* SetFillColor(std::shared_ptr<Color> fillColor);
Rectangle* SetOutlineColor(std::shared_ptr<Color> outlineColor);
Rectangle* SetOutlineWidth(int outlineWidth); 
-->

# API Reference: Rectangle Node

The `Rectangle` visible node will draw a rectangle inside the 
node's area. It has a fill color, outline color, and outline 
width. By default, the colors are set to `Color::transparent` 
making it invisible.

<details>
<summary>BaseNode functions</summary>

<br>

```C++
Rectangle* SetX(int x)
```
Set the local X coordinate of the node. <br>
Default is `0`, same position as the parent node.

<br>

```C++
Rectangle* SetY(int y)
```
Set the local Y coordinate of the node. <br>
Default is `0`, same position as the parent node.

<br>

```C++
Rectangle* SetPosition(int x, int y)
```
Shorthand to set both the local X and Y coordinate of the node. 

<br>

```C++
Rectangle* SetWidth(int width)
```
Set the width of the node. <br>
Default is `KOWGUI::undefinedNumber`, which means that width 
is inherited from the parent node.

<br>

```C++
Rectangle* SetHeight(int height)
```
Set the height of the node. <br>
Default is `KOWGUI::undefinedNumber`, which means that height 
is inherited from the parent node.

<br>

```C++
Rectangle* SetSize(int width, int height)
```
Shorthand to set both the width and height of the node.

<br>

```C++
Rectangle* SetID(std::string iD)
```
Set a unique identifier for this node. Attempting to reuse it 
will fail and produce a warning. <br>
This ID system has a fast, constant return time. <br>
See `GUI::FindID(std::string iD)`.


<br>

```C++
Rectangle* SetShallowID(std::string shallowID)
```
Set a reusable identifier for this node. <br>
This ID system has a variable return time dependent on how 
deep the search goes. <br>
See `BaseNode::FindShallowID(std::string shallowID)`.


<br>

---

</details>