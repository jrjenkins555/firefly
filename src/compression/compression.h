#pragma once
#include "../screenshot/screenshot.h"
extern "C"{
    #include "../../library/zlib/include/zlib.h"
}

struct CompressedImage {
    unsigned char* image;
    uLong compressedSize;
    uLong originalSize;
};

class CompressionService{
    public:
        void compressImage();
        CompressedImage* compressBuffer(ImageCapture*);
        void decompressBuffer(CompressedImage*);
    private:
        unsigned long file_size(char*);
        int compress_one_file(char*, char*);
        int decompress_one_file(char*, char*);
};