#include <iostream>
#include "screenshot/screenshot.h"
#include "compression/compression.h"
#include "storage/storage.h"
#include "textRecognition/textRecognition.h"
#include <unistd.h>

using namespace std;


int main() {

    ScreenshotService screenshotService;
    CompressionService compressionService;
    StorageService storeageService;
    TextRecognitionService textRecognitionService;


    while(true){
        ImageCapture* image = screenshotService.takeScreenshot();
        textRecognitionService.getText(image);
        CompressedImage* compressed = compressionService.compressBuffer(image);
        storeageService.storeImage();
        sleep(5);
    }

    return 0;
}

