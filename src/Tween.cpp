#include "Tween.h"
#include <iostream>

using namespace std;

Tween::Tween(int duration, float range[]){
	cout << "made tween\n";

	// TODO - ensure values are valid
	_domain[0] = 0;
	_domain[1] = duration;

	// there has to be a better way to
	// assign one array to another :/
	_range[0] = range[0];
	_range[1] = range[1];

	// do we need to even store duration?
	_duration = duration;

	_currFrame = 0;

	_isDone = false;
}

void Tween::tick(){
	if(_isDone || _duration == 0){
		return;
	} else {
		_currFrame++;
		if(_currFrame == _duration){
			_isDone = true;
		}
	}	
}

float Tween::getX(){

	// cout << "duration " << _duration << "\n";
	// if _duration is 0, then this tween
	// can just return a constant value
	if(_duration == 0){
		return _range[0];
	} else {
		// return _scaleLinear(_currFrame);
		// return _scaleEaseOut(_currFrame);
		return _scaleLinear(_currFrame);
	}
}


float Tween::_scaleLinear(int x){
	float scaleFactor = float(x) / _domain[1];
	float result = scaleFactor * (_range[1] - _range[0]) + _range[0];
	return result;
}

// TODO - ease out :(
float Tween::_scaleEaseOut(int x){
	float scaleFactor = float(x) / _domain[1];
	float result = (scaleFactor + ((1-scaleFactor) * .01)) * (_range[1] - _range[0]) + _range[0];
	return result;
}
float Tween::_scaleEaseIn(int x){
	float scaleFactor = float(x) / _domain[1];
	float result = (scaleFactor * x * .1) * (_range[1] - _range[0]) + _range[0];
	return result;
}