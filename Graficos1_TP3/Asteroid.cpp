#include "Asteroid.h"

Asteroid::Asteroid(int x, int y, const char* imagePath) : Enemy(x, y, imagePath)
{
	_speed = rand() % (ASTEROID_MAX_SPEED - ASTEROID_MIN_SPEED + 1) + ASTEROID_MIN_SPEED;
	_spawnTime = rand() % (ASTEROID_MAX_SPAWN_TIME - ASTEROID_MIN_SPAWN_TIME + 1) + ASTEROID_MIN_SPAWN_TIME;
	_enabled = false;
}

Asteroid::~Asteroid()
{

}

void Asteroid::update(float elapsed)
{
	if (_enabled)
	{
		if (_x > ASTEROID_MIN_X)
			_x -= _speed * elapsed;
		else
			_enabled = false;
	}
	else
	{
		_spawnTime -= elapsed;
		if (_spawnTime <= 0)
			respawn();
	}
}

void Asteroid::respawn()
{
	_enabled = true;
	_x = ASTEROID_MAX_X;
	_y = rand() % (ASTEROID_MAX_Y - ASTEROID_HEIGHT - ASTEROID_MIN_Y + 1) + ASTEROID_MIN_Y;
	_speed = rand() % (ASTEROID_MAX_SPEED - ASTEROID_MIN_SPEED + 1) + ASTEROID_MIN_SPEED;
	_spawnTime = rand() % (ASTEROID_MAX_SPAWN_TIME - ASTEROID_MIN_SPAWN_TIME + 1) + ASTEROID_MIN_SPAWN_TIME;
}