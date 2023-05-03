#include "Player.h"
#include <fstream>
using namespace std;

#define INFO 9
#pragma once
//CONTROL Y LÓGICA DE UNA SALA

enum class SCENE { CLASE, PASILLO, CAFE, BATTLE, ENDGAME }; //CONTROLAR LAS ESCENAS CON UN ENUM CLASS


class Sala {
private:
	SCENE m_scene;
	char m_wall;
	char m_door;
	int* dimensions;


public:

	Sala(SCENE scene, char wall, char door, int info) //CONSTRUCTOR DE SALA
	{
		m_scene = scene;
		m_wall = wall;
		m_door = door;
		dimensions = new int[info];

		int fileData; //DATOS A LEER DEL ARCHIVO
		int* gameData = new int[info]; //ARRAY DINÁMICO PARA GUARDAR LA INFORMACIÓN DE CONFIG.TXT
		int iterator = 0;

		ifstream Config("config.txt");
		Config.is_open(); //ABRIMOS EL ARCHIVO

		if (Config.is_open())
		{
			while (Config >> fileData)
			{
				gameData[iterator] = fileData; //CADA VEZ QUE SE LEE UN INT, LO GUARDA EN gameData SUB iterator
				dimensions[iterator] = gameData[iterator]; //ASIGNAR EL VALOR DE gameData A dimensions, MIEMBRO DE LA CLASE
				iterator++; //CUANDO SE LEE UN INT, iterator AUMENTA
			}
		}

		Config.close(); //CERRAMOS EL ARCHIVO
	}

	~Sala()
	{}

	//GETTERS DE LA CLASE
	int get_X_class()
	{
		return dimensions[0];
	}

	int get_Y_class()
	{
		return dimensions[1];
	}

	int get_enemies_class()
	{
		return dimensions[2];
	}


	//GETTERS DEL PASILLO
	int get_X_corridor()
	{
		return dimensions[3];
	}

	int get_Y_corridor()
	{
		return dimensions[4];
	}

	int get_enemies_corridor()
	{
		return dimensions[5];
	}


	//GETTERS DE LA CAFETERÍA
	int get_X_cafe()
	{
		return dimensions[6];
	}

	int get_Y_cafe()
	{
		return dimensions[7];
	}

	int get_enemies_cafe()
	{
		return dimensions[9];
	}


	//FUNCIONES
	void PaintClass()
	{
		SCENE scene = SCENE::CLASE;
		char wall = 'X';
		char door = 'P';
		char p_icon = '^';
		int score = 0;
		const int info = INFO;
		Sala Sala(scene, wall, door, info);
		Link Link(p_icon, score);

	
		for (int k = 0; k < Sala.get_Y_class(); k++)
		{
			if (k == 0 || k == Sala.get_Y_class() - 1)
			{
				for (int m = 0; m < Sala.get_X_class(); m++)
				{
					cout << wall << wall << wall << wall << wall << wall << wall;
				}
				cout << endl;
			}

			else
			{

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < Sala.get_X_class(); j++)
					{

						if ((i == 0 || i == 2))
						{
							if (j == 0)
								cout << wall << "     ";

							else if (j != 0 && j != Sala.get_X_class() - 1)
								cout << "       ";

							else if (k == 1 && j == Sala.get_X_class() - 1)
								cout << "       " << door;

							else if (k != 1 && j == Sala.get_X_class() - 1)
								cout << "       " << wall;
						}

						else if (i == 1)
						{
							if (j == 0)
								cout << wall << "  " << p_icon << "  ";

							else if (j != 0 && j != Sala.get_X_class() - 1)
								cout << "    " << p_icon << "  ";

							else if (j == Sala.get_X_class() - 1 && k == 1)
								cout << "    " << p_icon << "  " << door;

							else if (j == Sala.get_X_class() - 1 && k != 1)
								cout << "    " << p_icon << "  " << wall;
						}


					}
					cout << endl;
				}
			}
		}
		cout << endl << "	AULA ACTUAL: CLASE" << endl << endl;
		cout << "   CONTROLES:" << endl << endl << "	KEY_UP: ARRIBA" << endl;
		cout << "	KEY_LEFT: IZQUIERDA" << endl;
		cout << "	KEY_RIGHT: DERECHA" << endl;
		cout << "	KEY_DOWN: ARRIBA" << endl << endl;
		cout << "INTRODUCE TU PROXIMO MOVIMIENTO: ";
	}
	


	void PaintCorridor()
	{
		SCENE scene = SCENE::CLASE;
		char wall = 'X';
		char door = 'P';
		char p_icon = '^';
		int score = 0;
		const int info = INFO;
		Sala Sala(scene, wall, door, info);
		Link Link(p_icon, score);


		for (int k = 0; k < Sala.get_Y_corridor(); k++)
		{
			if (k == 0 || k == Sala.get_Y_corridor() - 1)
			{
				for (int m = 0; m < Sala.get_X_corridor(); m++)
				{
					cout << wall << wall << wall << wall << wall << wall << wall;
				}
				cout << endl;
			}

			else
			{

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < Sala.get_X_corridor(); j++)
					{

						if ((i == 0 || i == 2))
						{
							if (j == 0)
								cout << wall << "     ";

							else if (j != 0 && j != Sala.get_X_corridor() - 1)
								cout << "       ";

							else if (k == 1 && j == Sala.get_X_corridor() - 1)
								cout << "       " << door;

							else if (k != 1 && j == Sala.get_X_corridor() - 1)
								cout << "       " << wall;
						}

						else if (i == 1)
						{
							if (j == 0)
								cout << wall << "  " << p_icon << "  ";

							else if (j != 0 && j != Sala.get_X_corridor() - 1)
								cout << "    " << p_icon << "  ";

							else if (j == Sala.get_X_corridor() - 1 && k == 1)
								cout << "    " << p_icon << "  " << door;

							else if (j == Sala.get_X_corridor() - 1 && k != 1)
								cout << "    " << p_icon << "  " << wall;
						}


					}
					cout << endl;
				}
			}
		}
		cout << endl << "	AULA ACTUAL: CLASE" << endl << endl;
		cout << "   CONTROLES:" << endl << endl << "	KEY_UP: ARRIBA" << endl;
		cout << "	KEY_LEFT: IZQUIERDA" << endl;
		cout << "	KEY_RIGHT: DERECHA" << endl;
		cout << "	KEY_DOWN: ARRIBA" << endl << endl;
		cout << "INTRODUCE TU PROXIMO MOVIMIENTO: ";
	}
	void PaintCafe(SCENE scene, char wall, char door, int info); //PINTAR LA CAFETERÍA
	void PrintEnemies(SCENE scene, char wall, char door, int info); //PRINTEAR LOS ENEMIGOS EN LAS DISTINTAS ESCENAS

	bool isEmpty(); //COMPROBAR QUE NO SE PRINTEE UN ENEMIGO ENCIMA DEL OTRO
};