#include <iostream>
#include "screenshot/screenshot.cpp"
#include "compression/compression.cpp"
#include "storage/storage.cpp"
#include "textRecognition/textRecognition.cpp"


using namespace std;

int main() {

    ScreenshotService screenshotService;
    CompressionService compressionService;
    StorageService storeageService;
    TextRecognitionService textRecognitionService;


    screenshotService.takeScreenshot();
    compressionService.compressImage();
    storeageService.storeImage();
    textRecognitionService.getText();

    return 0;
}

