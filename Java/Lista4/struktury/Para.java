package struktury;

/**
 * Klasa Para definiuje pare, ktora sklada sie z publicznego finalnego pola "klucz"(string) oraz prywatnego pola
 * "wartosc" (double). Posiada tez metody odpowiedzialne za: zwrocenie wartosci (Get_War()),
 * ustawienie wartosci (Set_War(), zamienienie klucza i wartosci na string gotowy do wypisania (toString()) oraz
 * sprawdzenie czy dwie pary maja taki sam klucz (Equals)
 */
public class Para{
    public final String klucz;
    private double wartosc;

    /**
     * Tworzy nowa pare
     * @param k - klucz tej pary
     * @param w - wartosc tej pary
     */
    public Para(String k, double w){
        klucz = k;
        wartosc = w;
    }

    /**
     * Zwaraca pole wartosc
     * @return wartosc z tej pary
     */
    public double Get_War(){
        return  wartosc;
    }

    /**
     * Zmienia wartosc
     * @param new_war - wartosc ktora stanie sie nowa wartoscia
     */
    public void Set_War(double new_war){
        wartosc = new_war;
    }

    /**
     * nadpisuje wbudowana metode toString tak aby mozna bylo wypisac pare
     * @return klucz oraz wartosc jako jeden ciag znakow
     */
    public String toString(){
        return (this.klucz + ", " + this.wartosc);
    }

    /**
     * Nadpisuje metode equals tak aby mozna bylo porownac dwie pary, pary sa sobie rowne jezeli ich klucze sa takie
     * same
     * @param p - para z ktora jest porownywana
     * @return prawda jezeli pary maja takie same klucze, falsz jezeli nie maja takich samych kluczy
     */
    public boolean equals(Object p){
        if (p == null)
            return false;
        Para tmp =(Para)p;
        return (tmp.klucz == klucz);
    }
}