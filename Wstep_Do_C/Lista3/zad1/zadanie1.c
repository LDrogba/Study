//Lukasz Wojdon
//Zadanie 1

#include <stdio.h>
#include <stdbool.h>
typedef unsigned short TypDaty;
char *DniTyg[]={"0", "pon", "wto", "sro", "czw", "pia", "sob", "nie"};
char *Mies[]={"0","Styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien"};
char *NazwaRok[]={"0","malpy", "koguta", "swini", "szczura", "tygrysa", "krolika", "smoka", "weza", "konia", "owcy", "kozy", "psa"};

#define MASKA_DZIENTYG 7
#define MASKA_DZIENMIES (31<<3)
#define MASKA_MIES (15<<8)	
#define MASKA_ROK (15<<12)

int DzienTyg(TypDaty data)
{
    return data&7;
}

int DzienMies(TypDaty data)
{
    return (data>>3)&31;
}

int Miesiac(TypDaty data)
{
    return (data>>8)&15;
}

int Rok(TypDaty data)
{
    return (data>>12)&15;
}

void WypiszDate(TypDaty data)
{
    char* dt = DniTyg[DzienTyg(data)];
    char* mies = Mies[Miesiac(data)];
    char* rok = NazwaRok[Rok(data)];
    int dzienmiesiaca = DzienMies(data), rok1=Rok(data);

    printf("%s, %d %s, rok %s(%d)\n", dt, dzienmiesiaca, mies, rok, rok1);
}

bool CzyDobra(TypDaty data)
{
	if( ((Miesiac(data)==4 || Miesiac(data)== 6 || Miesiac(data) == 9 || Miesiac(data)== 11) && (DzienMies(data)>30))
	 || ((Miesiac(data)==2) && (DzienMies(data)>=29)))
		return 0;
	else
		return 1;		
}

TypDaty BladDaty(TypDaty data)
{
	TypDaty bityBledu=0;
	
	if(DzienTyg(data)==0)
		bityBledu |= MASKA_DZIENTYG;
			  
    if(DzienMies(data)==0 || CzyDobra(data)==0)
    	bityBledu |= MASKA_DZIENMIES;
      
    if(Miesiac(data)==0 || CzyDobra(data)==0 || Miesiac(data)>12)
    	bityBledu |= MASKA_MIES;
    
	if(Rok(data)==0 || Rok(data)>12)
    	bityBledu |= MASKA_ROK;
	
	return bityBledu;
}

void ktory_bledny( TypDaty liczba)
{
	printf("blad");

	if(DzienTyg(liczba)!=0)
		printf(" dnia tygodnia,");

	if(DzienMies(liczba)!=0)
		printf(" dnia miesiaca,");

	if(Miesiac(liczba)!=0)
		printf(" miesiaca,");

	if(Rok(liczba)!=0)
		printf(" roku");
}

int main()
{
	TypDaty Data;
	
	scanf("%hu", &Data);

	while(Data!=0)
	{   
	    if(!BladDaty(Data))
	    	WypiszDate(Data);
	    else
	    	ktory_bledny(BladDaty(Data));

	    printf("\n");
		scanf("%hu", &Data);
	}	
}
