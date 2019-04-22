#include <stdio.h>
#include <stdlib.h>

#define MAX 6001

int wczytaj_wiersz(char wiersz[], int max)
{
	int c,i;
	for(i = 0; i < max && (c=getchar()) != EOF; ++i)
		if(c == '\n')//	if((wiersz[i] = c) =='\n') 
		{
			wiersz[i]=0;
			return i;
		}
		else
			wiersz[i]=c;
				
	if (c==EOF)
	{
		wiersz[i]=0;
		if (i==0)
			return -1;
	}
	
	return i;
}

int bialy(char c)
{
	return ( c == ' ' || c == '\t'); 
}

int bialy_wiersz(char wiersz[])
{
	int i=0;
	while(wiersz[i]!=0)
	{
		if(!bialy(wiersz[i]))
			return 0;	
		i++;
	}
	
	return i>0;
}

int przytnij(char wiersz[], int start)
{
	int i = start-1;
	while(i>=0 && bialy(wiersz[i]))
		i--;
	
	if(i==start-1)
		return start;
	
	wiersz[i+1]=0;
	return i+1;	
}

int takie_same(char w1[],char w2[])
{
	int i=0;
	while(w1[i]!=0)
	{
		if(w1[i]!=w2[i])
			return 0;
		i++;	
	}
	
	if(w2[i]!=0)
		return 0;
	return 1;
}

int kopiuj(char zrodlo[], char cel[])
{
	int i=0;
	while(zrodlo[i]!=0)
	{
		cel[i]=zrodlo[i];
		i++;
	}
	cel[i]=0;
	
	return i;
}

int main() 
{
	char b1[MAX] = {0};
	char b2[MAX] = {0};
	int l1, l2;
	int w1, w2; // czy wiersz jest bialy?
	
	l1 = wczytaj_wiersz(b1, MAX);
	
	if (l1==-1)
		return 0;
	
	w1 = bialy_wiersz(b1);
	if(!w1)
		l1 = przytnij(b1, l1);
	
	printf("%s\n", b1);	
	
	_Bool koniec = 0;
	
	while(!koniec)
	{
		l2 = wczytaj_wiersz(b2, MAX);
		if(l2<0)
			return 0;
		w2 = bialy_wiersz(b2);
		
		int pomin_wiersz = 0;
		if(!w1 && !w2 && l1>0)
			l2 = przytnij(b2, l2);
		
		pomin_wiersz = takie_same(b1, b2);
		
		if(!pomin_wiersz)
		{
			printf("%s\n", b2);
			
			if(!w2 )
				l2=przytnij(b2, l2);
				
			kopiuj(b2, b1);
			l1=l2;
			w1=w2;
		}
			
	}
	
	printf("---- \n");
	return 0;
}
