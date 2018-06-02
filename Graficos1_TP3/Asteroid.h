#ifndef ASTEROID_H
#define ASTEROID_H

#include "Enemy.h"

class Asteroid : public Enemy
{
public:
	Asteroid(int x, int y, const char* imagePath);
	~Asteroid();

	void update(float elapsed);

	void respawn();
	Type getType() { return ASTEROID; }
};

#endif
