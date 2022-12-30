#pragma once

class CompressionService{
    public:
        void compressImage();
    private:
        unsigned long file_size(char*);
        int compress_one_file(char*, char*);
        int decompress_one_file(char*, char*);
};