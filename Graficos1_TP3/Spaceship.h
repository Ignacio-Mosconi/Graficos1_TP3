#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <math.h>
#include "Enemy.h"

class Spaceship : public Enemy
{
private:
	float _waveAmplitude;
	float _waveFrequency;
	float _time;
	int _originY;

public:
	Spaceship(int x, int y, const char* imagePath);
	~Spaceship();

	void update(float elapsed);

	void respawn();
	Type getType() { return SPACESHIP; }
};

#endif
