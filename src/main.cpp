#include "vex.h"
#include "globalVars.h"

#include "TestGUI/panelManager.h"
#include "TestGUI/sidebar.h"

using namespace vex;

int main() {
    srand(Brain.Timer.systemHighResolution());

    // Files on SD card:
    // "kitty.png" - 240x240 picture
    // "logoSmall.png" - 16x4 picture

    uint32_t timerStart = Brain.Timer.system();


    // // 0ms every time
    // Brain.Screen.setFillColor(color::blue);
    // Brain.Screen.drawRectangle(0, 0, 240, 240);


    // // ~600ms first time after boot, 63ms every time subsequent
    // Brain.Screen.drawImageFromFile("kitty.png", 0, 0);


    // // 40ms when loaded
    // uint8_t buf[100000];
    // Brain.SDcard.loadfile("kitty.png", buf, 100000); // ~600 first time after boot, 32ms every time subsequent
    // Brain.Screen.drawImageFromBuffer(buf, 0, 0, 100000); // 8ms every time


    // // ~600 first time after boot, 27ms every time subsequent
    // uint8_t buf[100000];
    // Brain.SDcard.loadfile("logoSmall.png", buf, 100000); // ~600 first time after boot, 27ms every time subsequent
    // Brain.Screen.drawImageFromBuffer(buf, 20, 20, 100000); // 0ms every time


    // // Transparency test. It does not work. Transparency just shows as black
    // Brain.Screen.setFillColor(color::blue);
    // Brain.Screen.drawRectangle(0, 0, 240, 240);
    // uint8_t buf[100000];
    // Brain.SDcard.loadfile("logoSmall.png", buf, 100000);
    // Brain.Screen.drawImageFromBuffer(buf, 20, 20, 100000);


    // // 0ms every time. Converted at https://notisrac.github.io/FileToCArray/ with code format decimal, treat as binary, not static, not const, data type uint8_t, no PROGMEM
    // uint8_t buf[] = {
    //     137, 80, 78, 71, 13, 10, 26, 10, 0, 0, 0, 13, 73, 72, 68, 82, 
    //     0, 0, 0, 16, 0, 0, 0, 4, 8, 6, 0, 0, 0, 135, 180, 191, 
    //     236, 0, 0, 0, 109, 73, 68, 65, 84, 120, 94, 117, 141, 187, 13, 128, 
    //     48, 12, 68, 207, 97, 146, 236, 3, 243, 80, 167, 163, 128, 49, 105, 25, 
    //     193, 135, 63, 137, 66, 131, 37, 235, 73, 214, 61, 31, 96, 115, 3, 28, 
    //     203, 11, 244, 219, 239, 172, 228, 216, 29, 7, 93, 86, 170, 166, 124, 218, 
    //     18, 194, 7, 234, 217, 193, 210, 106, 208, 36, 181, 232, 148, 65, 201, 118, 
    //     145, 148, 123, 187, 137, 193, 165, 213, 96, 233, 116, 81, 182, 148, 243, 129, 
    //     135, 97, 141, 93, 246, 246, 184, 25, 163, 245, 195, 8, 91, 227, 148, 25, 
    //     183, 23, 90, 13, 93, 88, 46, 58, 68, 108, 0, 0, 0, 0, 73, 69, 
    //     78, 68, 174, 66, 96, 130
    // };
    // Brain.Screen.drawImageFromBuffer(buf, 0, 0, 100000); // 0ms every time


    // // So much testing for a function that doesn't actually resize the picture. Consider this function useless
    // // 0ms every time. Converted with decimal, palette mod 24bit RGB, not static, not const, data type uint32_t, not PROGMEM
    // uint32_t buf[]  = {
    //     0, 15007744, 15007744, 15007744, 16747776, 0, 0, 0, 0, 0, 0, 0, 19711, 19711, 19711, 7798920, 
    //     15007744, 16776958, 15007744, 16747520, 16776960, 16772608, 0, 16772608, 0, 164129, 0, 19711, 16711423, 19711, 7798920, 255, 
    //     15007744, 15008001, 16747520, 16747776, 0, 16772608, 0, 229665, 0, 164129, 0, 19711, 85503, 7798920, 7798920, 0, 
    //     16711680, 16747520, 16747776, 16776960, 0, 16776960, 164129, 65280, 164129, 65280, 0, 255, 7798920, 7798920, 255, 0
    // };
    // Brain.Screen.drawImageFromBuffer(buf, 0, 0, 16, 4);
    // // Brain.Screen.drawImageFromBuffer(buf, 0, 0, 160, 40); // Breaks. Size given must be the original size


    // Testing dynamic allocation  
    int bufSize = Brain.SDcard.size("kitty.png"); // ~600ms first time after boot, 27ms every time subsequent
    // printf("Size: %d\n", bufSize);
    uint8_t buf[bufSize];
    Brain.SDcard.loadfile("kitty.png", buf, bufSize); // ~6ms every time
    Brain.Screen.drawImageFromBuffer(buf, 0, 0, bufSize); // 8ms every time



    uint32_t timerEnd = Brain.Timer.system();
    printf("%dms\n", timerEnd - timerStart);



    /*

    Image::SetSource(std::shared_ptr<ImageBuffer> imageBuffer); // Simply sets interal pointer
    Image::SetSource(std::string filePath); // Creates a new ImageBuffer

    struct ImageBuffer {
        int bufferSize;
        uint8_t buffer[];

        ImageBuffer(int, uint8_t[]);
        ImageBuffer(std::string filePath);
    };

    */




    // InitGUISidebar();

    // InitPanels();

    // numpad = KOWGUI::Keyboard::CreateNumpad(10, 10, 100, 150, true, true, theme.sliderNFocused, theme.buttonNFocused, theme.buttonFocused, theme.lightText);
    // gui.root->AddChild(numpad);

    // keyboard = KOWGUI::Keyboard::CreateKeyboard(KOWGUI::Color::darkSlateGray, theme.buttonNFocused, theme.buttonFocused, theme.lightText);
    // gui.root->AddChild(keyboard);

    // LoadPanel(panels.removalDemo);

    while(true) {

        // gui.Tick();

        // Allow other tasks to run
        this_thread::sleep_for(20);
    }
}
