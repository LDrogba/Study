#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Wspol
{
	float lat;
	float lon;
	struct Wspol* Next;
};

typedef struct Wspol Wsp;

Wsp Pobierz(char* trkpt)
{	
	Wsp tmp;
	char* ptr_lon;
	sscanf(trkpt+12, "%f", &tmp.lat);
	
	ptr_lon=strstr(trkpt, "lon");
	
	sscanf(ptr_lon+5, "%f", &tmp.lon);
	tmp.Next=NULL;
	
	return tmp;
}

Wsp* Wczytaj(FILE *Plik)
{
	Wsp* lista = NULL;
	Wsp* ostatni = NULL;
	
	char line[256];
	char* ptr_trkpt;

	while(fgets(line, sizeof(line), Plik))
	{
		ptr_trkpt=strstr(line,"<trkpt");
		if(ptr_trkpt!=0)
		{
			Wsp nowy=Pobierz(ptr_trkpt);			
			Wsp* nowy_ptr=malloc(sizeof(Wsp));
						
			if(lista==NULL)
			{
				lista=nowy_ptr;		
			}
			else
			{	
				ostatni->Next=nowy_ptr;
			}

			ostatni=nowy_ptr;				
			*ostatni=nowy;				
		}
	}
	return lista;
}


void Wypisz(Wsp* lista)
{
	do
	{
		printf("%f %f\n", lista->lat, lista->lon);
		lista=lista->Next;
	}
	while(lista!=NULL);
}

float Dystans(Wsp* lista)
{
	float dyst=0.0, x1, x2, y1, y2;

	while(lista->Next!=NULL)
	{
		x1=lista->lat;
		y1=lista->lon;
		x2=lista->Next->lat;
		y2=lista->Next->lon;
		dyst+=(sqrt((x2-x1)*(x2-x1)+(cos((x1*3.14)/180)*(y1-y2))*(cos((x1*3.14)/180)*(y1-y2)))*((40075.704)/360));
		lista=lista->Next;
	}
	
	return dyst;
}

int Wiersz(FILE* Plik)
{
	int ile=0;
	char line[256];
	
	while(fgets(line, sizeof(line), Plik))
		ile++;
	
	return ile;
}

int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("brak danych");
		return 0;
	}
	
	const char *wejscie= argv[1];
	FILE *Plik = fopen(wejscie, "r");
	
	if(Plik==NULL)
	{
		printf("blad wczytania");
		return 0;
	}
	
	printf("Wczytano pomyslnie\n\n");
	
	Wsp* lista = Wczytaj(Plik);
	
	if(lista==NULL)
	{
		printf("brak danych");
		return 0;
	}
	
	printf("DYSTANS: %f\n", Dystans(lista));
	
	fseek(Plik, 0, SEEK_END);
	printf("DLUGOSC W BAJTACH: %ld\n", ftell(Plik));
	
	fseek(Plik, 0, SEEK_SET);
	printf("ILOSC WIERSZY: %d", Wiersz(Plik));
	fclose(Plik);
	
	return 0;
}
