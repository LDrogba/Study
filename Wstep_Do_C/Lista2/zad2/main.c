//Lukasz Wojdon 
//zadnie 2 lista 3




#include <stdio.h>
#define ROZMIAR 2000
char tab[ROZMIAR]={' '};

int nalezy_kolo(int x0, int y0, int r, int x, int y)
{
    return (((x-x0)*(x-x0) + (y-y0)*(y-y0)) <= (r *r));
}

void DrawElip(int x, int y, int r)
{
    for(int i=1;i<=25;i++)
        for(int j=0;j<=80;j++)
           	if(nalezy_kolo(x, y, r, j, i-1))
           	    tab[(i-1)*80+j]='x';
    return;
}

void DrawRect(int x0, int y0, int w, int h)
{
    for(int i=y0;i<(y0+h);i++)
        for(int j=x0;j<(x0+w);j++)
    		tab[i*80+j]='X';
    return;
}

void DrawTri(int x0, int y0, int w)
{
	int warunek, k=0;
	if(w%2==0)
		warunek = w/2;
	else
		warunek = w/2+1;
		
	for(int i=0;i<=warunek;i++,y0++)
	{	
		for(int j=x0+k; j<x0+w-k; j++ )
			tab[y0*80+j]='x';	
		k++;	
	}
	return;
}

void DrawTree(int x0, int y0, int h)
{
	int k=0, wysokosc_pnia=1;
	
	if(h>=4)
		wysokosc_pnia=h/4;
	
	for(int i=0; i<h-wysokosc_pnia; i++,y0++)
	{
		for(int j=x0-k;j<=x0+k;j++)
			tab[(y0-1)*80+j] = 'x';
		k++;
	}
	
	for(int i=h+1;i<=h+wysokosc_pnia; i++,y0++)
		tab[(y0-1)*80+x0]='|';
	return;
}

void Print()
{
	for(int i=1;i<=25;i++)
	{
		for(int j=0; j<80; j++ )
			printf("%c", tab[(i-1)*80+j]);
		printf("\n");
	}
	return;
}


int WspX(int x)
{
	return x%80;	
}

int WspY(int y)
{
	return y/80+1;
}

int Wsp(int x, int y)
{
	return ((25 - y)*80+(80-(80-x)));
}

void CmdMirror()
{
	char tab2[ROZMIAR];
	for(int i=1; i<ROZMIAR; i++)
		tab2[Wsp(WspX(i),WspY(i))]=tab[i];
	
	for(int i=0; i<ROZMIAR; i++)
		tab[i]=tab2[i]; 
}

void CmdPrint()
{
	Print();
	return;
}

void CmdZero()
{
	for(int i=0; i<ROZMIAR; i++)
		tab[i]=' ';
}
	
void CmdXtree(char cmd[])
{
	int x,y,h;
	char s;
	sscanf(cmd, "%c %d %d %d", &s, &x, &y, &h);
	
	DrawTree(x,y,h);
	return;
}
void CmdTriangle(char cmd[])
{
	int x,y,r;
	char s;
	sscanf(cmd, "%c %d %d %d", &s, &x, &y, &r);
	
	DrawTri(x,y,r);	
	return;
}
void CmdCircle(char cmd[])
{
	int x=0,y=0,r=0;
	char s;
	sscanf(cmd,"%c %d %d %d", &s,&x,&y,&r);
	
	DrawElip(x,y,r);	
	return;
}

void CmdSquare(char cmd[])
{
	int x,y,w,h;
	char s;
	sscanf(cmd, "%c %d %d %d %d", &s, &x, &y, &w, &h);	
	
	DrawRect(x,y,w,h);
	return;
}
int main()
{
    char polecenie[1000]; 
    printf("Witaj w programie rysujacym Twoje wymarzone figury!\n");
 	while(1)
 	{
	 	fgets(polecenie, 1000, stdin);
	 	switch(polecenie[0]) 
		{
		 	case 'c':
		 		CmdCircle(polecenie);
		 		break;
		 	case 'r':
		 		CmdSquare(polecenie);
		 		break;
		 	case 't':
		 		CmdTriangle(polecenie);
		 		break;
		 	case 'x':
		 		CmdXtree(polecenie);
		 		break;
			case 'p':
		 		CmdPrint();
		 		break;
		 	case 'm':
		 		CmdMirror();
		 		break;
		 	case 'z':
		 		CmdZero();
		 		break;
			case 'q':
		 		return 0;
		 		break;
		}  
	}
}
