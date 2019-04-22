package Obliczenia;
/** klasa definiajaca przeciwienstwo*/
public class Przeciwienstwo extends Operator_1_arg {

    /**
     * Konstruktor wyrazenia-Przeciwienstwo
     * @param w1 - wyrazenie ktorego przeciwienstwo bedziemy obliczac
     */
    public Przeciwienstwo(Wyrazenie w1){
        super(w1);
    }

    @Override
    public double Oblicz() {
        return w1.Oblicz() * (-1);
    }

    @Override
    public String toString() {
        return ("-" + w1.toString());
    }

    @Override
    public boolean equals(Object obj) {
        Przeciwienstwo a = (Przeciwienstwo) obj;
        return a.Oblicz() == Oblicz();
    }
}
