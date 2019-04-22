//Lukasz Wojdon
//Zadanie 1 lista 8

#include <stdio.h>
#include <stdlib.h>

struct Zespolona
{
	float r;
	float u;
};

struct Zespolona Dodawanie(struct Zespolona A, struct Zespolona B)
{
	struct Zespolona Suma;
	Suma.r = A.r + B.r;
	Suma.u = A.u + B.u;
	
	return Suma;
}

struct Zespolona Odejmowanie(struct Zespolona A, struct Zespolona B)
{
	struct Zespolona Roznica;
	Roznica.r = A.r - B.r;
	Roznica.u = A.u - B.u;
	
	return Roznica;
} 

struct Zespolona Mnozenie(struct Zespolona A, struct Zespolona B)
{
	struct Zespolona Iloczyn;
	Iloczyn.r = A.r * B.r - A.u * B.u;
	Iloczyn.u = A.r * B.u + A.u * B.r;
	
	return Iloczyn;
}

float Norma(struct Zespolona Z)
{
	return (Z.r * Z.r + Z.u * Z.u);
}


int Check(struct Zespolona zesp, struct Zespolona c)
{
	for(int i = 0; i < 200; i++)
		zesp=Odejmowanie(Mnozenie(zesp, zesp), c);

	if(Norma(zesp) < 4)
		return 1;
	else
		return 0;	
}

int main( int argc, char* argv[])
{
    int h = 25;
    int w = 40;
    struct Zespolona zesp, c;
    c.r = 0.1;
    c.u = 0.81;
    
    if(argc > 2)
    {
    	w = atoi(argv[1]);		
		h = atoi(argv[2]);
	}
	
	if(argc > 4)
	{
		c.r = atof(argv[3]);
		c.u = atof(argv[4]);
	}

    for(int y = 0; y < h; y++)
    {
    zesp.u = 2.0f*(((float)y / (h-1)) - 0.5f);
    
	    for(int x = 0; x < w; x++)
        {
        	zesp.r = 2.0f*(((float)x / (w-1)) - 0.5f);
			        	
            if(Check(zesp, c))
                printf("O");
            else
                printf(" ");
        }
	printf("\n");
	}
	
	return 0;
}	

