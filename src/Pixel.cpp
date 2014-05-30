#include "Pixel.h"
#include "Tween.h"

Pixel::Pixel(
        int duration,
        float rangeR[2], float rangeG[2], float rangeB[2], float rangeA[2])
: r(duration, rangeR)
, g(duration, rangeG)
, b(duration, rangeB)
, a(duration, rangeA)
{
}

void Pixel::tick(){
	r.tick();
	g.tick();
	b.tick();
	a.tick();
}
