#pragma once
#include <iostream>
#include"Tipos.h"
#include "Player.h"

class MyRoom
{
public:

	MyRoom(int ancho, int alto, int numEnemigos, Link l);
	~MyRoom();

	bool CheckValidMovement(Vector2 cellPos);
	void UpdatePlayerPos(Vector2 pos, char orientation);
	void Print();
	//void printSceneString(SCENE s);

private:
	int ancho;
	int alto;
	int numEnemigos;
	Celda** sala;
};

