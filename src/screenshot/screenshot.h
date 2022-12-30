#pragma once

struct imageCapture{
    unsigned long height;
    unsigned long width;
    unsigned long bpp;
    unsigned char* pixels;
};

class ScreenshotService{
    public:
        imageCapture takeScreenshot();
    private:
        imageCapture testEfficientScreenshot();
};