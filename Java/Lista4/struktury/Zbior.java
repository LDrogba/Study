package struktury;

/**
 * Klada abstrakcyjna definiujaca jakie metody musi posiadac zbior
 */
public abstract class Zbior{

    /** metoda ma szukac pary z okreslonym kluczem */
    public abstract Para szukaj (String k);
    /** metoda ma wstawiac do zbioru nowa pare */
    public abstract void wstaw (Para p) throws Exception;
    /** metoda ma odszukac parc i zwrocic wartosc zwiazana z kluczem */
    public abstract double czytaj (String k);
    /** metoda ma wstawic do zbioru nowa albo zaktualizowac pare */
    public abstract void ustaw (Para p) throws Exception;
    /** metoda ma usunąc wszystkie pary ze zbioru */
    public abstract void czysc ();
    /** metoda ma podac ile par jest przechowywanych w zbiorze */
    public abstract int ile ();
    /** metoda ma wypisac caly zbior */
    public abstract  void wypisz_zbior();
}

