# API Reference: Circle Node

The `Circle` visible node will draw a circle inside the node's 
area. Ellipses are not supported, so diameter is determined 
by the node's width alone.


<br>

This node inherits from [`BaseNode`](./../baseNode.md).
- [SetCentered](#circle-setcentered)
- [SetFillColor](#circle-setfillcolor)
- [SetOutlineColor](#circle-setoutlinecolor)
- [SetOutlineWidth](#circle-setoutlinewidth)
- [SetRadius](#circle-setradius)

<br>

---

<br>


<a id="circle-setcentered"></a>
```C++
[this]* SetCentered(bool centered)
```
Set whether or not the node's position is the center of the 
circle instead of the top left corner like most other nodes. <br>
Default is `false`, making it draw the circle from the top 
left corner.

<br>

<a id="circle-setfillcolor"></a>
```C++
[this]* SetFillColor(std::shared_ptr<Color> fillColor)
```
Set the color that will fill in the circle. <br>
Default is `Color::transparent`, making it invisible.

<br>

<a id="circle-setoutlinecolor"></a>
```C++
[this]* SetOutlineColor(std::shared_ptr<Color> outlineColor)
```
Set the color that will outline and draw around the circle. <br>
Default is `Color::transparent`, making it invisible.

<br>

<a id="circle-setoutlinewidth"></a>
```C++
[this]* SetOutlineWidth(int outlineWidth)
```
Set the width of the outline around the circle. <br>
Default is `1` pixel.

<br>

<a id="circle-setradius"></a>
```C++
[this]* SetRadius(int radius)
```
Set the width of the node based on radius. <br>
If diameter is intended, see [`BaseNode::SetWidth(...)`](./../baseNode.md#basenode-setwidth)