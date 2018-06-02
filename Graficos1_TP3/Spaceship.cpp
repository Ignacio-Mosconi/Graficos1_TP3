#include "Spaceship.h"

Spaceship::Spaceship(int x, int y, const char* imagePath) : Enemy(x, y, imagePath)
{
	_speed = rand() % (SPACESHIP_MAX_SPEED - SPACESHIP_MIN_SPEED + 1) + SPACESHIP_MIN_SPEED;
	_spawnTime = rand() % (ASTEROID_MAX_SPAWN_TIME - ASTEROID_MIN_SPAWN_TIME + 1) + ASTEROID_MIN_SPAWN_TIME;
	_enabled = false;
	_waveAmplitude = rand() % (SPACESHIP_MAX_WAVE_AMPLITUDE - SPACESHIP_MIN_WAVE_AMPLITUDE + 1) + SPACESHIP_MIN_WAVE_AMPLITUDE;
	_waveFrequency = SPACESHIP_WAVE_FREQUENCY;
	_originY = _y;
}

Spaceship::~Spaceship()
{

}

void Spaceship::update(float elapsed)
{
	if (_enabled)
	{
		_time += elapsed;
		if (_x > SPACESHIP_MIN_X)
		{
			_x -= _speed * elapsed;
			_y = _waveAmplitude * cos(_waveFrequency * _time) + _originY; 
		}
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

void Spaceship::respawn()
{
	_time = 0;
	_enabled = true;
	_x = SPACESHIP_MAX_X;
	_y = rand() % (SPACESHIP_MAX_Y - SPACESHIP_HEIGHT - SPACESHIP_MIN_Y + 1) + SPACESHIP_MIN_Y;
	_speed = rand() % (SPACESHIP_MAX_SPEED - SPACESHIP_MIN_SPEED + 1) + SPACESHIP_MIN_SPEED;
	_spawnTime = rand() % (SPACESHIP_MAX_SPAWN_TIME - SPACESHIP_MIN_SPAWN_TIME + 1) + SPACESHIP_MIN_SPAWN_TIME;
	_originY = _y;
}