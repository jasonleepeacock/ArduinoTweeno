#ifndef PIXEL_H
#define PIXEL_H

#include "Tween.h"

class Pixel {
public:
	Pixel();
	// Tween r;
	Tween* r;
	// Tween* g;
	// Tween* b;
	// Tween* a;

	void tick();

	// float getr(){ return r.getX(); }
	float getr(){ return r->getX(); }
	// float getg(){ return g->getX(); }
	// float getb(){ return b->getX(); }
	// float geta(){ return a->getX(); }

private:
};

#endif