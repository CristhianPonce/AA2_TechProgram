#include "MyRoom.h"
#include "Tipos.h"
#include "Player.h"

MyRoom::MyRoom(int ancho, int alto, int numEnemigos, Link l) : ancho(ancho), alto(alto), numEnemigos(numEnemigos)
{
	/*char grid[w][h];

	grid[0][y] = 'X';
	grid[x][0] = 'X';
	grid[w-1][b] = 'P'
	grid[a][h-1] = 'P'
	grid[0][0] = 'X';
	grid[w-1][h-1] = 'X';
	grid[m][n] = '^';*/

	sala = new Celda * [alto];
	for (int i = 0; i < alto; i++)
	{
		sala[i] = new Celda[ancho];
	}

	for (int i = 0; i < alto; i++)
	{
		for (int j = 0; j < ancho; j++)
		{
			if (i == 1 && j == ancho - 1)
				sala[i][j] = Celda::PUERTA;
			else if (i == l.get_pos().y && j == l.get_pos().x)
			{
				if (l.GetOrientation() == '^')
					sala[i][j] = Celda::PLAYER_UP;
				else if (l.GetOrientation() == '>')
					sala[i][j] = Celda::PLAYER_RIGHT;
				else if (l.GetOrientation() == '<')
					sala[i][j] = Celda::PLAYER_LEFT;
				else if (l.GetOrientation() == 'V')
					sala[i][j] = Celda::PLAYER_DOWN;

			}
			else if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1)
				sala[i][j] = Celda::PARED;
			else
				sala[i][j] = Celda::VACIO;
		}
	}
	
}

MyRoom::~MyRoom()
{
	for (int i = 0; i < alto; i++)
	{
		delete[] sala[i];

	}
	delete[] sala;
}

bool MyRoom::CheckValidMovement(Vector2 cellPos)
{
	return sala[cellPos.x][cellPos.y] != Celda::PARED;
}

void MyRoom::UpdatePlayerPos(Vector2 pos, char orientation)
{
	sala[pos.x][pos.y] = (Celda)orientation;
}


void MyRoom::Print()
{
	for (size_t i = 0; i < alto; i++)
	{
		for (size_t j = 0; j < ancho; j++)
		{
			std::cout << " " << (char)sala[i][j];
		}
		std::cout << std::endl;
	}
}

//void MyRoom::printSceneString(SCENE s)
//{
//	switch (s)
//	{
//	case SCENE::CLASE:
//		cout << "Clase";
//		break;
//	case SCENE::PASILLO:
//		cout << "Pasillo";
//		break;
//	case SCENE::CAFE:
//		cout << "Cafeteria";
//		break;
//	case SCENE::ENDGAME:
//		cout << "YOU ARE A LEGEND, YOU JUST SAVED ALL ENTI'S STUDENTS!";
//	default:
//		break;
//	}
//}
