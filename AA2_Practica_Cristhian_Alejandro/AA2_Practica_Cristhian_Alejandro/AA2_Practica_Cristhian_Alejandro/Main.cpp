//LOGICA GENERAL DEL JUEGO, DETECCION DE INPUTS, CONTROL DE FRAMES
#include "Room.h"
#include "Windows.h"

int main() {
	SCENE currentScene = SCENE::CLASE;
	char wall = 'X';
	char door = 'P';
	char p_icon = '^';
	int score = 0;
	int info = 9;
	Sala Sala(currentScene, wall, door, info);
	Link Link(p_icon, score);
	
	while(currentScene != SCENE::ENDGAME)
	{
		char myAction;
		
		if (currentScene == SCENE::CLASE)
			Sala.PaintClass();

		else if (currentScene == SCENE::PASILLO)
			Sala.PaintCorridor();

		else if (currentScene == SCENE::CAFE)
		{ }
			//Sala.PaintCafe();

		cin >> myAction;
		if (myAction == 'R')
			currentScene = SCENE::PASILLO;

		else if (myAction == 'E')
			currentScene = SCENE::ENDGAME;
	}

	if (currentScene == SCENE::ENDGAME)
	{
		cout << "YOU ARE A LEGEND, YOU JUST SAVED ALL ENTI'S STUDENTS!" << endl << "YOUR SCORE IS: " << Link.get_score() << endl << endl;
	}
}