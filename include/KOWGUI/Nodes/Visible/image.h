#ifndef KOWGUI_IMAGE_NODE_H
#define KOWGUI_IMAGE_NODE_H

#include "KOWGUI/BaseNodes/visibleBaseNode.h"

#include <memory>

namespace KOWGUI {

    // Container for the size and content of an image
    struct ImageBuffer : public vex::brain::sdcard { // Ah, handy, thanks jpearman. https://www.vexforum.com/t/sw-wight-a-new-gui-library-released/126341/11?u=1810t-colby
        // Size of the image buffer
        uint8_t* bufferData;
        // Data inside the image buffer
        uint32_t bufferSize;

        ImageBuffer(uint8_t* data, uint32_t size);
        ImageBuffer(std::string filePath);
        ~ImageBuffer();
    };

    class Image : public VisibleBaseNode {
        private:
            // Image data to be drawn
            std::shared_ptr<ImageBuffer> mpImageBuffer = nullptr;
        
        public:
            Image* SetX(int x) {BaseNode::SetX(x); return this;}
            Image* SetY(int y) {BaseNode::SetY(y); return this;}
            Image* SetPosition(int x, int y) {BaseNode::SetPosition(x, y); return this;}
            Image* SetWidth(int width) {BaseNode::SetWidth(width); return this;}
            Image* SetHeight(int height) {BaseNode::SetHeight(height); return this;}
            Image* SetSize(int width, int height) {BaseNode::SetSize(width, height); return this;}
            Image* SetID(std::string iD) {BaseNode::SetID(iD); return this;}
            Image* SetShallowID(std::string shallowID) {BaseNode::SetShallowID(shallowID); return this;}
            Image* SetPreTick(void (*callback)(BaseNode*)) {BaseNode::SetPreTick(callback); return this;}
            Image* SetDisabled(bool disabled) {BaseNode::SetDisabled(disabled); return this;}
            Image* ClearPreTick() {BaseNode::ClearPreTick(); return this;}
            Image* AddChildren(std::vector<BaseNode*> newChildren) {BaseNode::AddChildren(newChildren); return this;}

            Image* SetImage(std::shared_ptr<ImageBuffer> imageBuffer);
            Image* SetImage(std::string filePath);

            void Draw(vex::brain::lcd& rScreen);
    };

}

#endif