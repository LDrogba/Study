//Lukasz Wojdon
//Zadanie 2 lista 7
s
#include "functions.h"

int main(int argc, char* argv[]) 
{
	if(argc<3)
	{
		printf("Za malo danych!");
		return 0;
	}

	char com[9];	
	FILE* Plik=fopen(argv[1], "r");	
	struct PtList *list_first;
	
	list_first=Read(Plik);
	
	if(list_first==NULL)
	{
		printf("brak danych");
		return 0;
	}
	
	strcpy(com, argv[2]);
	printf("polecenie %s\n", com);
		
	if(strcmp(com, "wypisz")==0)
		Wypisz(list_first);
	else if(strcmp(com, "punkt")==0)
		Wypisz_Pt(list_first, argv[3]);
	else if(strcmp(com, "wyzszy")==0)
		Wypisz_Wieksze(list_first, argv[3]);
	else if(strcmp(com, "szukaj")==0)
		Wypisz_Szukany(list_first, argv[3]);
	else
	{
		printf("zle dane!");
		return 0;
	}
		
	return 0;
}
