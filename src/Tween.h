#ifndef TWEEN_H
#define TWEEN_H

// TODO - loop, reverse
// TODO - start, stop, pause, rewind
// TODO - start delay, end delay

class Tween {
public: 
	// range: int array with 2 values: the min
	// and max values that the scale should return
	// duration: duration of the tween in frames
	void init(int duration, float range[]);

	// advances the playhead by one frame (or if
	// tween is reversing, reverses the playhead
	// by one frame)
	void tick();

	// returns the current output value
	float getX();

	// returns if this tween has played to completion
	// or not
	bool isDone(){ return _isDone; };

private:
	// examines _domain and _range, and given x
	// returns the current output value
	float _scaleLinear(int x);
	float _scaleEaseOut(int x);
	float _scaleEaseIn(int x);

	bool loop;

	// TODO - yoyo

	// input domain
	int _domain [2];

	// output range
	float _range [2];

	// current frame / playhead position
	int _currFrame;

	// duration of this tween in frames
	int _duration;

	// if tween has reached the last frame
	// or not
	bool _isDone;
};

#endif