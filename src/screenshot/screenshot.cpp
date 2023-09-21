#include <iostream>
#include "screenshot.h"

#include <chrono>
#include <ctime>  

#include <cstdlib>
#include <ApplicationServices/ApplicationServices.h>

ImageCapture* ScreenshotService::takeScreenshot(){
    std::cout << "This is the screenshot service" << std::endl;

    auto start = std::chrono::system_clock::now();


    // std::string system_command="screencapture -x Image.png";
    // system((system_command).c_str());

    ImageCapture* image = testEfficientScreenshot();
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    std::cout << "Screenshot taken\n"
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;
    return image;
}

ImageCapture* ScreenshotService::testEfficientScreenshot(){
    CGImageRef image_ref = CGDisplayCreateImage(CGMainDisplayID()); 
    CGDataProviderRef provider = CGImageGetDataProvider(image_ref);
    CFDataRef dataref = CGDataProviderCopyData(provider);
    size_t width, height;    
    width = CGImageGetWidth(image_ref);
    height = CGImageGetHeight(image_ref); 
    std::cout << width << std::endl;
    std::cout << height << std::endl;
    size_t bpp = CGImageGetBitsPerPixel(image_ref) / 8;
    uint8 *pixels = (uint8*) malloc(width * height * bpp);
    memcpy(pixels, CFDataGetBytePtr(dataref), width * height * bpp);
    CFRelease(dataref); 
    CGImageRelease(image_ref); 

    // FILE *stream = fopen("screencap.raw", "w+");
    // fwrite(pixels, bpp, width * height, stream);
    // fclose(stream); 

    ImageCapture* image = new ImageCapture;
    image->bpp = bpp;
    image->height = height;
    image->width = width;
    image->pixels = (unsigned char*) pixels;
    return image;
}

