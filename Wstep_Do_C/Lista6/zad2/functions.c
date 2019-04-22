#include "functions.h"

PtList_Ptr Read( FILE* Plik)
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
		{
			if(feof(Plik))
				return First;
			else
				continue;
		}
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

void Wypisz(PtList_Ptr List)
{		
	printf("%f %f %f %s", List->x, List->y, List->z, List->Nazwa);
	
	if(List->next==NULL)
		return;
	else
		Wypisz(List->next);
}
PtList_Ptr Last(PtList_Ptr St)
{
	while(St->next!=NULL)
		St=St->next;
		
	return St;
}

void Wypisz_Pt(PtList_Ptr List,char* com_par)
{
	int cp=atoi(com_par);
	int i=1;
	while(i!=cp)
	{
		List=List->next;
		i++;		
	}
	printf("%f %f %f %s", List->x, List->y, List->z, List->Nazwa);
}

void Wypisz_Wieksze(PtList_Ptr List, char* com_par)
{
	int cp=atoi(com_par);
	
	while(1)
	{
	if(List->x>cp)
		printf("%f %f %f %s", List->x, List->y, List->z, List->Nazwa);
	
	if(List->next==NULL)
		return;
	else
		List=List->next;
	}
}

void Wypisz_Szukany(PtList_Ptr List, char* com_par)
{
	while(1)
	{
		if(strstr(List->Nazwa, com_par)!=NULL)
			printf("%f %f %f %s", List->x, List->y, List->z, List->Nazwa);
		
		if(List->next==NULL)
			return;
		else
			List=List->next;
	}
}

