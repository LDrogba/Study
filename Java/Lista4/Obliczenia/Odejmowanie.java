package Obliczenia;
/** klasa definiajaca odejmowanie*/
public class Odejmowanie extends Operatory_2_arg {

    /**
     * Konstruktor wyrazenia-Odejmowanie
     * @param w1 - 1 parametr do dodania
     * @param u - 2 parametr do dodania
     */
    public Odejmowanie(Wyrazenie w1, Wyrazenie u){
        super(w1, u);
    }

    @Override
    public double Oblicz() {
        return w1.Oblicz() - w2.Oblicz();
    }

    @Override
    public String toString() {
        return (w1.toString() + "-" + w2.toString());
    }

    @Override
    public boolean equals(Object obj) {
        Odejmowanie a = (Odejmowanie) obj;
        return a.Oblicz() == Oblicz();
    }
}
