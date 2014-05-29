#include <iostream>
#include "Pixel.h"
#include "Tween.h"

using namespace std;

main(){

	Pixel a;
	a.tick();
	cout << a.getr() << "\n";
	a.tick();
	cout << a.getr() << "\n";
	a.tick();
	cout << a.getr() << "\n";
	a.tick();
	cout << a.getr() << "\n";


	cout << "\n\nusing Tween directly";
	int duration = 10;
	float range [2] = {0, 255};
	Tween b(duration, range);
	b.tick();
	cout << b.getX() << "\n";
	b.tick();
	cout << b.getX() << "\n";
	b.tick();
	cout << b.getX() << "\n";
	b.tick();
	cout << b.getX() << "\n";
	// float val = a.getr();
	// cout << val << "\n";

	// a.tick();
	// cout << "r: " << a.getr() << "/n";
	// // range[0] is starting value
	// // range[1] is ending value
	// float range [2] = {0, 100};
	// float rangeAlpha [2] = {1, 0};
	// // duration in frames
	// int duration = 10;

	// // create a tween for each subpixel
	// // (red, green, blue) and use the same
	// // duration. realistically the range would
	// // differ from subpixel to subpixel
	// // TODO - loop and reverse options
	// Tween r(duration, range);
	// Tween g(duration, range);
	// // a duration of zero means this tween will
	// // always return the first value of range. IE
	// // it is a constant value tween
	// Tween b(0, range);
	// Tween a(duration, rangeAlpha);

	// // "play" each tween a frame at a time
	// // and output the value
	// // NOTE: Layer will take care of this RGB
	// // junk for you. 
	// while(!r.isDone()){
	// 	r.tick();
	// 	g.tick();
	// 	b.tick();
	// 	a.tick();
	// 	cout << "r: " << floor(r.getX());
	// 	// cout << " g: " << floor(g.getX());
	// 	// cout << " b: " << floor(b.getX());
	// 	// cout << " a: " << a.getX();
	// 	cout << "\n";
	// }
}

