#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
private:
	float _speed;
	bool _enabled;
	
public:
	Bullet();
	~Bullet();

	void update(float elapsed);

	inline bool isEnabled() { return _enabled; }
	void enable() { _enabled = true; }
	void disable() { _enabled = false; }
};

#endif
