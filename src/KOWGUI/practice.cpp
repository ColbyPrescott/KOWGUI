// Goal
// Static
    // Rectangle, 0, 0, 480, 50, white,
        // Text "Random header!" horizontal centered, vertical align middle, black
    // Clickable 100, 100, 50, 50, btnFunc
        // Unfocused - Rectangle gray
        // Focused - Rectangle green
    // Draggable 300, 100, 50, 50, 300, 50, 300, 150
        // Unfocused - Rectangle gray
        // Focused - Rectangle green
        // Custom IconCross, custom property color blue



// 6:10
void Structs() {
    KOWGUI::Static* slide = new KOWGUI::Static({.children = {
        new KOWGUI::Rectangle({.x = 0, .y = 0, .width = 480, .height = 50, .color = KOWGUI::Color::white, .children = {
            new KOWGUI::Text({.text = "Ranodm header!", .horizontalCentering = true, .verticalAlign = KOWGUI::Text::VerticalAlign::center})
        }}),
        new KOWGUI::Clickable({.x = 100, .y = 100, .width = 50, .height = 50, .pressedFunction = btnFunc, .children = {
            new KOWGUI::Unfocused({.children = {new KOWGUI::Rectangle({.color = KOWGUI::Color::gray})}}),
            new KOWGUI:Focused({.children = {new KOWGUI::Rectangle({.color = KOWGUI::Color::greed})}})
        }}),
        new KOWGUI::Draggable({.x = 300, .y = 100, .width = 50, .width = 50, .minX = 300, .minY = 300, .minX = 50, .maxY = 150, .children = {
            new KOWGUI::Unfocused({.children = {new KOWGUI::Rectangle({.color = KOWGUI::Color::gray})}}),
            new KOWGUI::Focused({.children = {new KOWGUI::Rectangle({.color = KOWGUI::Color::green})}}),
            new KOWGUI::Custom({.drawFunction = IconCross, .customProperties = {{"color", KOWGUI::Color::blue}}})
        }})
    }});
}

// 6:19
void Functions() {
    KOWGUI::Static* slide = (new KOWGUI::Static)->AddChildren({
        (new KOWGUI::Rectangle)->SetX(0)->SetY(0)->SetWidth(480)->SetHeight(50)->SetColor(KOWGUI::Color::white)->AddChildren({
            (new KOWGUI::Text)->SetText("Random header!")->SetHorizontalCentering(true)->SetVerticalAlign(KOWGUI::Text::VerticalAlign::center)->SetColor(KOWGUI::Color::black)
        }),
        (new KOWGUI::Clickable)->SetX(100)->SetY(100)->SetWidth(50)->SetHeight(50)->SetPressedFunction(btnFunc)->AddChildren({
            (new KOWGUI::Unfocused)->SetChildren({(new KOWGUI::Rectangle)->SetColor(KOWGUI::Color::gray)}),
            (new KOWGUI::Focused)->SetChildren({(new KOWGUI::Rectangle)->SetColor(KOWGUI::Color::green)})
        }),
        (new KOWGUI::Draggable)->SetX(300)->SetY(100)->SetWidth(50)->SetHeight(50)->SetMinX(300)->SetMinY(50)->SetMaxX(300)->SetMaxY(150).AddChildren({
            (new KOWGUI::Unfocused)->AddChildren({(new KOWGUI::Rectangle)->SetColor(KOWGUI::Color::gray)}),
            (new KOWGUI::Focused)->AddChildren({(new KOWGUI::Rectangle)->SetColor(KOWGUI::Color::green)}),
            (new KOWGUI::Custom)->SetDrawFunction(IconCross)->SetProperty("color", KOWGUI::Color::blue)
        })
    });
}




// There was basically no time difference... Structs probably could've been written a little faster had it been practiced a bit more though.
// Functions feels like you have to press shift and move the cursor around a lot, not completely ideal.
// Structs look a little bit more compressed and readable.
// I think structs win. Functions may still be implemented at a later time as both could be programmed into the same system,
// but I can't spend forever on this project and having two fundamentally different ways to achieve the same results may be difficult
// to learn as someone else trying to figure out the GUI library for the first time!

// CORRECTION!! Those designated initializer structs are a C++20 feature while VEXOS only has libraries imbedded for C++11! 
// I guess... I guess I'm glad to have already thought of a backup solution! Now time to go rewrite the final sketch