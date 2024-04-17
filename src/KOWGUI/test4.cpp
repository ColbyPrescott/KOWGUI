// Global variable file or main.cpp or something
KOWGUI::GUI gui;

struct {
    KOWGUI::Static* home = nullptr;
    KOWGUI::Static* other = nullptr;
} userDefinedSlidesCustomNameWhatever;

// Individual slide files
void CreateHomeSlide() {
    // One tree structure with an AddNodes function
    userDefinedSlidesCustomNameWhatever.home = gui.root.AddNodes({
        KOWGUI::Static({.id = "slideHome", .x = 0, .y = 0, .disabled = true}).AddNodes({
            KOWGUI::Text({
                .x = 50, .y = 50, 
                .text = "Random text!", 
                .font = vex::fontType::prop20,
                .verticalAlign = "center",
                .color = KOWGUI::Color::white
            }),
            KOWGUI::Clickable({
                .id = "birthdayButton",
                .x = 200, .y = 100, 
                .width = 50, .height = 50, 
                .unpressedChildNodeIndex = 0, .pressedChildNode = "pressedNode",
                .onRelease = [](){UserFunctionToDisableEveryQuoteSlideThenEnableThisOne(userDefinedSlidesCustomNameWhatever.other);}
            }).AddNodes({
                // Node will ask parent for size if not provided. Position already defaulted to 0 is also relative to parent
                KOWGUI::Rectangle({.color = KOWGUI::Color::gray}),
                KOWGUI::Rectangle({.color = KOWGUI::Color::green, .localImmidiateShallowId = "pressedNode"}),
                KOWGUI::Custom({
                    .drawFunction = customFunctionThatWillBeCalledWithReferenceToThisObject
                }).SetProperty("color", KOWGUI::Color::white)
            })
        })
    });

    gui.GetID("birthdayButton").GetLocalID("pressedNode").children[0].color = KOWGUI::Color::red.HueShift(50);



    // Another tree structure with children objects defined in struct section (COMPRESSED)
    userDefinedSlidesCustomNameWhatever.other = gui.root.AddNode({
        new KOWGUI::Static({.x = 0, .y = 0, .disabled = true, .children = {
            new KOWGUI::Text({.x = 50, .y = 50, .text = "Random text!", .font = vex::fontType::prop20, .verticalAlign = "center", .color = KOWGUI::Color::white}),
            new KOWGUI::Clickable({.x = 200, .y = 100, .width = 50, .height = 50, .children = {
                new KOWGUI::Clickable::Unpressed({.children = {new KOWGUI::Rectangle({.color = KOWGUI::Color::gray})}}),
                new KOWGUI::Clickable::Pressed({.children = {new KOWGUI::Rectangle({.color = KOWGUI::Color::green})}}),
                new KOWGUI::Custom({.drawFunction = customFunctionThatWillBeCalledWithReferenceToThisObject, .customProperties = {{"color", KOWGUI::Color::black}}})
            }})
        }})
    });

    // Another tree structure with children objects defined in struct section (UNCOMPRESSED)
    userDefinedSlidesCustomNameWhatever.other = gui.root.AddNodes({
        new KOWGUI::Static({
            .x = 0, .y = 0, 
            .disabled = true, 
            .children = {
            new KOWGUI::Text({
                .x = 50, .y = 50, 
                .text = "Random text!", 
                .font = vex::fontType::prop20,
                .verticalAlign = "center",
                .color = KOWGUI::Color::white
            }),
            new KOWGUI::Clickable({
                .x = 200, .y = 100, 
                .width = 50, .height = 50, 
                .children = {
                new KOWGUI::Clickable::Unpressed({.children = {new KOWGUI::Rectangle({.color = KOWGUI::Color::gray})}}),
                new KOWGUI::Clickable::Pressed({.children = {new KOWGUI::Rectangle({.color = KOWGUI::Color::green})}}),
                new KOWGUI::Custom({
                    .drawFunction = customFunctionThatWillBeCalledWithReferenceToThisObject,
                    .customProperties = {{"color", KOWGUI::Color::black}}
                })
            }})
        }})
    });



    // Another tree structure with function setters instad of structs (COMPRESSED)
    userDefinedSlidesCustomNameWhatever.other = gui.root.AddChild((new KOWGUI::Static)->SetX(0)->SetY(0)->SetDisabled(true)->AddChildren({
        (new KOWGUI::Text)->SetX(50)->SetY(50)->SetText("Random text!")->SetFont(vex::fontType::prop20)->SetVerticalAlign(KOWGUI::Text::VerticalAlign::center)->SetColor(KOWGUI::Color::white),
        (new KOWGUI::Clickable)->SetX(200)->SetY(100)->SetWidth(50)->SetHeight(50)->AddChildren({
            (new KOWGUI::Unfocused)->AddChildren({(new KOWGUI::Rectangle).SetColor(KOWGUI::Color::gray)}),
            (new KOWGUI::Focused)->AddChildren({(new KOWGUI::Rectangle).SetColor(KOWGUI::Color::green)}),
            (new KOWGUI::Custom)->SetDrawFunction(customDrawFunction)->SetProperty("color", KOWGUI::Color::black)
        })
    }));

    // Another tree structure with function setters instad of structs (UNCOMPRESSED)
    userDefinedSlidesCustomNameWhatever.other = gui.root.AddChild((new KOWGUI::Static)->SetX(0)->SetY(0)->SetDisabled(true)->AddChildren({
        (new KOWGUI::Text)->
            SetX(50)->
            SetY(50)->
            SetText("Random text!")->
            SetFont(vex::fontType::prop20)->
            SetVerticalAlign(KOWGUI::Text::VerticalAlign::center)->
            SetColor(KOWGUI::Color::white),
        (new KOWGUI::Clickable)->
            SetX(200)->
            SetY(100)->
            SetWidth(50)->
            SetHeight(50)->
            AddChildren({
            (new KOWGUI::Unfocused)->AddChildren({(new KOWGUI::Rectangle).SetColor(KOWGUI::Color::gray)}),
            (new KOWGUI::Focused)->AddChildren({(new KOWGUI::Rectangle).SetColor(KOWGUI::Color::green)}),
            (new KOWGUI::Custom)->
                SetDrawFunction(customDrawFunction)->
                SetProperty("color", KOWGUI::Color::black)
        })
    }));
}


// KOWGUI::NodeName could be a static function that allocates memory and returns a reference...
// KOWGUI::NodeName could be a class name...