//Lukasz Wojdon
//zadanie 2 lista 6



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT 100

#define z 100

struct Samochod
{
	char marka[MAX_TEXT+1];
	char model[MAX_TEXT+1];
	unsigned int rok;
	unsigned int pojemnosc;
};

struct SDane
{
	struct Samochod* Baza;
	int Ilosc_Aut;
	int Max_Ilosc;
};

void Dane__Init(struct SDane* Dane)
{
	Dane->Max_Ilosc = 1;
	Dane->Ilosc_Aut = 0;
	
	Dane->Baza = malloc(sizeof(struct Samochod)*Dane->Max_Ilosc);
}

void Dane__Powieksz(struct SDane* Dane, int Ile)
{
	struct Samochod* nowa_baza = malloc(sizeof(struct Samochod)*(Dane->Max_Ilosc + Ile));
	memcpy(nowa_baza, Dane->Baza, sizeof(struct Samochod)*Dane->Ilosc_Aut);
	free(Dane->Baza);
	Dane->Baza = nowa_baza;
	Dane->Max_Ilosc+=Ile;
}

void Dane__Dodaj(struct SDane* Dane, struct Samochod* Nowy_Sam)
{
	if(Dane->Max_Ilosc==Dane->Ilosc_Aut)
		Dane__Powieksz(Dane, 10);
	
	int n = Dane->Ilosc_Aut;
	Dane->Baza[n].marka[MAX_TEXT] = '\0';	
	Dane->Baza[n].model[MAX_TEXT] = '\0';	
	
	strncpy(Dane->Baza[n].marka, Nowy_Sam->marka, MAX_TEXT);
	strncpy(Dane->Baza[n].model, Nowy_Sam->model, MAX_TEXT);
	Dane->Baza[n].pojemnosc = Nowy_Sam->pojemnosc;
	Dane->Baza[n].rok = Nowy_Sam->rok;
	
	Dane->Ilosc_Aut++;	
}

void Dane__Wczytaj(struct SDane* Dane, char* Nazwa_Pliku)
{

//	printf("rozpoczeto otwieranie\n");

	FILE* plik=fopen(Nazwa_Pliku, "r");
	if(plik==NULL)
	{
		printf("blad\n");
		return;
	}
	
	struct Samochod tmp;
	while(!feof(plik))
	{
		int rc = fscanf(plik, "%s %s %u %u", tmp.marka, tmp.model, &tmp.rok, &tmp.pojemnosc);
		
		if(rc!=4)
			break;			
			
		Dane__Dodaj(Dane, &tmp);
		
	}
	
	
	fclose(plik);	
}


int MySort_Marka(const void* a, const void* b)
{
	const struct Samochod* ptrElem1 = a;
	const struct Samochod* ptrElem2 = b;
	
	return strncmp(ptrElem1->marka, ptrElem2->marka, MAX_TEXT);			
}

int MySort_Model(const void* a, const void* b)
{
	const struct Samochod* ptrElem1 = a;
	const struct Samochod* ptrElem2 = b;
	
	return strncmp(ptrElem1->model, ptrElem2->model, MAX_TEXT);			 
}

int MySort_Rok(const void* a, const void* b)
{
	const struct Samochod* ptrElem1 = a;
	const struct Samochod* ptrElem2 = b;
	
	if (ptrElem1->rok>ptrElem2->rok)
		return 1;
	else 
	if (ptrElem1->rok==ptrElem2->rok)
		return 0;
	else
		return -1;
}

void Dane__Sortowanie(struct SDane* Dane, char Typ)
{
	int (*pf)(const void * p1, const void * p2);
	switch(Typ)
	{
		case 'r':
			pf=MySort_Rok;
			break;
		case 'm':
			pf=MySort_Model;
			break;
		case 'p':
			pf=MySort_Marka;
			break;
		default:
			printf("BLAD\n");
			return;	
	}
	
	qsort(Dane->Baza, Dane->Ilosc_Aut, sizeof(Dane->Baza[0]), pf);
			
}

void Dane__Wypisz(struct SDane* Dane)
{
		for(int i=0; i<Dane->Ilosc_Aut; i++)
		printf("%s %s %d %d\n", Dane->Baza[i].marka, Dane->Baza[i].model, Dane->Baza[i].rok, Dane->Baza[i].pojemnosc);
}


int main(int argc, char *argv[]) 
{
	if(argc<2)
	{
		printf("za malo danych");
		return 1;
	}
	
	struct SDane Dane;
	Dane__Init(&Dane);
	Dane__Wczytaj(&Dane, argv[1]);
	Dane__Sortowanie(&Dane, *argv[2]);
	Dane__Wypisz(&Dane);	
//	printf("poszlo\n");	
	
	return 0;
}
