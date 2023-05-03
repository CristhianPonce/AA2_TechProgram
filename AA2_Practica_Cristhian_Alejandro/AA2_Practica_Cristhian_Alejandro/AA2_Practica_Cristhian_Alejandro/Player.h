#include <stdio.h>
#include <iostream>
#define MAX_POS 25
#pragma once
//CONTROL Y LOGICA DEL PLAYER

class Link {
private: //DEFINIMOS LOS ATRIBUTOS DE LINK
	char p_icon;
	int** p_pos;
	int m_score;

public: //AHORA LOS METODOS
		
	Link(char icon, int& score)
	{
		p_icon = icon;
		m_score = score;
		p_pos = new int* [MAX_POS];

		for (int i = 0; i < MAX_POS; i++)
		{
			p_pos[i] = new int[MAX_POS];
		}
	}

	~Link()
	{}

	int get_score()
	{
		return m_score;
	}
};
