// test.ino
#include "Pixel.h"
#include "Tween.h"
#include "Layer.h"
#include <math.h>
#include "Adafruit_NeoPixel.h"
#include "../../src/constants.h"

#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PX, PIN, NEO_GRB + NEO_KHZ800);

// 60fps
int TICK_RATE = 1000 / 60;
long lastTime;
long currentTime;
long diff;

// Pixel px;
Layer layer;

void setup() {

	// Serial.begin(9600);
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'

	layer.init();
}

void loop() {
	currentTime = millis();
	diff = currentTime - lastTime;

	// if it should tick, update
	if(diff > TICK_RATE){
		lastTime = currentTime;
		updateThings();

	// otherwise, wait till next tick
	} else {

	}
}

void updateThings(){
	
	float* results;
	results = layer.render();

	// Serial.println(results[0]);

	for(int i = 0; i < NUM_PX * NUM_SUB_PX; i += NUM_SUB_PX){
		strip.setPixelColor(i / NUM_SUB_PX, strip.Color(results[i], results[i+1], results[i+2]));	
	}
	
	strip.show();
	layer.tick();
}
