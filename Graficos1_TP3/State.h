#ifndef STATE_H
#define STATE_H

#include <allegro5\allegro.h>
#include "Definitions.h"

class State
{
protected:
	ALLEGRO_DISPLAY * _display;
	ALLEGRO_EVENT_QUEUE* _queue;
	ALLEGRO_TIMER* _timer;

	bool _canDraw;
	float _timeAtLastFrame;

	virtual void input() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

public:
	State(ALLEGRO_DISPLAY* display);
	~State();
};

#endif
