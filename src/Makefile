# compiler
CC = g++

# compiler flags
# CFLAGS = -std=c++17

# Build target
TARGET = main

CFLAGS=-I../library/tesseract/5.2.0/include -I../library/leptonica/1.82.0_1/inclue -I../library/zlib/include
LDFLAGS=-L../library/tesseract/5.2.0/lib -L../library/leptonica/1.82.0_1/lib -L../library/zlib/lib
LDLIBS=-ltesseract -llept -lz -framework ApplicationServices

SOURCES=compression/compression.cpp screenshot/screenshot.cpp storage/storage.cpp textRecognition/textRecognition.cpp
OBJECTS=main.o compression/compression.o screenshot/screenshot.o storage/storage.o textRecognition/textRecognition.o

EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -std=c++17 -o $@ $(OBJECTS) $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CC) -std=c++17 $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
