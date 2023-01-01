# compiler
CC = g++

# compiler flags
CFLAGS = -std=c++17

# Build target
TARGET = main

# Object Files
OBJ_FILES = screenshot/screenshot.o compression/compression.o storage/storage.o textRecognition/textRecognition.o

# Third Party Libs
LIBS = ../library/libz.a ../library/tesseract/5.2.0/lib/libtesseract.a ../library/leptonica/1.82.0_1/lib/liblept.a

# Clean command
clean:
	$(RM) $(TARGET) $(TARGET).o $(OBJ_FILES)

# link the executable
main: main.o screenshot/screenshot.o compression/compression.o storage/storage.o textRecognition/textRecognition.o
	$(CC) $(CFLAGS) -o main $(TARGET).o $(OBJ_FILES) $(LIBS) -framework ApplicationServices

main.o: main.cpp screenshot/screenshot.h compression/compression.h storage/storage.h textRecognition/textRecognition.h
	$(CC) $(CFLAGS) -c main.cpp

screenshot/screenshot.o: screenshot/screenshot.h
	$(CC) $(CFLAGS) -c -o screenshot/screenshot.o screenshot/screenshot.cpp

compression/compression.o: compression/compression.h
	$(CC) $(CFLAGS) -c -o compression/compression.o compression/compression.cpp

storage/storage.o: storage/storage.h
	$(CC) $(CFLAGS) -c -o storage/storage.o storage/storage.cpp

textRecognition/textRecognition.o: textRecognition/textRecognition.h
	$(CC) $(CFLAGS) -c -o textRecognition/textRecognition.o textRecognition/textRecognition.cpp
