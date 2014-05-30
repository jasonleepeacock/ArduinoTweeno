#include "Pixel.h"
#include "Tween.h"

void Pixel::init(int duration, float rangeR[2], float rangeG[2], float rangeB[2], float rangeA[2]){
	r.init(duration, rangeR);
	g.init(duration, rangeG);
	b.init(duration, rangeB);
	a.init(duration, rangeA);
}
void Pixel::tick(){
	r.tick();
	g.tick();
	b.tick();
	a.tick();
}