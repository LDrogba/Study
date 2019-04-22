package Obliczenia;
/** klasa definiajaca mnozenie*/
public class Mnozenie extends Operatory_2_arg {

    /**
     * Konstruktor wyrazenia-Mnozenie
     * @param w1 - 1 parametr mnozenia
     * @param u - 2 parametr mnozenia
     */
    public Mnozenie(Wyrazenie w1, Wyrazenie u){
        super(w1, u);
    }
    @Override
    public double Oblicz() {
        return w1.Oblicz() * w2.Oblicz();
    }

    @Override
    public String toString() {
        return (w1.toString() + "*" + w2.toString());
    }

    @Override
    public boolean equals(Object obj) {
        Cosinus a = (Cosinus) obj;
        return a.Oblicz() == Oblicz();
    }
}
