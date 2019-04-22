#ifndef My_Functions
#define My_Functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 37

struct PtList
{
	float x;
	float y;
	float z;
	char Nazwa[MAX];
	struct PtList* next;
};

typedef struct PtList* PtList_Ptr;

void Wypisz_Szukany(PtList_Ptr List, char* com_par);
PtList_Ptr Read( FILE* Plik);
void Wypisz(PtList_Ptr List);
PtList_Ptr Last(PtList_Ptr St);
void Wypisz_Pt(PtList_Ptr List,char* com_par);
void Wypisz_Wieksze(PtList_Ptr List, char* com_par);

#endif
