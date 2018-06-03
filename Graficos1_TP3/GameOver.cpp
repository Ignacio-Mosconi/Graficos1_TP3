#include "GameOver.h"

GameOver::GameOver(ALLEGRO_DISPLAY* display) : State(display)
{
	_titleFont = al_load_font(MENU_FONT_PATH, MENU_OPTIONS_SIZE, false);
	_textFont = al_load_font(MENU_FONT_PATH, HUD_FONT_SIZE, false);

	_gameOverText = "Game Over";
	_highestScoreText = "Highest Score: ";
	_restartText = "Press ENTER to restart.";
	_goBackText = "Press ESCAPE to go back.";

	_restarted = false;
	_wentBack = false;
	_quited = false;
}

GameOver::~GameOver()
{
	al_destroy_font(_titleFont);
	al_destroy_font(_textFont);
}

void GameOver::input()
{
	ALLEGRO_EVENT event;

	al_wait_for_event(_queue, &event);
	switch (event.type)
	{
		case ALLEGRO_EVENT_TIMER:
			_canDraw = true;
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			_quited = true;
			break;
		case ALLEGRO_EVENT_KEY_UP:
			switch (event.keyboard.keycode)
			{
				case ALLEGRO_KEY_ENTER:
					_restarted = true;
					break;
				case ALLEGRO_KEY_ESCAPE:
					_wentBack = true;
					break;
			}
	}
}

void GameOver::update(float elapsed)
{

}

void GameOver::draw() const
{
	if (_canDraw)
	{
		_canDraw = false;
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));

		al_draw_text(_titleFont, al_map_rgb_f(HUD_RED), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4, 
			ALLEGRO_ALIGN_CENTER, _gameOverText.c_str());

		al_draw_text(_textFont, al_map_rgb_f(HUD_WHITE), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
			ALLEGRO_ALIGN_CENTER, _highestScoreText.c_str());

		al_draw_text(_textFont, al_map_rgb_f(HUD_GREEN), 32, SCREEN_HEIGHT - 128,
			ALLEGRO_ALIGN_LEFT, _restartText.c_str());

		al_draw_text(_textFont, al_map_rgb_f(HUD_RED), SCREEN_WIDTH - 32, SCREEN_HEIGHT - 128, 
			ALLEGRO_ALIGN_RIGHT, _goBackText.c_str());

		al_flip_display();
	}
}

void GameOver::show(int highestScore)
{
	_highestScoreText = "Highest Score: " + to_string(highestScore);

	while (!_restarted && !_wentBack && !_quited)
	{
		float elapsed = al_get_time() - _timeAtLastFrame;
		_timeAtLastFrame = al_get_time();

		input();
		update(elapsed);
		draw();
	}
}