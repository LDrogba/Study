package Obliczenia;

import java.util.Hashtable;

/** klasa definiujaca wyrazenie-stala zawiera zbior stalych dostepnych */
public class Stala extends Wyrazenie {
    String nazwa;

    /**
     * Konstruktor dla Wyrazenia-Stala
     * @param s stala ktora chcemy stworzyc a tak naprawde sprawdzic czy jest w bazie naszych stalych "Stale"
     * @throws Exception jezeli nie ma stalej w naszje bazie stalych "Stale"
     */
    public Stala(String s) throws Exception{
        if(Stale.containsKey(s))
            nazwa = s;
        else
            throw new Exception("nie ma takiej stalej");
    }

    /**
     * tablica dostepnych stalych
     */
    final static Hashtable<String, Double> Stale = new Hashtable<String, Double>() {
        {
            put("Pi", 3.141569);
            put("e", 2.718281);
            put("Fi", 1.618033);
        }
    };


    @Override
    public double Oblicz() { return Stale.get(nazwa); }

    @Override
    public String toString(){ return nazwa; }

    @Override
    public boolean equals(Object obj) {
        Stala a = (Stala) obj;
        return a.Oblicz() == Oblicz();
    }
}
