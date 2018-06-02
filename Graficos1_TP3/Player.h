#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Bullet.h"

enum Direction
{
	LEFT, RIGHT, UP, DOWN
};

class Player : public Entity
{
private:
	Bullet* _bullets;
	int _lives;
	int _speed;
	float _shotCooldown;

	void move(Direction direction, float elapsed);
	void shoot(float elapsed);

public:
	Player(int x, int y, const char* imagePath);
	~Player();

	void update(float elapsed);
	void die();
	void respawn();

	Bullet* getBullets() { return _bullets; }
	inline int getLives() { return _lives; }
};

#endif
