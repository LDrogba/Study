package Obliczenia;

import java.lang.Exception;
import struktury.Para;
import struktury.ZbiorNaTablicyDynamicznej;
/** klasa definiujaca wyrazenie-zmienna zawiera statyczny zbior wszystkich zeminnych */
public class Zmienna extends Wyrazenie{
    String z;
    /** ustawia wartosc zmiennej */

    public void Set_war(double k) throws Exception{
        Zmienne.ustaw(new Para(z, k));
    }

    /**
     * Konstruktor nowez zmiennej
     * @param s nazwa zmiennej
     */
    public Zmienna(String s){ z = s;}

    /**
     * tablica zmiennych dostepnych w programie
     */
    public static ZbiorNaTablicyDynamicznej Zmienne = new ZbiorNaTablicyDynamicznej();

    @Override
    public double Oblicz(){
        return Zmienne.czytaj(z);
    }

    @Override
    public String toString() {
        return z;
    }

    @Override
    public boolean equals(Object obj) {
        Zmienna a = (Zmienna) obj;
        return a.Oblicz() == Oblicz();
    }
}
