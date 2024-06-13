#include "KOWGUI/kowgui.h"
#include "TestGUI/panelManager.h"

using namespace KOWGUI;

const double diagramTextSize = 54;
const double diagramLineSizeMultiplier = diagramTextSize / Fonts::proportional.height;
const int lineLength = 270;

void InitGUITextVerticalAlignDemo() {
    panels.textVerticalAlignDemo->AddChildren({
        (new Text)->SetPosition(20, 130)->SetText("good text.")->SetFont(Fonts::proportional)->SetFontSize(diagramTextSize)->SetVerticalAlign(VerticalAlign::baseline)->AddChildren({
            (new Line)->SetPositions(-10, -57 * diagramLineSizeMultiplier, lineLength, -57 * diagramLineSizeMultiplier)->SetColor(Color::white)->SetLineWidth(1)->AddChildren({   (new Text)->SetPosition(lineLength + 20, 0)->SetText("Top")->      SetFontSize(10)->SetVerticalAlign(VerticalAlign::middle)   }),
            (new Line)->SetPositions(-10, -41 * diagramLineSizeMultiplier, lineLength, -41 * diagramLineSizeMultiplier)->SetColor(Color::white)->SetLineWidth(1)->AddChildren({   (new Text)->SetPosition(lineLength + 20, 0)->SetText("Ascender")-> SetFontSize(10)->SetVerticalAlign(VerticalAlign::middle)   }),
            (new Line)->SetPositions(-10, -15 * diagramLineSizeMultiplier, lineLength, -15 * diagramLineSizeMultiplier)->SetColor(Color::white)->SetLineWidth(1)->AddChildren({   (new Text)->SetPosition(lineLength + 20, 0)->SetText("Middle")->   SetFontSize(10)->SetVerticalAlign(VerticalAlign::middle)   }),
            (new Line)->SetPositions(-10,   0 * diagramLineSizeMultiplier, lineLength,   0 * diagramLineSizeMultiplier)->SetColor(Color::white)->SetLineWidth(1)->AddChildren({   (new Text)->SetPosition(lineLength + 20, 0)->SetText("Baseline")-> SetFontSize(10)->SetVerticalAlign(VerticalAlign::middle)   }),
            (new Line)->SetPositions(-10,  13 * diagramLineSizeMultiplier, lineLength,  13 * diagramLineSizeMultiplier)->SetColor(Color::white)->SetLineWidth(1)->AddChildren({   (new Text)->SetPosition(lineLength + 20, 0)->SetText("Descender")->SetFontSize(10)->SetVerticalAlign(VerticalAlign::middle)   }),
            (new Line)->SetPositions(-10,  33 * diagramLineSizeMultiplier, lineLength,  33 * diagramLineSizeMultiplier)->SetColor(Color::white)->SetLineWidth(1)->AddChildren({   (new Text)->SetPosition(lineLength + 20, 0)->SetText("Bottom")->   SetFontSize(10)->SetVerticalAlign(VerticalAlign::middle)   }),
        }),
    });
}