#include <iostream>
#include "Pixel.h"
#include "Tween.h"

using namespace std;

Pixel::Pixel(){
	int duration = 10;
	float range [2] = {0, 255};
	float alphaRange [2] = {0, 1};
	r = new Tween(duration, range);
	g = new Tween(duration, range);
	b = new Tween(duration, range);
	a = new Tween(duration, alphaRange);
}

void Pixel::tick(){
	r->tick();
	g->tick();
	b->tick();
	a->tick();
}