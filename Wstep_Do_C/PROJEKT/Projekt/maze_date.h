/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <stdio.h>
#include "Global.h"

#ifndef Maze_date
#define Maze_date

#define NumCells 8

int CellSize;


enum kierunek
{
    up,
    right,
    down,
    left,
    base,
};

// current traversing position
int g_PtX;
int g_PtY;


typedef enum _eDirection
{
    eDirection_Invalid = 0,
    eDirection_Up      = 1,
    eDirection_Right   = 2,
    eDirection_Down    = 4,
    eDirection_Left    = 8
} eDirection;

//                   0  1  2  3  4  5  6  7  8
//                      U  R     D           L


#endif // Maze_date
