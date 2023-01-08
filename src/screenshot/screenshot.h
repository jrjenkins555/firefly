#pragma once

struct ImageCapture{
    unsigned long height;
    unsigned long width;
    unsigned long bpp;
    unsigned char* pixels;
};

class ScreenshotService{
    public:
        ImageCapture* takeScreenshot();
    private:
        ImageCapture* testEfficientScreenshot();
};