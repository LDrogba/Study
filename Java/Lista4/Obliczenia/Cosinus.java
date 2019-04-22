package Obliczenia;

/** klasa definiujaca cosinus */
public class Cosinus extends Operator_1_arg {
    /**
     * Konstruktor wyrazenia-Cosinus
     * @param w1 - wyrazenie ktorego cosinus bedzie policzony
     */
    public Cosinus(Wyrazenie w1){
        super(w1);
    }


    @Override
    public double Oblicz() {
        return Math.cos(Math.toRadians(w1.Oblicz()) );
    }

    @Override
    public String toString() {
        return ("Cos(" + w1.toString() + ")");
    }

    @Override
    public boolean equals(Object obj) {
        Cosinus a = (Cosinus) obj;
        return a.Oblicz() == Oblicz();
    }
}
