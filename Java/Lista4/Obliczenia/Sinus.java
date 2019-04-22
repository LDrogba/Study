package Obliczenia;
/** klasa definiajaca sinus*/
public class Sinus extends Operator_1_arg {

    /**
     * Konstuktor dla Wyrazenia-Sinus
     * @param w1 - wyrazenie ktorego sins bedziemy obliczac
     */
    public Sinus(Wyrazenie w1){
        super(w1);
    }

    @Override
    public double Oblicz() {
        return Math.sin(Math.toRadians(w1.Oblicz()) );
    }

    @Override
    public String toString() {
        return ("Sin(" + w1.toString() + ")");
    }

    @Override
    public boolean equals(Object obj) {
        Sinus a = (Sinus) obj;
        return a.Oblicz() == Oblicz();
    }
}
