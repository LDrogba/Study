package Obliczenia;
/** klasa definiujaca wyrazenie-liczbe */
public class Liczba extends Wyrazenie{
    /**
     * Konstruktor dla wyrazenia-Liczba
     * @param k - wartosc
     */
    public Liczba(double k){ wartosc = k;}

    public double wartosc;

    @Override
    public double Oblicz() {
        return wartosc;
    }

    @Override
    public String toString() {
        return String.valueOf(wartosc);
    }

    @Override
    public boolean equals(Object obj) {
        Liczba a = (Liczba) obj;
        return a.Oblicz() == Oblicz();
    }
}
