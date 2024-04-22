#include "KOWGUI/Nodes/text.h"

#include "KOWGUI/gui.h" // DEBUG
#include <math.h> // DEBUG

using namespace KOWGUI;

void Text::Draw(vex::brain::lcd& rScreen) {
    rScreen.setPenColor(vex::white);
    rScreen.setFillColor(vex::blue);
    rScreen.setFont(vex::prop60);
    // vexDisplayFontNamedSet("Prop");
    vexDisplayTextSize((sin(GetContainingGUI()->mpVexBrain->Timer.system() / 1000.0) / 2.0 + 0.51) * 300, 100);
    rScreen.printAt(CalculateX(), CalculateY(), true, "Text");
}