package Obliczenia;
/** klasa definiajaca logarytmowanie*/
public class Logarytmowanie extends Operatory_2_arg {

    /**
     * Konstruktor wyrazenia-Logarytmowanie
     * @param w1 - podstawa logarytmu
     * @param u - wyrazenie logarytmowane
     */
    public Logarytmowanie(Wyrazenie w1, Wyrazenie u){
        super(w1, u);
    }
    @Override
    public double Oblicz() {
        return Math.log(w2.Oblicz()) / Math.log(w1.Oblicz());
    }

    @Override
    public String toString() {
        return ("log" + w1.toString() + "(" + w2.toString() + ")");
    }

    @Override
    public boolean equals(Object obj) {
        Logarytmowanie a = (Logarytmowanie) obj;
        return a.Oblicz() == Oblicz();
    }
}
