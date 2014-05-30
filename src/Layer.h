#ifndef LAYER_H
#define LAYER_H

#include "Pixel.h"
#include "../../src/constants.h"

class Layer {
public:
	void init();

	void tick();
	
	float* render();

	float results [NUM_PX * NUM_SUB_PX];

	Pixel pixels [NUM_PX];

private:
};

#endif