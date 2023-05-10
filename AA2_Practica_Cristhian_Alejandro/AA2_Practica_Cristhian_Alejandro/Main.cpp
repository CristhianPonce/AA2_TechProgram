#include "MyRoom.h"
#include "Player.h"
#include "Windows.h"
#include <iostream>
#include <fstream>
using namespace std;


int main()
{

	SCENE currentScene = SCENE::PASILLO;
	char wall = 'X';
	char door = 'P';
	char p_icon = '^';
	int score = 0, info = 9;


	Link link(p_icon, score);

	//leer fichero
	int anchuraSala;
	int alturaSala;
	int enemigosSala;
	char semicolon;

	std::ifstream config("config.txt");

	if (config.is_open())
	{
		config >> anchuraSala >> semicolon >> alturaSala >> semicolon >> enemigosSala >> semicolon;
	}
	MyRoom Class = MyRoom(anchuraSala, alturaSala, enemigosSala, link);

	if (config.is_open())
	{
		config >> anchuraSala >> semicolon >> alturaSala >> semicolon >> enemigosSala >> semicolon;
	}
	MyRoom Pasillo = MyRoom(anchuraSala, alturaSala, enemigosSala, link);

	if (config.is_open())
	{
		config >> anchuraSala >> semicolon >> alturaSala >> semicolon >> enemigosSala;
	}
	MyRoom Cafe = MyRoom(anchuraSala, alturaSala, enemigosSala, link);
	config.close(); //CERRAMOS EL ARCHIVO
	
	// game loop
	while(currentScene != SCENE::ENDGAME)
	{

		system("cls");

		//INPUTS
		link.movement();
		link.UpdateMovement();

		char myAction;
		if (currentScene == SCENE::CLASE)
		{
			Class.Print();
			cout << "\nSala actual: Clase" << endl;
			cout << "Introduce sala: ";
			cin >> myAction;
			if (myAction == 'N')
				currentScene = SCENE::CAFE;
		}

		else if (currentScene == SCENE::PASILLO)
		{
			Pasillo.Print();
			cout << "\nSala actual: Pasillo" << endl;
			cout << "Introduce sala: ";
			cin >> myAction;
			if (myAction == 'N')
				currentScene = SCENE::CLASE;
		}

		else if (currentScene == SCENE::CAFE)
		{
			Cafe.Print();
			cout << "\nSala actual: Cafeteria" << endl;
			cout << "Introduce sala: ";
			cin >> myAction;
			if (myAction == 'N')
				currentScene = SCENE::PASILLO;
		}
		Sleep(60);
	}

	if (currentScene == SCENE::ENDGAME)
	{
		//testRoom.printSceneText(currentScene); 
		cout << endl << " YOUR SCORE IS: " << link.get_score() << endl << endl;
	}
}