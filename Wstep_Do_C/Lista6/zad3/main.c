#include <stdio.h>

void Tab__Read(int n, int m, char Tab[n][m])
{
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				char c;
				scanf("%c", &c);
				Tab[i][j]=c;
			}			
}

void Tab__Print(int n, int m, char Tab[n][m])
{
	for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				printf("%c", Tab[i][j]);			
}

void Tab__Fill(int n, int m, char Tab[n][m])
{
	if(Tab[n-1][m] == '-')
		Tab[n-1[m]] = '!';
		
	if(Tab[n+1][m] == '-')
		Tab[n+1][m] = '!';
		
	if(Tab[n][m+1] == '-')
		Tab[n][m+1] = '!';
		
	if(Tab[n][m-1] == '-')
		Tab[n][m-1] = '!';
		
	else
		return;
}

void Tab__Source(int n, int m, char Tab[n][m])
{
	for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(Tab[i][j]=='!')
					Tab__Fill(n, m, Tab)	 
}



int main() 
{
	int n,m;
	scanf("%d %d", &n, &m);
	
	char tab[n][m+1];
	
	Tab__Read(n, m+1, tab);
	Tab__Print(n, m+1, tab);
	Tab__Source(n, m+1, tab);
	
	return 0;
}
