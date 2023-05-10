#pragma once

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "Tipos.h"

#define MAX_POS 25


// Movement and player's logic
class Link 
{
private: // link atributtes
	char p_icon;
	Vector2 position;
	Vector2 oldPosition;
	Vector2 nextMovement;
	PlayerOrientation character;

	int m_score;

public: // methods
		
	Link(char icon, int& score)
	{
		character = PlayerOrientation::UP;
		p_icon = icon;
		m_score = score;
	}

	~Link()
	{}

	void movement();
	void UpdateMovement();

	//getters
	int get_score();
	Vector2 GetNextmovement();
	Vector2 get_pos();

	char GetOrientation();
};
