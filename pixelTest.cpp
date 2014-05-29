#include <iostream>
#include <math.h>
#include "src/Pixel.h"
#include "src/Tween.h"

using namespace std;

main(){

	Pixel a;

	for(int i = 0; i < 10; i++){
		a.tick();
		cout << "r: " << floor(a.getr());
		cout << " g: " << floor(a.getg());
		cout << " b: " << floor(a.getb());
		cout << " a: " << a.geta();
		cout << "\n";
	}
}

