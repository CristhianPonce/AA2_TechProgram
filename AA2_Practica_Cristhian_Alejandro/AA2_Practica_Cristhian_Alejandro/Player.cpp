#include "Player.h"


int Link::get_score()
{
	return m_score;
}

Vector2 Link::get_pos()
{
	return position;
}

void Link::movement()
{
	if (GetAsyncKeyState(VK_UP))
	{
		// move up
		position = Vector2(position.x, position.y-1);
		character = PlayerOrientation::UP;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		//move down
		position = Vector2(position.x, position.y + 1);
		character = PlayerOrientation::DOWN;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		//move right
		position = Vector2(position.x + 1, position.y);
		character = PlayerOrientation::RIGHT;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		//move left
		position = Vector2(position.x - 1, position.y);
		character = PlayerOrientation::LEFT;
	}
}

void Link::UpdateMovement()
{
	position = nextMovement;
	nextMovement = position;
}

Vector2 Link::GetNextmovement()
{
	return nextMovement;
}

char Link::GetOrientation()
{
	return (char)character;
}
