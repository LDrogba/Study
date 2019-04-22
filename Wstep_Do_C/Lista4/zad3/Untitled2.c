#include <stdio.h>

int Row(int szer, int r, int n, int m, char tab[n][m])
{
		
	for(int i=0; i<n; i++)
		for(int j=r; j<r+szer; j++)
			if(tab[i][j]=='X' && j<m)
				return i;
	return n;
}

int RowF(int r, int n, int m, char  tab[n][m])
{
		
	int x=n, y=n;
	
	for(int i=0; i<n; i++)
		if(tab[i][r]=='X' && r<m)
		{
			x=i;
			break;
		}
	
	for(int i=0; i<n; i++)	
		if(tab[i][r+1]=='X' && r+1<m)
		{
			y=i; 
			break;
		}
		
	if(x<=y+2)
		return x;
	else
		return y+2;	
		
}

int RowT(int r, int n, int m, char tab[n][m])
{		
	for(int i=0; i<n; i++)
	{
		if(tab[i][r]=='X'|| (tab[i][r+2]=='X' && r+2<m))
			return i+1;
		if(tab[i+1][r+1]=='X' && r+1<m)
			return i+1;
	}
	return n;
}

void K(int r, int n, int m, char tab[n][m])
{
	if(r>=m || r<0)
		return;
		
	int w=2, h=2, line;
	
	line=Row(w, r, n, m, tab);
	
	for(int i=line-h; i<line; i++)
		for(int j=r; j<r+w && j<m; j++)	
				tab[i][j]='X';
}

void T(int r, int n, int m, char tab[n][m])
{
	if(r>=m || r<0)
		return;
		
	int w=3, h=2, line;
	
	line=RowT(r, n, m, tab);
	
	for(int i=line-h; i<line; i++, r++, w-=2)
		for(int j=r; j<r+w && j<m; j++)
				tab[i][j]='X';
}

void I(int r, int n, int m, char tab[n][m])
{
	if(r>=m || r<0)
		return;
	
	int w=1, h=4, line;
	
	line=Row(w, r, n, m, tab);
	
	for(int i=line-h; i<line; i++)
		tab[i][r]='X';
	
}

void W(int r, int n, int m, char tab[n][m])
{
	if(r>=m || r<0)
		return;
	int w=5, h=3, line;
	
	line=Row(w, r, n, m, tab);
	
	for(int i=line-h; i<line; i++)
		if(i!=line-1)
		{
			for(int j=r; j<r+w && j<m; j+=2)
					tab[i][j]='X';
		}
		else
			for(int j=r; j<r+w && j<m; j++)
					tab[i][j]='X';
}

void F(int r, int n, int m, char tab[n][m])
{
	if (r>=m || r<0)
		return;
		
	int h=3, line;

	line=RowF(r, n, m, tab);
	
	for(int i=line-h; i<line; i++)
	{
		tab[i][r]='X';
		if(i==line-h && r+1<m)
			tab[i][r+1]='X';
	}
}

void B(int r, int n, int m, char tab[n][m])
{
	if(r>=m || r<0)
		return;
		
	int w=1, line;
	
	line=Row(w, r, n, m, tab)-1;
	
	tab[line][r]='X';
	
	for(int i=line-1; i<=line+1; i++)
		for(int j=r-1; j<=r+1; j++)
			if(j<m && i<n)
				tab[i][j]='.';
	
}

void Print(char* typ, int col, int n, int m, char tab[n][m])
{
	switch(*typ)
	{
		case 'K':
			K(col, n, m, tab);
			break;
		case 'T':
			T(col, n, m, tab);
			break;
		case 'I':
			I(col, n, m, tab);
			break;
		case 'F':
			F(col, n, m, tab);
			break;
		case 'W':
			W(col, n, m, tab);
			break;
		case '*':
			B(col, n, m, tab);
			break;
		default:
			printf("BLAD\n");
	}	
}

void Delete(int row, int n, int m, char tab[n][m])
{
	for(int i=row; i>0; i--)
		for(int j=0; j<m; j++)
			tab[i][j]=tab[i-1][j];

	for(int i=0; i<m; i++)
		tab[0][i]='&';
}


void IfDelete(int n, int m, char tab[n][m])
{
	int sum;
	for(int i=0; i<n; i++)
	{
		sum=0;
		for(int j=0; j<m; j++)			
			if(tab[i][j]=='X')
				sum++;
		if(sum==m)
			Delete(i, n, m, tab);					
	}
}




int main()
{
	int k, n, m, row;	
	char sign[2];
	
	scanf("%d %d %d",&m, &n, &k);
	char Tab[n][m];
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			Tab[i][j]='.';
				
	for(int i=0; i<k; i++)
	{
		scanf("%s %d", sign, &row);
		Print(sign, row, n, m, Tab);
		IfDelete(n,m,Tab);
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%c", Tab[i][j]);
		
		printf("\n");
	}
	
	return 0;
}
