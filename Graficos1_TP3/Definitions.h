#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Display Settings
#define GAME_NAME "The Space Wars"
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define FRAME_TIME 1.0 / 60
#define TIMEOUT 1.0 / 120

// Player Attributes
#define PLAYER_WIDTH 128
#define PLAYER_HEIGHT 90
#define PLAYER_MIN_X 32
#define PLAYER_MAX_X 1568
#define PLAYER_MIN_Y 90
#define PLAYER_MAX_Y 865
#define PLAYER_SPEED 500
#define PLAYER_LIVES 3

// Bullet Attributes
#define BULLETS 10
#define BULLET_WIDTH 48
#define BULLET_HEIGHT 18
#define BULLET_MIN_X 0
#define BULLET_MAX_X 1600

// Enemy Attributes
#define ENEMIES 3
#define ENEMIES_SCORE 10
#define ENEMIES_WIDTH 128
#define ENEMIES_HEIGHT 90
#define ENEMIES_MIN_X 0
#define ENEMIES_MAX_X 1600
#define ENEMIES_MIN_Y 90
#define ENEMIES_MAX_Y 865
#define ENEMIES_MIN_SPAWN_TIME 3
#define ENEMIES_MAX_SPAWN_TIME 6

// Asteroid Attributes
#define ASTEROIDS 7
#define ASTEROIDS_SCORE 5
#define ASTEROIDS_WIDTH 64
#define ASTEROIDS_HEIGHT 45
#define ASTEROIDS_MIN_X 0
#define ASTEROIDS_MAX_X 1600
#define ASTEROIDS_MIN_Y 90
#define ASTEROIDS_MAX_Y 865
#define ASTEROIDS_MIN_SPAWN_TIME 1
#define ASTEROIDS_MAX_SPAWN_TIME 3

// HUD Attributes
#define HUD_FONT_SIZE 48
#define HUD_TEXT_POS_Y 22
#define HUD_RED 0.95, 0.15, 0.15
#define HUD_GREEN 0.15, 0.95, 0.15
#define HUD_YELLOW 0.15, 0.15, 0.95
#define HUD_YELLOW 0.65, 0.45, 0.15

// Image Paths
#define PLAYER_PATH "Assets/Images/Player.png"
#define ENEMY_PATH "Assets/Images/Enemy.png"
#define ASTEROID_PATH "Assets/Images/Asteroid.png"
#define ICON_PATH "Assets/Images/Icon.png"

// Font Paths
#define FONT_PATH "Assets/Fonts/Spaceman.ttf"

#endif
