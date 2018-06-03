#include "Menu.h"

Menu::Menu(ALLEGRO_DISPLAY* display) : State(display)
{
	_titleFont = al_load_font(MENU_FONT_PATH, MENU_TITLE_SIZE, false);
	_optionsFont = al_load_font(MENU_FONT_PATH, MENU_OPTIONS_SIZE, false);

	_titleText = GAME_TITLE;
	_optionsText[0] = "Play";
	_optionsText[1] = "Exit";

	_optionsTextX[0] = SCREEN_WIDTH / 2 - al_get_text_width(_optionsFont, _optionsText[0].c_str()) / 2;
	_optionsTextY[0] = SCREEN_HEIGHT / 2;
	_optionsTextX[1] = SCREEN_WIDTH / 2 - al_get_text_width(_optionsFont, _optionsText[1].c_str()) / 2;
	_optionsTextY[1] = SCREEN_HEIGHT / 2 + 128;

	_mouseX = 0;
	_mouseY = 0;

	_selected[0] = false;
	_selected[1] = false;
	_clicked = false;
	_started = false;
	_quited = false;
}

Menu::~Menu()
{
	al_destroy_font(_titleFont);
	al_destroy_font(_optionsFont);
}

void Menu::input()
{
	ALLEGRO_EVENT event;

	al_wait_for_event(_queue, &event);
	switch (event.type)
	{
		case ALLEGRO_EVENT_MOUSE_AXES:
			_mouseX = event.mouse.x;
			_mouseY = event.mouse.y;
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			_mouseX = event.mouse.x;
			_mouseY = event.mouse.y;
			_clicked = true;
			break;
		case ALLEGRO_EVENT_TIMER:
			_canDraw = true;
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			_quited = true;
			break;
	}
}

void Menu::update(float elapsed)
{
	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		if (isMouseOverText(_optionsFont, _optionsText[i], i))
		{
			if (!_selected[i])
				_selected[i] = true;
		}
		else
			if (_selected[i])
				_selected[i] = false;

		if (_clicked)
		{
			if (_selected[0])
				_started = true;
			else
				if (_selected[1])
					_quited = true;
		}
	}
	_clicked = false;
}

void Menu::draw() const
{
	if (_canDraw)
	{
		_canDraw = false;
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));

		al_draw_text(_titleFont, al_map_rgb_f(HUD_GREEN), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4, ALLEGRO_ALIGN_CENTER, _titleText.c_str());

		if (_selected[0])
			al_draw_text(_optionsFont, al_map_rgb_f(HUD_GREEN), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
				ALLEGRO_ALIGN_CENTER, _optionsText[0].c_str());
		else
			al_draw_text(_optionsFont, al_map_rgb_f(HUD_WHITE), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
					ALLEGRO_ALIGN_CENTER, _optionsText[0].c_str());

		if (_selected[1])
			al_draw_text(_optionsFont, al_map_rgb_f(HUD_GREEN), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 128,
				ALLEGRO_ALIGN_CENTER, _optionsText[1].c_str());
		else
			al_draw_text(_optionsFont, al_map_rgb_f(HUD_WHITE), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 128,
				ALLEGRO_ALIGN_CENTER, _optionsText[1].c_str());

		al_flip_display();
	}
}

bool Menu::isMouseOverText(ALLEGRO_FONT* font, const string& text, const int index)
{
	int textW = al_get_text_width(font, text.c_str());
	int textH = al_get_font_line_height(font);

	if ((_mouseX >= _optionsTextX[index] && _mouseX <= _optionsTextX[index] + textW) &&
		(_mouseY >= _optionsTextY[index] && _mouseY <= _optionsTextY[index] + textH))
		return true;
	else
		return false;
}

void Menu::show()
{
	al_flush_event_queue(_queue);

	while (!_started && !_quited)
	{
		float elapsed = al_get_time() - _timeAtLastFrame;
		_timeAtLastFrame = al_get_time();

		input();
		update(elapsed);
		draw();
	}
}