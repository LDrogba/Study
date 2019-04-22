// Lukasz Wojdon
// program oblicza proste wyrazenia arytmetyczne w systemie szesnastkowym



#include <stdio.h>
#include <math.h>

int IsBaz(char c, int baza)
{
	if (baza==16)
		return ((c>='0' && c<='9') || (c>='A' && c<='F'));
	else
		return (c>='0' && c<('0'+baza));
}

int NumInput( int baza)
{
	int liczba = 0,sign=1;
	
	printf("podaj ciag znakow: ");
	int c = getchar();
	
	while( c!='+' && c!='-' && !IsBaz(c, baza))
		c = getchar();
	
	if( c == '-')
	{
		sign=-1;
		c = getchar();		
	}
	else if(c== '+')
		c = getchar();
	
	while(c!='.')
	{
		liczba*=baza;
		if(c<='9' && c>='0')
			liczba += c-'0';
		else if(c>='A' && c<='F')
			liczba += c-'A'+10;	
		c = getchar();

	}
	
	return liczba*sign;	
}


char ReadOperator()	
{
	char c;
	
	do
		c=getchar();
	while(c==' ');
	
	return c;	
}


void NumOutputR(int baza, int x)
{
	if(x>=baza)
		(NumOutputR(baza, x/baza));

	int m = x%baza;
	if(m>=10)
		putchar('A'+ m-10);
	else
		putchar('0' + m);
}



void NumOutput( int baza, int x)
{
	if(x<0)
	{
		putchar('-');
		NumOutputR(baza,-x);
	}
	else
		NumOutputR(baza,x);
	
}


int main()
{	const int BASE_IN = 16;
	int liczba1 = 1, liczba2, wynik=0;
	while(liczba1!=0)
	{
		liczba1=NumInput(BASE_IN);
		
		switch(ReadOperator())
		{
			case('+'):
				liczba2=NumInput(BASE_IN);
				wynik = liczba1 + liczba2;
				break;
			case('-'):
				liczba2=NumInput(BASE_IN);
				wynik=liczba1 - liczba2;
				break;
			case('*'):
				liczba2=NumInput(BASE_IN);
				wynik = liczba1 * liczba2;
				break;
			case('/'):
				liczba2=NumInput(BASE_IN);
				wynik = liczba1 / liczba2;
				break;
			case('!'):
				wynik = 1;
				for(int i=1;i<=liczba1;i++)
					wynik*=i;
				break;
			default:
				liczba1=wynik=0;		
		}
		
		NumOutput(16, wynik);
		putchar('\n');
	}
}
