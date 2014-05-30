#include "Tween.h"
#include <iostream>

using namespace std;

Tween::Tween(int duration, float range[])
: _domain{0, duration}
, _range{range[0], range[1]}
{
	// TODO - ensure values are valid
	//_domain[0] = 0;
	//_domain[1] = duration;

	// there has to be a better way to
	// assign one array to another :/
	//_range[0] = range[0];
	//_range[1] = range[1];

	// do we need to even store duration?
	_duration = duration;

	// TODO - get this from user
	loop = true;

	_currFrame = 0;

	_isDone = false;
}

void Tween::tick(){
	// tween should just return a static val
	if(_duration == 0 || _isDone){
		return;

	// count frames
	} else {
		_currFrame++;

		// if were at the end of the tween animation
		if(_currFrame == _duration){

			// if tween should loop, reset _currFrame
			if(loop){
				_currFrame = 0;

			// otherwise tween is done
			} else {
				_isDone = true;
			}		
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
