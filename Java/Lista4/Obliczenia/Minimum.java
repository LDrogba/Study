package Obliczenia;
/** klasa definiajaca minimum*/
public class Minimum extends Operatory_2_arg {

    /**
     * Konstruktor wyrazenia-Minimum
     * @param w1 - 1 parametr do porownania
     * @param u - 2 parametr do porownania
     */
    public Minimum(Wyrazenie w1, Wyrazenie u){
        super(w1, u);
    }
    @Override
    public double Oblicz() {
        return Math.min(w1.Oblicz(), w2.Oblicz());
    }

    @Override
    public String toString() {
        return ("min(" + w1.toString() + ", " + w2.toString() + ")" );
    }

    @Override
    public boolean equals(Object obj) {
        Minimum a = (Minimum) obj;
        return a.Oblicz() == Oblicz();
    }
}
