#include <stdio.h>

const int DOBA=60*24;

int Zamiana(int h, int m)
{
	return h*60+m;
}

int PierwszyPrzystanek()
{
	int h,m;
	scanf("%d %d", &h, &m);
	return h*60+m;
}

int PierwszyPoprawny(int jazda, int odjazd)
{
	return odjazd+jazda;
}

int NastepnyDzien(int czas)
{
	return czas-DOBA;
}

int main() 
{
	
	int	aktualny_czas;
	int czas_jazdy;
	int godzina_przyjazdu;
	int najlepszy_czas_wyjazdu, czas_wyjazdu;
	int czas_odjazdu;
	int najlepszy_czas_podrozy, czas_podrozy;
	int przystanki;
	int ilosc_odjazdow;
	int h,m,doba=0,znaleziony=0;
	
	scanf("%d", &przystanki);
	for (int i=1; i<=przystanki; i++)
	{
		scanf("%d %d", &czas_jazdy, &ilosc_odjazdow);
		
		int odjazdow = ilosc_odjazdow; 
		while(odjazdow>0)
		{
			scanf("%d %d", &h, &m);
			czas_odjazdu=Zamiana(h,m);
					
			if(znaleziony==0)
			{
				if(aktualny_czas<=(czas_odjazdu+doba*DOBA))
				{
					aktualny_czas=PierwszyPoprawny(czas_jazdy, czas_odjazdu);
					znaleziony++;
					
					if(aktualny_czas>DOBA)
						doba++;
				}
			}					
			odjazdow--;
			if(odjazdow == 0 && znaleziony == 0)
				{
					odjazdow = ilosc_odjazdow;
					aktualny_czas=0;
					doba++;
				}	
		}
		i++;
	}
	
	
	
	
	return 0;
}
