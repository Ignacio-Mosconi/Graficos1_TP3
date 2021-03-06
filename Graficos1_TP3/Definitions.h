#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Display Settings
#define GAME_TITLE "The Space Wars"
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define FRAME_TIME 1.0 / 60
#define TIMEOUT 1.0 / 120


// Audio Settings
#define GAME_SAMPLES 5
#define MENU_SAMPLES 1

// Menu Settings
#define MENU_OPTIONS 2
#define MENU_TITLE_SIZE 150
#define MENU_OPTIONS_SIZE 100

// Player Attributes
#define PLAYER_WIDTH 128
#define PLAYER_INITIAL_X 64
#define PLAYER_HEIGHT 90
#define PLAYER_MIN_X 32
#define PLAYER_MAX_X 1568
#define PLAYER_MIN_Y 90
#define PLAYER_MAX_Y 865
#define PLAYER_SPEED 500
#define PLAYER_LIVES 3
#define PLAYER_SHOT_COOLDOWN 0.33

// Bullet Attributes
#define BULLETS 10
#define BULLET_WIDTH 48
#define BULLET_SPEED 1000
#define BULLET_HEIGHT 18
#define BULLET_MIN_X 0
#define BULLET_MAX_X 1600

// Enemy Attributes
#define SPACESHIPS 5
#define SPACESHIP_SCORE 10
#define SPACESHIP_MIN_SPEED 300
#define SPACESHIP_MAX_SPEED 600
#define SPACESHIP_WIDTH 128
#define SPACESHIP_HEIGHT 90
#define SPACESHIP_MIN_X 0
#define SPACESHIP_MAX_X 1600
#define SPACESHIP_MIN_Y 122
#define SPACESHIP_MAX_Y 833
#define SPACESHIP_MIN_SPAWN_TIME 3
#define SPACESHIP_MAX_SPAWN_TIME 6
#define SPACESHIP_MIN_WAVE_AMPLITUDE 8
#define SPACESHIP_MAX_WAVE_AMPLITUDE 32
#define SPACESHIP_WAVE_FREQUENCY  3 * 3.1415927

// Asteroid Attributes
#define ASTEROIDS 7
#define ASTEROID_SCORE 5
#define ASTEROID_MIN_SPEED 150
#define ASTEROID_MAX_SPEED 300
#define ASTEROID_WIDTH 64
#define ASTEROID_HEIGHT 45
#define ASTEROID_MIN_X 0
#define ASTEROID_MAX_X 1600
#define ASTEROID_MIN_Y 90
#define ASTEROID_MAX_Y 865
#define ASTEROID_MIN_SPAWN_TIME 1
#define ASTEROID_MAX_SPAWN_TIME 3

// HUD Attributes
#define HUD_FONT_SIZE 52
#define HUD_TEXT_POS_Y 22
#define HUD_WHITE 0.75, 0.75, 0.75
#define HUD_RED 0.75, 0.15, 0.15
#define HUD_GREEN 0.15, 0.75, 0.15
#define HUD_BLUE 0.15, 0.15, 0.75
#define HUD_YELLOW 0.65, 0.45, 0.15

// Image Paths
#define PLAYER_PATH "Assets/Images/Player.png"
#define BULLET_PATH "Assets/Images/Bullet.png"
#define ENEMY_PATH "Assets/Images/Enemy.png"
#define ASTEROID_PATH "Assets/Images/Asteroid.png"
#define SPACESHIP_PATH "Assets/Images/Spaceship.png"
#define ICON_PATH "Assets/Images/Icon.png"

// Sound Paths

#define MUSIC_PATH "Assets/Sounds/Music.wav"
#define SELECT_SOUND_PATH "Assets/Sounds/Select.wav"
#define SHOT_SOUND_PATH "Assets/Sounds/Shot.wav"
#define EXPLOSION_SOUND_PATH "Assets/Sounds/Explosion.wav"
#define HIT_SOUND_PATH "Assets/Sounds/Hit.wav"
#define GAME_OVER_SOUND_PATH "Assets/Sounds/Game Over.wav"

// Font Paths
#define HUD_FONT_PATH "Assets/Fonts/Space Ranger.ttf"
#define MENU_FONT_PATH "Assets/Fonts/Space Ranger Laser.ttf"

#endif
