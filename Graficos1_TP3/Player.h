#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

enum Direction
{
	Left, Right, Up, Down
};

class Player : public Entity
{
private:
	int _lives;
	float _speed;

	void move(Direction direction, float elapsed);

public:
	Player(int x, int y, const char* imagePath);
	~Player();

	void update(float elapsed);
	void die();
	void respawn();

	inline int getLives() { return _lives; }
};

#endif
