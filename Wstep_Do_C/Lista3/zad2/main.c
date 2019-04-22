//Lukasz Wojdon
//Zadanie 2

#include <stdio.h>
#include <stdbool.h>
typedef unsigned short TypDaty;
char *DniTyg[]={"0", "pon", "wto", "sro", "czw", "pia", "sob", "nie"};
char *Mies[]={"0","Styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien"};
char *NazwaRok[]={"0","malpy", "koguta", "swini", "szczura", "tygrysa", "krolika", "smoka", "weza", "konia", "owcy", "kozy", "psa"};
int	  DayOfYear[12]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

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

    printf("%s, %d %s, rok %s(%d), data: %hu\n", dt, dzienmiesiaca, mies, rok, rok1,data);
}

bool CzyDobra(TypDaty data)
{
	if( ((Miesiac(data)==4 || Miesiac(data)== 6 || Miesiac(data) == 9 || Miesiac(data)== 11) && (DzienMies(data)==31)) 
	|| ((Miesiac(data)==2) && (DzienMies(data)==29 || DzienMies(data)==30 || DzienMies(data)==31)) )
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


int Odleglosc(TypDaty d1, TypDaty d2)
{
	int day1,day2,mon1,mon2,year1,year2,dni1,dni2;
	day1 = DzienMies(d1);
	day2 = DzienMies(d2);
	mon1 = Miesiac(d1);
	mon2 = Miesiac(d2);
	year1 = Rok(d1);
	year2 = Rok(d2);
	
	dni1 = (year1-1)*365+DayOfYear[mon1]+day1;
	dni2 = (year2-1)*365+DayOfYear[mon2]+day2;
	
	if(dni1>dni2)
		return dni1-dni2;
	else
		return dni2-dni1;	
}

TypDaty ZrobDate( short dt, short dm, short m, short r)
{	
	if(dt>7 || dt<1)
		dt=0;
	
	if(dm>31 || dm<1)
		dm=0;
	
	if(m>12 || m<1)
		m=0;
	
	if(r>12 || r<1)
		r=0;	
	
	dm <<=3;
	m <<=8;
	r <<=12;
	
	return dt|dm|m|r;
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
	TypDaty Data1, Data2;
	short DzienTyg1, DzienMies1, Mies1, Rok1, DzienTyg2, DzienMies2, Mies2, Rok2;

	while(true)
	{
		scanf("%hd %hd %hd %hd %hd %hd %hd %hd", &DzienTyg1, &DzienMies1, &Mies1, &Rok1, &DzienTyg2, &DzienMies2, &Mies2, &Rok2);
		
		if(DzienTyg1 == 0)
			break;
			
		Data1=ZrobDate(DzienTyg1, DzienMies1, Mies1, Rok1);
		Data2=ZrobDate(DzienTyg2, DzienMies2, Mies2, Rok2);
		
		
		if(BladDaty(Data1)!=0 || BladDaty(Data2)!=0)	
		{ 
		    if(BladDaty(Data1) != 0)
		    {
		    	printf("Data1: ");
				ktory_bledny(BladDaty(Data1));
				printf("\n");	    
			}
			if(BladDaty(Data2) != 0)
		    {
				printf("Data2: ");
				ktory_bledny(BladDaty(Data2));
				printf("\n");
		    }
		}
		else
		{
			WypiszDate(Data1);
			WypiszDate(Data2);
			printf("Ilosc dni pomiedzy: %d\n", Odleglosc(Data1, Data2));
		}
	}
	return 0;
}
