//Lukasz Wojdon
//lista 5(6) zadanie 1



#include <stdio.h>
#include <stdlib.h>





void WypiszWiersz1(int k, int r) // k - nr. wiersza r - szerokosc spirali; funkcja wypisujace gorna polowe spirali
{
	
		if(k==0)
		{
			r++;
			for(int i=0; i<r-1; i++)
				printf("%4d", r*r-(r-k)-i);
		}
		else if(r%2==0)
		{
			WypiszWiersz1(k, (r-1));			
			printf("%4d", r*r-(k-1));
		}
		else
		{
			printf("%4d", r*r-(r-k));			
			WypiszWiersz1((k-1), (r-1));
		}
}

void WypiszWiersz2(int k, int r) // k - nr wiersza r - szerokosc spirali; funkcja wypisujaca dolna polowe spirali
{

	if(r%2==0)
	{	
		if(k==r)
		{
			for(int i=0; i<r; i++)
				printf("%4d", r*r-2*(r-1)+i);
		}
		else
		{
			WypiszWiersz2(k, (r-1));		
			printf("%4d", r*r-(k-1));
		}
	}
	else
	{
		printf("%4d", r*r-(r-k));	
		WypiszWiersz2((k-1), (r-1));
	}
}

int main(int argc, const char *argv[]) 
{
	int r;
	if(argc==1)
		r=17;
	else
		r=atoi(argv[1]);
		
	for(int i=1; i<=r/2; i++)	
	{
		WypiszWiersz1(i, r);
		printf("\n");
	}
	
	for(int i=r/2+1; i<=r; i++)
	{
		WypiszWiersz2(i, r);
		printf("\n");
	}
	return 0;
}
