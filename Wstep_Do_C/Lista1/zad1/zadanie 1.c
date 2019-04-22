//Lukasz Wojdon
//Program wczytuje liczby calkowite zakonczone kropka w systemie dziesietnym i wypisuje je w systemie dwojkowym.

#include <stdio.h>
#include <math.h>

int NumInput( int baza)
{
	int liczba = 0,sign=1;
	
	printf("podaj ciag znakow: ");
	int c = getchar();
	while( c!='+' && c!='-' && !(c<('0'+baza) && c>='0'))
		c = getchar();
	if( c == '-')
	{
		sign=-1;
		c = getchar();				
	}
	else if( c=='+')
		c = getchar();
	
	while(c!='.')
	{
		liczba*=baza;
		liczba += c-'0';
		c = getchar();

	}

	return liczba*sign;		
}


void NumOutputR(int baza, int x)
{
	if(x>=baza)
		(NumOutputR(baza, x/baza));
	putchar('0' + x%baza);
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
	putchar('.');
	
}


int main()
{	const int BASE_IN = 10;
	int liczba = 1;
	while(liczba!=0)
	{
		liczba=NumInput(BASE_IN);
		NumOutput(10, liczba);
		putchar(' ');
		NumOutput(2,  liczba);
		putchar('\n');
	}
}
