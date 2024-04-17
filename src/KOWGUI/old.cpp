void CreateSlide() {
    tSlide &slide = slides["home"];
    Element* elem;

    elem = &slide["btnTeleport"];
    elem->posX = 400;
    elem->posY = 0;
    elem->width = 30;
    elem->height = 30;
    elem->fillColor = blue;
    elem->interactable = true;
    elem->clickUpFunc = [](){
        slides["home"]["btnTeleport"].posX = rand() % (480 - 400 - 30) + 400;
        slides["home"]["btnTeleport"].posY = rand() % (240 - 30);
        DrawWholeScreen();
    };

    elem = &slide["btnButtons"];
    elem->posX = 80;
    elem->posY = 140;
    elem->width = 100;
    elem->height = 70;
    elem->fillColor = color(30, 30, 30);
    elem->outlineColor = white;
    elem->outlineWidth = 2;
    elem->text = "More buttons :)";
    elem->textColor = white;
    elem->textLineSpacing = 0.7;
    elem->interactable = true;
    elem->clickUpSlide = &slides["buttons"];
}