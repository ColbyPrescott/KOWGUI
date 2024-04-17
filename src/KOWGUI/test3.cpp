// GUI outline file
enum SlideNames {
    home
};

enum SlideHomeElements {
    testButton,
    testSlider
};



// Global variable file or main.cpp or something
KOWGUI::GUI gui;

struct {
    interactable: KOWGUI::Color(50, 200, 50),
    secondary: KOWGUI::Color(50, 50, 50)
} theme;

// Individual slide files
void CreateHomeSlide() {
    gui.slides[home] = gui.CreateSlide();

    gui.slides[home][testButton] = gui.CreateTransformNodeEmptyBaseStatic(50, 50, {
        gui.CreateRectangle(0, 0, 200, 150, KOWGUI::Color::HueShift(KOWGUI::Color::green, 90)),
        // X, Y, Text, horizontal wrapping width, center horizontal, center vertical, padding four sides
        gui.CreateText(0, 0, "Click me", 200, true, true, 10, 10, 10, 10),
        gui.CreateClickable(0, 0, 200, 150, clickDownFunction, clickUpFunction)
    });


    gui.slides[home][testSlider] = gui.CreateStatic(200, 100, {
        // Color passed by reference
        gui.CreateRectangle(-100, -20, 200, 40, theme.secondary),
        // X, Y, Interactable width, Interactable height, Min X, Min Y, Max X, Max Y, Called when drag starts, Function to call when position changed, Called when input is removed, children elements
        gui.CreateDraggable(-25, -25, 50, 50, -100, -25, 100, -25, clickDownFunction, dragFunction, clickUpFunction, maybeSomehowPointerToRectangleObjectToDimWhenDragging, {
            gui.CreateRectangle(0, 0, 50, 50, theme.interactable),
            gui.CreateCustom(0, 0, 50, 50, customDrawFunction),
            gui.CreateImage(0, -100, "/thisIsOnSDCard/images/duck.png", "specificID")
        })
    });

    gui.slides[home][testSlider].Get(KOWGUI::ElementType::draggable)[0].Get(KOWGUI::ElementType::rectangle)[0].outlineColor = new KOWGUI::Color("#ffffff");

    gui.GetID("specificID").source = &randomImageBuffer;
    gui.GetID("specificID").SetSource(&randomImageBuffer); // Or
}