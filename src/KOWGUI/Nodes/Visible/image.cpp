#include "KOWGUI/Nodes/Visible/image.h"

#include <iostream>

using namespace KOWGUI;

// Initialize an ImageBuffer with raw PNG or BMP data
ImageBuffer::ImageBuffer(uint8_t* data, uint32_t size) {
    bufferData = data;
    bufferSize = size;
}

// Initialize an ImageBuffer with a PNG or BMP file path. 
ImageBuffer::ImageBuffer(std::string filePath) {
    // Ensure SD card is inserted
    if(!isInserted()) {
        std::cerr << "KOWGUI: Could not load image. SD card is not inserted" << std::endl;
        vex::this_thread::sleep_for(5);
        return;
    }

    // Ensure file path exists
    if(!exists(filePath.c_str())) {
        std::cerr << "KOWGUI: Could not load image. File path \"" << filePath << "\" does not exist" << std::endl;
        vex::this_thread::sleep_for(5);
        return;
    }

    // Initialize buffer data
    bufferSize = size(filePath.c_str());
    bufferData = new uint8_t[bufferSize];
    // Load file data into buffer
    loadfile(filePath.c_str(), bufferData, bufferSize);
}

// ImageBuffer deconstructor. Free buffer memory
ImageBuffer::~ImageBuffer() {
    delete[] bufferData;
}



// Set the displayed image via an ImageBuffer. Reusing ImageBuffers is more memory efficient
Image* Image::SetImage(std::shared_ptr<ImageBuffer> imageBuffer) {
    mpImageBuffer = imageBuffer;
    return this;
}

// Set the displayed image via a PNG or BMP file path on the SD card. Creates a new ImageBuffer object
Image* Image::SetImage(std::string filePath) {
    mpImageBuffer = std::make_shared<ImageBuffer>(filePath);
    return this;
}



// Draw the image to the screen
void Image::Draw(vex::brain::lcd& rScreen) {
    // Return if no buffer has been set
    if(mpImageBuffer == nullptr) return;
    // Draw the image to the screen
    rScreen.drawImageFromBuffer(mpImageBuffer->bufferData, CalculateX(), CalculateY(), mpImageBuffer->bufferSize);
}