// KOWGUI files
namespace KOWGUI {

    struct buttonParameters {
        int x = 0;
        int y = 0;
        int width = 0;
        int height = 0;
        void (*pClickFunc)() = nullptr;
        KOWGUI::Color fillColor = KOWGUI::Color::transparent;
        KOWGUI::Color outlineColor = KOWGUI::Color::transparent;
        std::string text = "";
    };

}


// GUI outline file
enum SlideNames {
    home
};

enum SlideHomeElements {
    testRectangle
};


// Global variable file or main.cpp or something
KOWGUI::GUI gui;


// Individual slide files
void CreateHomeSlide() {
    gui.slides[home] = gui.CreateSlide();

    gui.slides[home][testRectangle] = gui.CreateRectangle({
        .x = 50, 
        .y = 50,
        .width = 200,
        .height = 150,
        .fillColor = gui.CreateColor(50, 200, 50)
    });

    gui.slides[home][testRectangle].text = "Late text!";
}