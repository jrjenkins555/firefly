#pragma once
#include "../screenshot/screenshot.h"

class CompressionService{
    public:
        void compressImage();
        unsigned char* compressBuffer(imageCapture* image);
    private:
        unsigned long file_size(char*);
        int compress_one_file(char*, char*);
        int decompress_one_file(char*, char*);
};