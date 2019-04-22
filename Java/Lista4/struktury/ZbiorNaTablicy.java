package struktury;

/**
 * Klasa przechowujaca pary w tablicy, dziedziczy po klasie Zbior */
public class ZbiorNaTablicy extends Zbior{
    protected Para[] Array;

    public ZbiorNaTablicy(){
    }

    /**
     * Tworzy obiekt o okreslonym rozmiarze
     * @param size - rozmiar zbioru
     * @throws Exception - jezeli rozmiar jest mniejszy niz 2 to zwracamy blad
     */

    public ZbiorNaTablicy(int size) throws Exception {
        if(size<2)
            throw new Exception("rozmiar musi byc rowny co najmniej 2");
        else
            Array = new Para[size];
    }

    /**
     * Wyszukuje wartosci dla podanego klucza
     * @param k - poszukiwany klucz w zbiorze
     * @return - para o podanym kluczu
     * @throws Exception - jezeli w naszym zbiorze nie istanieje para o podanym kluczu zwracany jest blad
     */

    @Override
    public Para szukaj(String k) {
        for (Para p : Array) {
            if (p.klucz == k)
                return p;
        }
        return null;
    }

    /**
     * Wstawia do naszego zbioru nowa pare
     * @param p - nowa para ktora bedzie wstawiona do zbioru
     * @throws Exception - jezeli zbior jest juz pelny to zwracany jest blad mowiacy o braku miejsca
     */

    @Override
    public void wstaw(Para p) throws Exception {
        for(int i = 0; i<Array.length; i++){
            if (p.equals(Array[i]))
                throw new Exception("Nie moze byc dwoch par z tym samym kluczem");
            if (Array[i] == null) {
                Array[i]= p;
                return;
            }
        }
        throw new Exception("Brak miejsca w zbiorze na nowa pare");
    }

    /**
     * Wyszukuje jaka wartosc jest dla danego klucza
     * @param k - poszukiwany klucz w zbiorze
     * @return - wartosc dla podanego klucza
     * @throws Exception - jezeli w zbiorze nie znaleziono pary o podanym kluczu, zwracany jest blad
     */
    @Override
    public double czytaj(String k){
        Para tmp = this.szukaj(k);
        return tmp.Get_War();
    }

    /**
     * Sprawdzane jest czy w zbiorze znajduje sie juz para o takim samym klucuz i jezeli tak to zmianiana jest jego
     * wartosc, a jezeli nie ma jeszcze takiej pary, to jest ona dodawana
     * @param p - para ktora ma byc dodana lub ktora ma zaktualizowac istaniejaca juz pare o takim samym kluczu
     * @throws Exception - jezeli w zbiorze nbie istnieje para o takim samym kluczu, a w zbiorze nie ma juz miejsca to
     * zwaracany jest blad mowiacy o braku miejsca w zbiorze
     */
    @Override
    public void ustaw(Para p) throws Exception {
        for (Para i_p : Array){
            if (i_p == null) {
                wstaw(p);
                return;
            }
            if (i_p.equals(p)) {
                i_p.Set_War(p.Get_War());
                return;
            }
        }
        wstaw(p);
    }

    /**
     * Caly zbior zostaje wyczyszczony
     */
    @Override
    public void czysc() {
        for (Para i_p : Array){
            i_p = null;
        }
    }

    /**
     *
     * @return ilosc elementow w zbiorze
     */
    @Override
    public int ile() {
        int n = 0;
        for (Para i_p : Array){
            if(i_p != null)
                n++;
        }
        return  n;
    }

    /**
     * Metoda wypisuje caly zbior
     */
    @Override
    public void wypisz_zbior(){
        for(Para i_p : Array)
            System.out.println(i_p);
    }
}

