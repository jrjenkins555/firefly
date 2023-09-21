#include <iostream>
#include "compression.h"

CompressedImage* CompressionService::compressBuffer(ImageCapture* image) {
    const int bytes = image->height * image->width * image->bpp;
    uLong destLen = compressBound(bytes); // upper bound for output buffer
    uLong* destLenCopy = new uLong(destLen); // DELETE later: copy for reporting % compressed
    std::cout << "size before: " << destLen << std::endl;
    // pointer to mem with output - 'Bytef' is same as 'unsigned char' or 'Byte'
    Bytef* dest = new Bytef[destLen];
    compress(dest, &destLen, (Bytef*) image->pixels, bytes);
    std::cout << "size after: " << destLen << std::endl;
    std::cout << "compressed by " << ((float) (*destLenCopy - destLen) / *destLenCopy) * 100 << "%" << std::endl;
    delete destLenCopy; // DELETE later
    delete image;
    CompressedImage* compressed = new CompressedImage;
    compressed->image = dest;
    compressed->compressedSize = destLen;
    compressed->originalSize = bytes;
    return compressed;
}

void CompressionService::decompressBuffer(CompressedImage* compressed) {
    std::cout << "Decompressing image" << std::endl;
    // need to store size of original image to allocate enough buffer space here
    int* dest = new int[compressed->originalSize];
    uncompress((Bytef*) dest, &(compressed->originalSize), compressed->image, compressed->compressedSize);
    // std::cout << "size of image: " <<  << std::endl;
}

void CompressionService::compressImage(){
    std::cout << "This is the compression service" << std::endl;
    compress_one_file("Image.png", "out.z");
}

unsigned long CompressionService::file_size(char *filename)
{
   FILE *pFile = fopen(filename, "rb");
   fseek (pFile, 0, SEEK_END);
   unsigned long size = ftell(pFile);
   fclose (pFile);
   return size;
}

int CompressionService::compress_one_file(char *infilename, char *outfilename)
{
   FILE *infile = fopen(infilename, "rb");
   gzFile outfile = gzopen(outfilename, "wb");
   if (!infile || !outfile) return -1;
   char inbuffer[128];
   int num_read = 0;
   unsigned long total_read = 0, total_wrote = 0;
   while ((num_read = fread(inbuffer, 1, sizeof(inbuffer), infile)) > 0) {
      total_read += num_read;
      gzwrite(outfile, inbuffer, num_read);
   }
   fclose(infile);
   gzclose(outfile);
   printf("Read %ld bytes, Wrote %ld bytes,Compression factor %4.2f%%n",
      total_read, file_size(outfilename),
      (1.0-file_size(outfilename)*1.0/total_read)*100.0);
}

int CompressionService::decompress_one_file(char *infilename, char *outfilename)
{
   gzFile infile = gzopen(infilename, "rb");
   FILE *outfile = fopen(outfilename, "wb");
   if (!infile || !outfile) return -1;
   char buffer[128];
   int num_read = 0;
   while ((num_read = gzread(infile, buffer, sizeof(buffer))) > 0) {
      fwrite(buffer, 1, num_read, outfile);
      }
   gzclose(infile);
   fclose(outfile);
}
