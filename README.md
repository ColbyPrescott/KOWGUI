# This project is **<u>IN PROGRESS</u>**
### Version 1.0.0 will be released... soon. Currently decently busy with school stuff
<br><br>

# KOWGUI

KOWGUI is a simple yet powerful Graphical User Interface library 
for the VEX V5 API. It uses basic nodes to create complex systems 
like Godot, and can arrange code in a compact manner like HTML.

Out-of-the-box systems range from as simplistic and customizable as rectangles and click detectors to as complicated as a terminal-integrated keyboard and graphs!

## Documentation

- [Installation](./docs/installation.md)
- [API Reference](./docs/APIReference/apiReference.md)

## Utility examples

- **Autonomous selection** <br>
    While placing robots on the field, on-screen buttons are 
    a fast and easy way to select an autonomous routine.
- **Seeing real-time data** <br>
    Being able to see data in a visual form makes it easier 
    to process meaning, quicker to see exact results, and it 
    looks professional in an Engineering Notebook*. <br>
    <sup><sub>* VEX VSCode Extension can screenshot the V5 
    Robot Brain, making a .png file to copy or print into a 
    notebook</sub></sup>
- **Faster tuning** <br>
    While building and testing robots, adjusting values directly 
    on the V5 Robot Brain can eliminate the time to edit and 
    download programs, accelerating the tuning of motor velocities, 
    PID controller values, and any other precise value.
- **Building applications** <br>
    If you want to develop screen-related tools for the V5 Robot 
    Brain, KOWGUI is an excellent base for flexible designs.

## Fundamentals

### Node-based

KOWGUI is a node-based system in which every node has a very 
specific purpose like drawing text to the screen or detecting 
user input in a specified area. Each node is listed as the 
child of another, inheriting position and size unless stated 
otherwise. Therefore, a button is not a designated *button 
node* but is instead one or more visible nodes (such as a `Rectangle` 
and `Text` node) parented to a `Clickable` node. 

### Code layout

After much designing and testing throughout KOWGUI development, 
and also being biased from previous web development experience, 
I recommend defining nodes in a condensed manner similar to 
HTML: 

```C++
// Functions separated from GUI layout
void ButtonFunction(BaseNode* thisNode) {
    printf("Pressed the button!\n");
}

// GUI layout created in one large tree structure
void InitGUIExampleButton() {
    gui.root->AddChild(
        (new Clickable)->SetPosition(50, 50)->SetSize(200, 100)->SetRelease(ButtonFunction)->AddChildren({
            // Background
            (new Rectangle)->SetFillColor(Color::lime),
            // Description
            (new Text)->SetText("Click")->SetAlignments(HorizontalAlign::center, VerticalAlign::middle)->SetOverflow(Overflow::wrapScale),
        })
    );
}
```

However, being built on pointers allows the code to be written 
in many different ways. If you have experience with LVGL, a 
more verbose layout may be comfortable.

```C++
// Functions separated from GUI layout
void ButtonFunction(BaseNode* thisNode) {
    printf("Pressed the button!\n");
}

// GUI layout created by defining one node at a time
void InitGUIExampleButton() {
    Clickable* button = new Clickable;
    gui.root->AddChild(button);
    button->SetPosition(50, 50);
    button->SetSize(200, 100);
    button->SetRelease(ButtonFunction);

    Rectangle* background = new Rectangle;
    button->AddChild(background);
    background->SetFillColor(Color::lime);

    Text* description = new Text;
    button->AddChild(description);
    description->SetText("Click");
    description->SetHorizontalAlignment(HorizontalAlignment::center);
    description->SetVerticalAlignment(VerticalAlignment::middle);
    description->SetOverflow(Overflow::wrapScale);
}
```

The only rules for layout is that nodes must have their memory 
allocated with the `new` keyword, and nodes must be eventually 
connected to the root node for processing or be removed with 
the `delete` keyword.

Using `delete` on an already rooted node can potentially throw 
a wrench into frame processing. To safely delete a node that 
has already been rooted, call its `ScheduleDeletion()` function.

## Contributing

Currently, KOWGUI is a passion project that I enjoy working 
on by myself. I am also unsure how contributions in GitHub 
work. If you think of a feature or change you'd like, create 
a new issue and, so long as it's reasonable, I will do my best 
to implement it. Feel free to modify the source code for your 
own projects and fork this repository, but I can not guarantee 
that I will add any of your own changes.

This status is not permanent. It may change as I become busy 
with different projects, lose interest, or perhaps when I graduate 
from high school and lose access to the VEX V5 Robot Brain 
needed to continue development. For now, however, I enjoy being 
a solo developer!