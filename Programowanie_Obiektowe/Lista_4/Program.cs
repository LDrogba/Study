using System;
using System.Collections;
using System.Collections.Generic;

namespace Lista4
{
    #region zad2
    public class PrimeCollection : IEnumerable<int>
    {
        bool CzyPierwsza(int n)
        {
            if (n < 2)
                return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

            for (int i = 2; i * i <= n; i++)
                if (n % i == 0)
                    return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
            return true;
        }
      
        public IEnumerator<int> GetEnumerator()
        {
            yield return 2;
            for(int i=3; i*i < Int32.MaxValue; i++)
            {
                if (i % 2 == 0)
                    i++;

                if (CzyPierwsza(i))
                    yield return i;
            }

        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
    #endregion

    class zad3
    {

        interface IGraf
        {
            void Dodaj_wierzcholek(string nazwa);
            void Dodaj_krawedz(string start, string end);
            List<string> Sadziedzi(string nazwa);
        }


        class Graf_macierz
        {
            bool[,] tab_kraw;
            string[] tab_nazw;
            int ilosc_wierz;

            int Znajdz_indeks(string nazwa)
            {
                for (int i = 0; i < ilosc_wierz; i++)
                    if (tab_nazw[i] == nazwa)
                        return i;

                return -1;
            }

            public Graf_macierz(int i)
            {
                if (i <= 0)
                    throw new Exception(" Graf musi miec co najmniej jeden wierzcholek ");

                tab_kraw = new bool[i, i];
                tab_nazw = new string[i];
                ilosc_wierz = 0;
                for (int j = 0; j < i; j++)
                {
                    for (int k = 0; k < i; k++)
                        tab_kraw[j, k] = false;
                    tab_nazw[j] = null;
                }
            }

            public void Dodaj_wierzcholek(string nazwa)
            {
                if (ilosc_wierz > tab_nazw.Length - 1)
                    throw new Exception("Osiagnieto juz maksymalna ilosc wierzcholkow dostepnych w tym grafie");

                int miejsce = ilosc_wierz;
                tab_nazw[miejsce] = nazwa;
                ilosc_wierz++;

                for (int j = 0; j <= miejsce; j++)
                {
                    tab_kraw[miejsce, j] = false;
                    tab_kraw[j, miejsce] = false;
                }
            }

            public void Dodaj_krawedzie(string wierz_pocz, List<string> list)
            {
                int indeks_1 = Znajdz_indeks(wierz_pocz);

                if (indeks_1 == -1)
                    throw new Exception("nie znaleziono takiego wierzchołka " + wierz_pocz);

                foreach(string wierz in list)
                {
                    int indeks_2 = Znajdz_indeks(wierz);

                    if (indeks_2 == -1)
                        throw new Exception("nie znaleziono wierzcholka " + wierz);

                    tab_kraw[indeks_1, indeks_2] = true;
                    tab_kraw[indeks_2, indeks_1] = true;
                }
            }

            public void Dodaj_krawedz(string wierz_pocz, string wierz_kon)
            {
                int indeks_1 = Znajdz_indeks(wierz_pocz);

                if (indeks_1 == -1)
                    throw new Exception("nie znaleziono takiego wierzchołka " + wierz_pocz);
                
                int indeks_2 = Znajdz_indeks(wierz_kon);
        
                if (indeks_2 == -1)
                    throw new Exception("nie znaleziono wierzcholka " + wierz_kon);

                tab_kraw[indeks_1, indeks_2] = true;
                tab_kraw[indeks_2, indeks_1] = true;
            }

            public List<string> Sasiedzi(string nazwa)
            {
                int indeks = Znajdz_indeks(nazwa);

                if (indeks == -1)
                    throw new Exception("nie znaleziono wierzcholka" + nazwa);

                List<string> sasiedzi = new List<string>();

                for (int i = 0; i < ilosc_wierz; i++)
                    if (tab_kraw[indeks, i] == true)
                        sasiedzi.Add(tab_nazw[i]);

                return sasiedzi;
            }

        }

        public class Graf_listy
        {
            public class wierzcholek
            {
                public string nazwa;
                //List<wierzcholek> somsiady;
                
                public List<wierzcholek> somsiady
                {
                    get;
                    private set;
                }

                public wierzcholek()
                {
                    somsiady = new List<wierzcholek>();
                }
                public wierzcholek(string nazwa)
                {
                    this.nazwa = nazwa;
                    somsiady = new List<wierzcholek>();
                }

                public wierzcholek(string nazwa, List<wierzcholek> somsiads)
                {
                    this.nazwa = nazwa;
                    somsiady = somsiads;
                }

                wierzcholek Znajdz_wierzcholek(string nazwa)
                {
                    foreach (wierzcholek w in somsiady)
                        if (nazwa == w.nazwa)
                            return w;

                    return null;
                }
                
                public void Dodaj_kraw(wierzcholek w)
                {
                    if (!somsiady.Exists(x => (x == w)))
                    {
                        somsiady.Add(w);
                    }
                }
            }

            List<wierzcholek> wierzcholki = new List<wierzcholek>();
            
            wierzcholek Znajdz_wierzcholek(string nazwa)
            {
                foreach (wierzcholek w in wierzcholki)
                    if (nazwa == w.nazwa)
                        return w;

                return null;
            }

            wierzcholek dodaj_wierzcholek(string nazwa)
            {
                if (Znajdz_wierzcholek(nazwa) != null)
                    throw new Exception(" wierzcholek o nazwie " + nazwa + " juz istnieje");

                wierzcholek new_wierz = new wierzcholek(nazwa);

                wierzcholki.Add(new_wierz);

                return new_wierz;
            }

            public void Dodaj_wierzcholek(string nazwa)
            {
                dodaj_wierzcholek(nazwa);
            }
#if disabled
            public wierzcholek Dodaj_wierzcholek(string nazwa, List<wierzcholek> list)
            {
                if (Znajdz_wierzcholek(nazwa) != null)
                    throw new Exception(" wierzcholek o nazwie " + nazwa + " juz istnieje");

                wierzcholek new_wierz = new wierzcholek(nazwa, list);

                wierzcholki.Add(new_wierz);

                return new_wierz;
            }
#endif
            public void Dodaj_krawedz(string start, string end)
            {
                wierzcholek w1 = Znajdz_wierzcholek(start);

                if (w1 == null)
                    w1 = dodaj_wierzcholek(start);

                wierzcholek w2 = Znajdz_wierzcholek(end);

                if (w2 == null)
                    w2 = dodaj_wierzcholek(end);

                w1.Dodaj_kraw(w2);
                w2.Dodaj_kraw(w1);
            }

            public List<string> Sasiedzi(wierzcholek w)
            {
                List<string> sasiedzi = new List<string>();

                foreach (wierzcholek w1 in w.somsiady)
                    sasiedzi.Add(w1.nazwa);

                return sasiedzi;
            }
            
            
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            PrimeCollection pc = new PrimeCollection();
            foreach (int i in pc)
                Console.WriteLine(i);
            Console.ReadLine();
        }
    }
}
