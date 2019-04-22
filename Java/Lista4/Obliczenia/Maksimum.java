package Obliczenia;
/** klasa definiajaca maksimum*/
public class Maksimum extends Operatory_2_arg {

    /**
     * Konstruktor wyrazenia-Maksimum
     * @param w1 - 1 parametr do porownania
     * @param u - 2 parametr do porownania
     */
    public Maksimum(Wyrazenie w1, Wyrazenie u){
        super(w1, u);
    }

    @Override
    public double Oblicz() {
        return Math.max(w1.Oblicz(), w2.Oblicz()) ;
    }

    @Override
    public String toString() {
        return ("max(" + w1.toString() + ", " + w2.toString() + ")" );
    }

    @Override
    public boolean equals(Object obj) {
        Maksimum a = (Maksimum) obj;
        return a.Oblicz() == Oblicz();
    }
}
