# compiler
CC = g++

# compiler flags
CFLAGS = -g

# Build target
TARGET = main

# Object Files
OBJ_FILES = screenshot/screenshot.o compression/compression.o storage/storage.o textRecognition/textRecognition.o

# Third Party Libs
LIBS = ../library/libz.a

# Clean command
clean:
	$(RM) $(TARGET) $(TARGET).o $(OBJ_FILES)

# link the executable
main: main.o screenshot/screenshot.o compression/compression.o storage/storage.o textRecognition/textRecognition.o
	$(CC) $(CFLAGS) -o main $(TARGET).o $(OBJ_FILES) $(LIBS) -framework ApplicationServices

main.o: main.cpp screenshot/screenshot.h compression/compression.h storage/storage.h textRecognition/textRecognition.h
	$(CC) $(CFLAGS) -c main.cpp

screenshot/screenshot.o: screenshot/screenshot.h

compression/compression.o: compression/compression.h

storage/storage.o: storage/storage.h

textRecognition/textRecognition.o: textRecognition/textRecognition.h
