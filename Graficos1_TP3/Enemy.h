#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

enum Type
{
	ASTEROID, SPACESHIP
};

class Enemy : public Entity
{
protected:
	int _speed;
	float _spawnTime;
	bool _enabled;

public:
	Enemy(int x, int y, const char* imagePath) : Entity(x, y, imagePath) { _enabled = false; }
	~Enemy() {}

	virtual void update(float elapsed) = 0;
	virtual void respawn() = 0;
	virtual Type getType() = 0;

	void disable() { _enabled = false; }
	inline bool isEnabled() { return _enabled; }
};

#endif
