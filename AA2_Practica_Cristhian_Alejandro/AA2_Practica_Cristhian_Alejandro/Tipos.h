#pragma once

enum class SCENE { CLASE, PASILLO, CAFE, ENDGAME };

enum class Celda
{
	PARED = 'X',
	VACIO = ' ',
	PUERTA = 'P',
	PLAYER_UP = '^',
	PLAYER_DOWN = 'V',
	PLAYER_LEFT = '<',
	PLAYER_RIGHT = '>'
};

enum class PlayerOrientation
{
	UP = '^',
	DOWN = 'V',
	LEFT = '<',
	RIGHT = '>'
};

struct Vector2
{
	int x, y;

	Vector2() : x(1), y(1) {}
	Vector2(int x, int y) : x(x), y(y) {}
};