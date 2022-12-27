#include <iostream>
#include "screenshot.h"

#include <chrono>
#include <ctime>  

void ScreenshotService::takeScreenshot(){
    std::cout << "This is the screenshot service" << std::endl;

    auto start = std::chrono::system_clock::now();


    std::string system_command="screencapture -x Image.png";
    system((system_command).c_str());
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    std::cout << "Screenshot taken"
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;

}

