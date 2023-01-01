#include <iostream>
#include "textRecognition.h"
#include "../../library/leptonica/1.82.0_1/include/leptonica/allheaders.h"
#include "../../library/tesseract/5.2.0/include/tesseract/baseapi.h"

char* TextRecognitionService::getText(imageCapture image){
    std::cout << "This is the text recognition service" << std::endl;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    api ->Init(NULL, "eng" );
}

