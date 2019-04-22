//Lukasz Wojdon
//lista 5 zadanie 2

#include <stdio.h>
#include <stdlib.h>


FILE* Wyjscie;

int Pierwsza(int n)
{
	if(n<2)
    	return 0;
 
	for(int i=2;i*i<=n;i++)
    	if(n%i==0)
      		return 0;
  	
	return 1;
}

void WypiszNum(int n)
{
	if(Wyjscie==stdout)
		fprintf(Wyjscie, "%4d", n);
	else
	{
		int r, g, b;
		
		if(Pierwsza(n))
		{
			r = 255;
			g = 0;
			b = 0;
		}
		else
		{
			r = 0;
			g = 0;
			b = 255;
		}
		
		fprintf(Wyjscie, "%3d %3d %3d    ", r, g, b);
	}

}


void WypiszWiersz1(int k, int r) // k - nr. wiersza r-szerokosc spirali
{	
		if(k==0)
		{
			r++;
			for(int i=0; i<r-1; i++)
				WypiszNum(r*r-(r-k)-i);
		}
		else if(r%2==0)
		{
			WypiszWiersz1(k, (r-1));			
			WypiszNum(r*r-(k-1));
		}
		else
		{
			WypiszNum(r*r-(r-k));			
			WypiszWiersz1((k-1), (r-1));
		}
}

void WypiszWiersz2(int k, int r)
{
	if(r%2==0)
	{	
		if(k==r)
		{
			for(int i=0; i<r; i++)
				WypiszNum(r*r-2*(r-1)+i);
		}
		else
		{
			WypiszWiersz2(k, (r-1));		
			WypiszNum(r*r-(k-1));
		}
	}
	else
	{
		WypiszNum(r*r-(r-k));
		
		WypiszWiersz2((k-1), (r-1));
	}
}

void WypiszSpirale(int r)
{	
	for(int i=1; i<=r/2; i++)	
	{
		WypiszWiersz1(i, r);
		fprintf(Wyjscie,"\n");
	}
	
	for(int i=r/2+1; i<=r; i++)
	{
		WypiszWiersz2(i, r);
		fprintf(Wyjscie,"\n");
	}
}

int main(int argc, const char *argv[]) 
{
	int r;

	if(argc==1)
		r=17;
	else
		r=atoi(argv[1]);
	
	Wyjscie = stdout;	
	WypiszSpirale(r);
	
	if(argc>2)
	{
		FILE* plik=fopen(argv[2],"w"); 
		Wyjscie = plik;
		
		fprintf(Wyjscie,"P3\n%d %d\n255\n", r, r);	
	
		WypiszSpirale(r);
		fclose(plik);
	}	
	return 0;
}
