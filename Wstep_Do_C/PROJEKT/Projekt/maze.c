
/**
* \file Maze.cpp
* \brief
*
* Depth-first Search Random Maze Generator
*
* \version 1.0.0
* \date 27/05/2014
* \author Sergey Kosarevsky, 2014
* \author support@linderdaum.com   http://www.linderdaum.com   http://blog.linderdaum.com
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define NumCells 15

typedef struct _cell{
	bool left;
	bool right;
	bool down;
	bool up;
}Cell;

///////////////// User selectable parameters ///////////////////////////////


////////////////////////////////////////////////////////////////////////////

const char* Version = "1.0.0 (27/05/2014)";

int CellSize;

unsigned char* g_Maze = NULL;

// current traversing position
int g_PtX;
int g_PtY;

// return the current index in g_Maze
int CellIdx()
{
    return g_PtX + NumCells * g_PtY;
}

////////////////////////////////////////////////////////////////////////////
int RandomInt()
{
    //return  dis( gen );
    return rand() % NumCells;
}

int RandomInt4()
{
    // return  dis4( gen );
    return rand() % 4;
}

////////////////////////////////////////////////////////////////////////////

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

	printf("%d", g_Maze[ CellIdx() ] |= Dir);

	printf("%d ", Dir);

	g_PtX += Heading_X[ Dir ];
	g_PtY += Heading_Y[ Dir ];

	g_Maze[ CellIdx() ] = Mask[ Dir ];
    }

    printf("\n");
}


void RenderMaze( Cell *Tab[NumCells][NumCells] )
{
    for (int y = 0; y < NumCells; y++)
    {
		for (int x = 0; x < NumCells; x++)
		{
		    char v = g_Maze[ y * NumCells + x ];

		    int nx = x * CellSize;
		    int ny = y * CellSize;

			Cell *tmp;

			tmp = Tab[y][x];

		    if (!( v & eDirection_Up )) tmp->up = true;
		    if (!( v & eDirection_Right )) tmp->right = true;
		    if (!( v & eDirection_Down )) tmp->down = true;
		    if (!( v & eDirection_Left )) tmp->left = true;
		}
    }
}

void Wyswietl(Cell *Tab[NumCells][NumCells]){
	Cell* tmp = malloc(sizeof(Cell));

	for(int i=0; i<NumCells; i++)
		for(int j=0; j<NumCells; j++){
			tmp = Tab[i][j];

		}

}

void main(){
    g_Maze = malloc( NumCells* NumCells );

    printf( "Generating %d x %d maze\n", NumCells, NumCells);
    srand( (unsigned int)time( NULL ) );

    memset( g_Maze, 0, NumCells*NumCells );

	Cell Tab[NumCells][NumCells];

    g_PtX = RandomInt();
    g_PtY = RandomInt();

    GenerateMaze();

    RenderMaze(*Tab);

    Wyswietl(Tab);

    free( g_Maze );

}


