all: pixelTest
	# g++ -Isrc tweenTest.cpp src/Tween.cpp -o build/tweenTest
	# g++ -Isrc pixelTest.cpp src/Tween.cpp src/Pixel.cpp -o build/pixelTest -g
	# g++ pixelTest.cpp Pixel.o Tween.o -o build/pixelTest

pixelTest: Pixel.o Tween.o
	g++ pixelTest.cpp Pixel.o Tween.o -o build/pixelTest

Pixel.o: Tween.o
	g++ -Wall -c src/Pixel.cpp

Tween.o:
	g++ -Wall -c src/Tween.cpp