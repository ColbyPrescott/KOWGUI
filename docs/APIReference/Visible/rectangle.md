# API Reference: Rectangle Node

The `Rectangle` visible node will draw a rectangle inside the 
node's area.


<br>

This node inherits from [`BaseNode`](./../baseNode.md).
- [SetFillColor](#rectangle-setfillcolor)
- [SetOutlineColor](#rectangle-setoutlinecolor)
- [SetOutlineWidth](#rectangle-setoutlinewidth)

<br>

---

<br>


<a id="rectangle-setfillcolor"></a>
```C++
Rectangle* SetFillColor(std::shared_ptr<Color> fillColor)
```
Set the color that will fill in the rectangle. <br>
Default is `Color::transparent`, making it invisible.

<br>

<a id="rectangle-setoutlinecolor"></a>
```C++
Rectangle* SetOutlineColor(std::shared_ptr<Color> outlineColor)
```
Set the color that will outline and draw around the rectangle. <br>
Default is `Color::transparent`, making it invisible.

<br>

<a id="rectangle-setoutlinewidth"></a>
```C++
Rectangle* SetOutlineWidth(int outlineWidth)
```
Set the width of the outline around the rectangle. <br>
Default is `1` pixel.