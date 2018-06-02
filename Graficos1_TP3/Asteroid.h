#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity
{
private:
	float _speed;
	float _spawnTime;
	bool _enabled;

public:
	Asteroid(int x, int y, const char* imagePath);
	~Asteroid();

	void update(float elapsed);

	inline bool isEnabled() { return _enabled; }
	void disable() { _enabled = false; }
	void respawn();
};

#endif
