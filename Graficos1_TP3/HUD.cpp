#include "HUD.h"

HUD::HUD(ALLEGRO_DISPLAY* display)
{
	_display = display;
	_hudFont = al_load_font(HUD_FONT_PATH, HUD_FONT_SIZE, false);
	_pausedFont = al_load_font(MENU_FONT_PATH, MENU_OPTIONS_SIZE, false);
	_scoreText = "Score: 0";
	_livesText = "Lives: 3";
	_pausedText = "Paused";
}

HUD::~HUD()
{
	al_destroy_font(_hudFont);
	al_destroy_font(_pausedFont);
}

void HUD::update(Element element, int amount)
{
	switch (element)
	{
		case SCORE:
			_scoreText = "Score: " + to_string(amount);
			break;
		case LIVES:
			_livesText = "Lives: " + to_string(amount);
			break;
	}
}

void HUD::draw(const int playerLives, const bool isPaused) const
{
	switch (playerLives)
	{
		case 3:
			al_draw_text(_hudFont, al_map_rgb_f(HUD_GREEN), SCREEN_WIDTH / 2, HUD_TEXT_POS_Y, ALLEGRO_ALIGN_CENTER, _livesText.c_str());
			break;
		case 2:
			al_draw_text(_hudFont, al_map_rgb_f(HUD_YELLOW), SCREEN_WIDTH / 2, HUD_TEXT_POS_Y, ALLEGRO_ALIGN_CENTER, _livesText.c_str());
			break;
		default:
			al_draw_text(_hudFont, al_map_rgb_f(HUD_RED), SCREEN_WIDTH / 2, HUD_TEXT_POS_Y, ALLEGRO_ALIGN_CENTER, _livesText.c_str());

	}
	
	al_draw_text(_hudFont, al_map_rgb_f(HUD_BLUE), 64, HUD_TEXT_POS_Y, ALLEGRO_ALIGN_LEFT, _scoreText.c_str());

	if (isPaused)
		al_draw_text(_pausedFont, al_map_rgb_f(HUD_WHITE), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
			ALLEGRO_ALIGN_CENTER, _pausedText.c_str());
}