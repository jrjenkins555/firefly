#include <iostream>
#include "screenshot/screenshot.cpp"
#include "compression/compression.cpp"
#include "storage/storage.cpp"
#include "textRecognition/textRecognition.cpp"
#include <unistd.h>

using namespace std;


int main() {

    ScreenshotService screenshotService;
    CompressionService compressionService;
    StorageService storeageService;
    TextRecognitionService textRecognitionService;


    while(true){
        screenshotService.takeScreenshot();
        compressionService.compressImage();
        storeageService.storeImage();
        textRecognitionService.getText();
        sleep(5);
    }

    return 0;
}

