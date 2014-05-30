CC=g++
OPTS=-std=c++11 -Wall
INCL=-Isrc

all:	
	$(CC) $(OPTS) $(INCL) tweenTest.cpp src/Tween.cpp -o build/tweenTest
	$(CC) $(OPTS) $(INCL) pixelTest.cpp src/Tween.cpp src/Pixel.cpp -o build/pixelTest

# all: pixelTest

pixelTest: Pixel.o Tween.o
	$(CC) $(OPTS) pixelTest.cpp Pixel.o Tween.o -o build/pixelTest

Pixel.o: Tween.o
	$(CC) $(OPTS) -c src/Pixel.cpp

Tween.o:
	$(CC) $(OPTS) -c src/Tween.cpp
