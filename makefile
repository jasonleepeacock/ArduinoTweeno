all:
	# g++ -Isrc tweenTest.cpp src/Tween.cpp -o build/tweenTest
	g++ -Isrc pixelTest.cpp src/Tween.cpp src/Pixel.cpp -o build/pixelTest -g