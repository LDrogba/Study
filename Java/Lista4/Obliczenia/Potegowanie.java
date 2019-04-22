package Obliczenia;
/** klasa definiajaca potegowanie*/
public class Potegowanie extends Operatory_2_arg {

    /**
     * Konstruktor wyrazenia-Potegowanie
     * @param w1 - Liczba potegowana
     * @param u - Wykladnik
     */
    public Potegowanie(Wyrazenie w1, Wyrazenie u){
        super(w1, u);
    }

    @Override
    public double Oblicz() {
        return Math.pow(w1.Oblicz(), w2.Oblicz());
    }

    @Override
    public String toString() {
        return (w1.toString() + "^" + w2.toString());
    }

    @Override
    public boolean equals(Object obj) {
        Potegowanie a = (Potegowanie) obj;
        return a.Oblicz() == Oblicz();
    }
}
