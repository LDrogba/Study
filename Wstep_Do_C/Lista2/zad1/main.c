//Lukasz Wojdon
//zadanie 1 lista 3


#include <stdio.h>

int (nalezy_kolo(int x0, int y0, int r, int x, int y))
{
    return (((x-x0)*(x-x0) + (y-y0)*(y-y0)) <= (r *r));
}

void DrawElip(int x, int y, int r)
{
    for(int i=0;i<=(y+r);i++)
    {
        for(int j=0;j<=(x+r);j++)
            {
                if(nalezy_kolo(x, y, r, j, i))
                    printf("x");
                else
                    printf(".");
            }
        printf("\n");
    }
}

void DrawRect(int x0, int y0, int w, int h)
{
    for(int i=0;i<(y0+h);i++)
    {
        for(int j=0;j<(x0+w);j++)
            if(j<x0 || i<y0)
                printf(".");
            else
            	printf("x");
        printf("\n");
    }
}

void CmdCircle(char cmd[])
{
	int x=0,y=0,r=0;
	char s;
	sscanf(cmd,"%c %d %d %d", &s,&x,&y,&r);
	
	DrawElip(x,y,r);	
}

void CmdSquare(char cmd[])
{
	int x,y,w,h;
	char s;
	sscanf(cmd, "%c %d %d %d %d", &s, &x, &y, &w, &h);
	
	DrawRect(x,y,w,h);
}
int main()
{
    int x0=4, y0=4, r=3;
    char polecenie[10]; 
    
	printf("Witaj w programie rysujacym Twoje wymarzone figury!\n");
    DrawElip(x0, y0, r);
 	
	while(true)
 	{
	 	fgets(polecenie, 10, stdin);
	 	switch(polecenie[0]) 
		{
		 	case 'c':
		 		CmdCircle(polecenie);
		 		break;
		 	case 'r':
		 		CmdSquare(polecenie);
		 		break;
		 	case 'q':
		 		return 0;
		 		break;
		}  
	}
}
