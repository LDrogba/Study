#include <stdio.h>

int in[512], out[512];

//#define DBG_PRINTF(...) printf(__VA_ARGS__)
#define DBG_PRINTF(...)

int In()
{
	int time=0, month, day, hour, min, sec;
	scanf("%d %d %d %d %d", &month, &day, &hour, &min, &sec);
	
	time+=month;
	time <<= 5;
	time+=day;
	time <<= 5;
	time+=hour;
	time <<= 6;
	time+=min;
	time <<= 6;
	time+=sec;
	
	return time;
}


int Month(int czas)
{
	return czas>>=22;
}

int Day(int czas)
{
	
	czas >>=17;	
	czas &= 31;
	
	return czas;
}

int Hour(int czas)
{

	czas >>=12;
	czas &= 31;
	
	return czas;
}

int Minute(int czas)
{
	
	czas>>=6;
	czas &= 63;
		
	return czas;
}

int Second(int czas)
{
	
	czas &= 63;	

	return czas;
}

void ReadPlayers(int x)
{
	for(int i=0; i<x; i++)
	{
		in[i] = In();
		out[i] = In();
	}
}

int Min(int x, int y)
{
	if(x>=y)
		return y;
	else
		return x;
}

int Max(int x, int y)
{
	if(x>=y)
		return x;
	else
		return y;
}

int Ok(int st1, int en1, int st2, int en2)
{
	int s, e;
	
	s=Max(st1,st2);
	e=Min(en1,en2);
	
	if(s<e)
		return 1;
	else
		return 0;
}


int main() 
{
	int players, s1, e1, s2, e2, najlepszy=0, pocz, kon, p1, p2, p3, p4;
	scanf("%d", &players);
	
	DBG_PRINTF("Ilosc graczy: %d\n", players);
	
	ReadPlayers(players);
	
	for(int i=0; i<players-3; i++)
	{
		DBG_PRINTF("----------------------\n");
		s1=in[i];
		e1=out[i];
		
		DBG_PRINTF("gracz %d: %d %d\n", i, s1, e1);
		if(e1-s1<=najlepszy)
			continue;
			
		for(int j=i+1; j<players-2; j++)
		{
			int sj=s1;
			int ej=e1;
			
			
			s2=in[j];
			e2=out[j];
			
			
			DBG_PRINTF("gracz %d: %d %d\n", j, s2, e2);
			
			if ( e2-s2<=najlepszy || Ok(sj, ej, s2, e2)==0)
				continue;
			else
			{
				DBG_PRINTF("++%d %d\n", i, j);
				
				sj=Max(sj, s2);
				ej=Min(ej, e2);
				
				DBG_PRINTF("przedzial: %d %d\n", s1, e1);
				
			}
			
			for(int k=j+1; k<players-1; k++)
				{
					int sk=sj;
					int ek=ej;
					
					s2=in[k];
					e2=out[k];
					
					DBG_PRINTF("gracz %d: %d %d\n", k, s2, e2);
					
					if ( e2-s2<=najlepszy || Ok(sk, ek, s2, e2) == 0)
						continue;
					else
					{
						DBG_PRINTF("+++%d %d %d\n", i, j, k);
						
						sk=Max(sk, s2);
						ek=Min(ek, e2);
						
						DBG_PRINTF("przedzial: %d %d\n", s1, e1);
					}
				
					for(int l=k+1; l<players; l++)
					{
						int sl=sk;
						int el=ek;
						
						
						s2=in[l];
						e2=out[l];
						
						DBG_PRINTF("gracz %d: %d %d\n", l, s2, e2);
						
						if (e2-s2<=najlepszy || Ok(sl, el, s2, e2) == 0)
							continue;
						else
						{
							DBG_PRINTF("+++%d %d %d %d\n", i, j, k, l);
							sl=Max(sl, s2);
							el=Min(el, e2);
							
							DBG_PRINTF("przedzial: %d %d\n", s1, e1);
	
														
							if(el-sl>najlepszy)
							{
								DBG_PRINTF("**********\n");
								DBG_PRINTF("%d %d %d %d\n", i, j, k, l);
								pocz=sl;
								kon=el;
								najlepszy=el-sl;
								p1=i;
								p2=j;
								p3=k;
								p4=l;
							}
						}
							
					}
						
				}
		}
	
	}
	if(najlepszy>0)
	{
	
		int m, d, h, min, s;
		printf("%d %d %d %d %d\n", najlepszy, p4, p3, p2, p1);
	
		m = Month(pocz); 
		d = Day(pocz);
		h =	Hour(pocz);
		min = Minute(pocz);
		s = Second(pocz);
	
		printf("%d: %d %d %d %d %d\n", pocz, m, d, h, min, s);
	
		m = Month(kon); 
		d = Day(kon);
		h =	Hour(kon);
		min = Minute(kon);
		s = Second(kon);
		
		printf("%d: %d %d %d %d %d\n", kon, m, d, h, min, s);
		
	}
	
	else
	printf("NOT FOUND!");
		
	return 0;
}
