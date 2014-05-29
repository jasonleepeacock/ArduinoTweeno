#include "Pixel.h"
#include "Tween.h"
#include <iostream>

using namespace std;

Pixel::Pixel(){
	int duration = 10;
	float range [2] = {0, 255};
	// float alphaRange [2] = {0, 1};
	// r = new Tween(duration, range);
	Tween r(duration, range);
	// Tween g(duration, range);
	// Tween b(duration, range);
	// Tween a(duration, alphaRange);
}

void Pixel::tick(){
	cout << "tick\n";
	// iterate tweens and tick each
	// r.tick();
	r->tick();
	// g->tick();
	// b->tick();
	// a->tick();
	// (*r).tick();
}