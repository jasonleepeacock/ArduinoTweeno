#include <iostream>
#include "Pixel.h"
#include "Tween.h"

using namespace std;

Pixel::Pixel(){
	// TODO - pass in duration and start/end values for each px
	int duration = 10;
	float range [2] = {0, 255};
	float alphaRange [2] = {0, 1};
	r.init(duration, range);
	g.init(duration, range);
	b.init(duration, range);
	a.init(duration, alphaRange);
}

void Pixel::tick(){
	r.tick();
	g.tick();
	b.tick();
	a.tick();
}