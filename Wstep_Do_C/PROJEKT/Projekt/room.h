/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <stdbool.h>
#include "Chest_str.h"

#ifndef Room

#define Room

typedef struct _cell{
	int door;
	bool player;
	bool was_player;
	ChestStr* chest;
	bool monster;
	bool exit;
}Cell;



#endif
