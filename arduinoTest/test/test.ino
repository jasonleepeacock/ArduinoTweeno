// test.ino
#include "Pixel.h"
#include "Tween.h"
#include <math.h>
#include "Adafruit_NeoPixel.h"


#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);

// 60fps
int TICK_RATE = 1000 / 60;
int NUM_PX = 16;
long lastTime;
long currentTime;
long diff;

Pixel px;

void setup() {

	// Serial.begin(9600);
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'

	strip.setPixelColor(3, strip.Color(255, 0, 0));
	strip.show();

	int duration = 120;
	float rangeR[2] = {20, 0};
	float rangeG[2] = {0, 20};
	float rangeB[2] = {0, 0};
	float rangeA[2] = {0, 1};

	px.init(duration, rangeR, rangeG, rangeB, rangeA);

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

	float currR = floor(px.getr());
	float currG = floor(px.getg());
	float currB = floor(px.getb());
	float currA = floor(px.geta());

	// Serial.println(currR);

	for(int i = 0; i < NUM_PX; i++){
		strip.setPixelColor(i, strip.Color(currR, currG, currB));	
	}
	
	strip.show();

	px.tick();
}
