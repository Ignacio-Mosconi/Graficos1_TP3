#include "State.h"

State::State(ALLEGRO_DISPLAY* display)
{
	_display = display;
	_queue = al_create_event_queue();
	_timer = al_create_timer(FRAME_TIME);

	_canDraw = true;
	_timeAtLastFrame = 0;

	al_register_event_source(_queue, al_get_keyboard_event_source());
	al_register_event_source(_queue, al_get_display_event_source(display));
	al_register_event_source(_queue, al_get_timer_event_source(_timer));

	al_start_timer(_timer);
}

State::~State()
{
	al_destroy_event_queue(_queue);
	al_destroy_timer(_timer);
}