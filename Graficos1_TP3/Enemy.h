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
	ALLEGRO_SAMPLE* _hitSound;

	int _speed;
	float _spawnTime;
	bool _enabled;

public:
	Enemy(int x, int y, const char* imagePath) : Entity(x, y, imagePath) { _enabled = false; _hitSound = al_load_sample(HIT_SOUND_PATH); }
	~Enemy() {}

	virtual void update(float elapsed) = 0;
	virtual void respawn() = 0;
	virtual Type getType() = 0;

	void disable() { _enabled = false; al_play_sample(_hitSound, 1, ALLEGRO_AUDIO_PAN_NONE, 1, ALLEGRO_PLAYMODE_ONCE, NULL); }
	inline bool isEnabled() { return _enabled; }
};

#endif
