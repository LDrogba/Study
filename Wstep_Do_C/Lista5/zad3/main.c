#include <stdio.h>
#include <stdlib.h>

void Tab__Read(int h, int w, int tab[h][w])
{
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		{
			int t;
			scanf("%d",&t);
			tab[i][j]=t;
		}
}

#if 0
void Tab__Write(int h, int w, int tab[h][w])
{
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
			printf("%d",tab[i][j]);
		printf("\n");
	}

}
#endif

void Tab__Neigh(int h, int w, int th, int tw, int tab[h][w])
{
	tab[th][tw]=0;
	
	int sc = max(th-1, 0);
	int ec = min(th)
	
	for(int i=th-1; i<=th+1; i++)
		for(int j=tw-1; j<=tw+1; j++)
		{
			if((i>=0 && i<h) && (j>=0 && j<w))
				if(tab[i][j]==1)
					Tab__Neigh(h, w, i, j, tab);
		}
}

int Tab__Count(int h, int w, int tab[h][w])
{
	int nr=0;
	
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		{
			if(tab[i][j]==1)
			{
				nr++;
				Tab__Neigh(h, w, i, j, tab);	
			}
		}
	return nr;
}



int main()
{
	char p;
	int l, h, w;
	
	scanf("%c%d %d %d", &p, &l, &w, &h);
	
	int tab[h][w];
	
	Tab__Read(h, w, tab);

	printf("%d\n", Tab__Count(h, w, tab));

	return 0;
}
