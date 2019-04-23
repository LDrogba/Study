/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <windows.h>
#include "Maze.h"

int Heading_X[ 9 ] = { 0, 0,+1, 0, 0, 0, 0, 0,-1 };
int Heading_Y[ 9 ] = { 0,-1, 0, 0,+1, 0, 0, 0, 0 };
int Mask[ 9 ]      = {
    0,
    eDirection_Down | eDirection_Down << 4,
    eDirection_Left | eDirection_Left << 4,
    0,
    eDirection_Up | eDirection_Up << 4,
    0,
    0,
    0,
    eDirection_Right | eDirection_Right << 4
};

int IsKey( int Code )
{
    return GetKeyState( Code ) & 0x8000;
}

int CellIdx()
{
    return g_PtX + NumCells * g_PtY;
}

////////////////////////////////////////////////////////////////////////////
int RandomInt()
{
    return rand() % NumCells;
}

int RandomInt4()
{
    return rand() % 4;
}

////////////////////////////////////////////////////////////////////////////
bool IsDirValid( eDirection Dir )
{
    int NewX = g_PtX + Heading_X[ Dir ];
    int NewY = g_PtY + Heading_Y[ Dir ];

    if (!Dir || NewX < 0 || NewY < 0 || NewX >= NumCells || NewY >= NumCells) return false;

    return !g_Maze[ NewX + NumCells * NewY ];
}




eDirection GetDirection()
{

    eDirection Dir =  1 << RandomInt4();

    while (true)
    {
	for (int x = 0; x < 4; x++)
	{
	    if (IsDirValid( Dir )) { return Dir; }

	    Dir = Dir << 1;

	    if (Dir > eDirection_Left) { Dir = eDirection_Up; }
	}

	Dir = ( g_Maze[ CellIdx() ] & 0xf0 ) >> 4;

	// nowhere to go
	if (!Dir) return eDirection_Invalid;

	g_PtX += Heading_X[ Dir ];
	g_PtY += Heading_Y[ Dir ];

	Dir = 1 << RandomInt4();
    }
}

void GenerateMaze()
{
    int Cells = 0;

    for (eDirection Dir = GetDirection(); Dir != eDirection_Invalid; Dir = GetDirection())
    {
	// a progress indicator, kind of
	if (++Cells % 1000 == 0) printf( "." );

	g_Maze[ CellIdx() ] |= Dir;

	g_PtX += Heading_X[ Dir ];
	g_PtY += Heading_Y[ Dir ];

	g_Maze[ CellIdx() ] = Mask[ Dir ];
    }

    printf("\n");
}

void CreateMaze()
{

    srand(time(0));

    g_Tab[0][0].player = 1;

    int exit_x = rand()%2+5;
    int exit_y = rand()%2+5;

    g_Tab[exit_y][exit_x].exit = 1;

    for (int y = 0; y < NumCells; y++)
    {
		for (int x = 0; x < NumCells; x++)
		{
		    char v = g_Maze[ y * NumCells + x ];

			Cell tmp;
			tmp = g_Tab[y][x];

		    if (!( v & eDirection_Up )){
                tmp.door += 1;
      //          printf("%d ", tmp.door);
		    }

            tmp.door = tmp.door<<1;

		    if (!( v & eDirection_Right )){

                tmp.door += 1;
		    }
		    tmp.door = tmp.door<<1;
		    if (!( v & eDirection_Down )){
                tmp.door += 1;
		    }
		    tmp.door = tmp.door<<1;
		    if (!( v & eDirection_Left )){
                tmp.door += 1;
		    }

            int ifchest = rand()%8;
            int ifmonster = rand()%6;

            if(ifchest==1){
                tmp.chest = malloc(sizeof(ChestStr));
                tmp.chest->opened = 0;
                tmp.chest->IsPotion = rand()%2;
                tmp.chest->IsSward = 1;//rand()%2;
                if(tmp.chest->IsSward == 1)
                    tmp.chest->SwardPower = rand()%50;
                else
                    tmp.chest->SwardPower = 0;
                }

            else
                tmp.chest = NULL;

            if(ifmonster==1)
                tmp.monster = 1;
            else
                tmp.monster = 0;


            g_Tab[y][x] = tmp;
		}
    }
}
