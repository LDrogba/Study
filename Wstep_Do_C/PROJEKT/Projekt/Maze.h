/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/


#ifndef Mazegen
#define Mazegen

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "Maze_date.h"

#define NumCells 8

// return the current index in g_Maze
int CellIdx();

int IsKey( int Code );

////////////////////////////////////////////////////////////////////////////
int RandomInt();

int RandomInt4();

////////////////////////////////////////////////////////////////////////////8
bool IsDirValid( eDirection Dir );

eDirection GetDirection();

void GenerateMaze();
void CreateMaze();

void ClearTab();

#endif
