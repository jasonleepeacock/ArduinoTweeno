#ifndef PIXEL_H
#define PIXEL_H

#include "Tween.h"

// TODO - accept hex and convert to rgb
// TODO - more sane init function signature

class Pixel {
public:
	void init(int duration, float rangeR[2], float rangeG[2], float rangeB[2], float rangeA[2]);
	
	Tween r;
	Tween g;
	Tween b;
	Tween a;

	void tick();

	float getr(){ return r.getX(); }
	float getg(){ return g.getX(); }
	float getb(){ return b.getX(); }
	float geta(){ return a.getX(); }

private:
};

#endif