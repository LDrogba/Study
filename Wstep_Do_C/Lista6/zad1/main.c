//Lukasz Wojdon
//Zadanie 1 Lista 7

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


struct PtList* Read( FILE* Plik)
{
	struct PtList* First=NULL;
	struct PtList* tail;
	struct PtList* new_el=NULL;
	struct PtList tmp;
	char temp[256];			
	memset(&tmp, 0, sizeof(struct PtList));

	do
	{
		int error=0;
		
		if(fscanf(Plik, "%f %f %f", &tmp.x, &tmp.y, &tmp.z)!=3)
			error++;
		if(fgets(temp, sizeof(temp), Plik)==NULL)
			error++;
		
		if(error!=0)
			if(feof(Plik))
				return First;
		else
			continue;
					
		new_el = malloc(sizeof(struct PtList));
	
		*new_el=tmp;
		strncpy(new_el->Nazwa, temp, 36);
		new_el->next=NULL;

		if(First==NULL)
		{
			First = tail = new_el;
		}
		else
		{
			tail->next = new_el;
			tail = new_el;
		}
	
	}while(strncmp(new_el->Nazwa," KONIEC",7)!=0);

	return First;
}

void Wypisz(struct PtList* Ptr)
{		
	printf("%f %f %f %s", Ptr->x, Ptr->y, Ptr->z, Ptr->Nazwa);
	
	if(Ptr->next==NULL)
		return;
	else
		Wypisz(Ptr->next);
}

struct PtList* Last(struct PtList* St)
{
	while(St->next!=NULL)
		St=St->next;
		
	return St;
}

int Count(struct PtList* St)
{
	int nr=1;
	while(St->next!=NULL)
	{
		nr++;
		St=St->next;	
	}
		
	return nr;
}

int main() 
{
	int nr;
	struct PtList* list_first, *list_last;
	char Anwr[20];
	
	list_first=Read(stdin);
	
	if(list_first==NULL)
	{
		printf("brak danych");
		return 0;
	}
	
	list_last=Last(list_first);
	nr=Count(list_first);
	
	printf("Ilosc wczytanych elementow: %d\n", nr);
	printf("%f %f %f %s", list_first->x, list_first->y, list_first->z, list_first->Nazwa);
	printf("%f %f %f %s\n", list_last->x, list_last->y, list_last->z, list_last->Nazwa);
	scanf("%s", Anwr);
	
	if(strcmp(Anwr, "tak")==0)
		Wypisz(list_first);
	
	return 0;
}
