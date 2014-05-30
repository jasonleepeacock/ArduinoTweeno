#include <iostream>
#include <math.h>
#include "src/Pixel.h"
#include "src/Tween.h"

using namespace std;

main(){

	Pixel px;

	int duration = 10;
	float rangeR[2] = {0, 255};
	float rangeG[2] = {0, 255};
	float rangeB[2] = {0, 255};
	float rangeA[2] = {0, 1};

	px.init(duration, rangeR, rangeG, rangeB, rangeA);

	for(int i = 0; i < duration; i++){
		cout << "r: " << floor(px.getr());
		cout << " g: " << floor(px.getg());
		cout << " b: " << floor(px.getb());
		cout << " a: " << px.geta();
		cout << "\n";
		px.tick();
	}
}

