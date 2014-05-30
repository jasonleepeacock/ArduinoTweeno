#include "Layer.h"
#include "Pixel.h"
// #include "Adafruit_NeoPixel.h"


void Layer::init(){
	// Serial.begin(9600);

	for(int i = 0; i < NUM_PX; i++){
		Pixel px;

		// TODO - get these vals from user
		int duration = 120;
		float rangeR[2] = {20, 0};
		float rangeG[2] = {0, 20};
		float rangeB[2] = {0, 0};
		float rangeA[2] = {0, 1};

		px.init(duration, rangeR, rangeG, rangeB, rangeA);
		pixels[i] = px;
	}
}
void Layer::tick(){
	for(int i = 0; i < NUM_PX; i++){
		pixels[i].tick();
	}
}

float* Layer::render(){
	for(int i = 0; i < NUM_PX; i++){
		int offset = NUM_SUB_PX * i;
		results[offset] = pixels[i].getr();
		results[offset+1] = pixels[i].getg();
		results[offset+2] = pixels[i].getb();
		results[offset+3] = pixels[i].geta();
	}
	return results;
	
}