// Global variable file or main.cpp or something
KOWGUI::GUI gui;


// Individual slide files
void CreateHomeSlide() {
    gui.slides.home = KOWGUI::Slide();

    gui.slides.home.testButton = KOWGUI::Button(
        50, // X
        50, // Y
        200, // Width
        150, // Height
        RandomFunction, // Click function
        "Click me", // Text to display
        KOWGUI::Color(50, 200, 50), // Fill color
        KOWGUI::Color::transparent // Outline color
    )
}