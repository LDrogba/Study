package Obliczenia;

/** klasa definiujaca atg */
public class ArcusTanges extends Operator_1_arg {
    /**
     * konstruktor wyrazenia-ArcusTanges
     * @param w1 - wyrazenie ktorego atg bedzie wyliczony
     */
    public ArcusTanges(Wyrazenie w1){
        super(w1);
    }


    @Override
    public double Oblicz() {
        return Math.atan(Math.toRadians(w1.Oblicz()) );
    }

    @Override
    public String toString() {
        return ("Arctan(" + w1.toString() + ")");
    }

    @Override
    public boolean equals(Object obj) {
        ArcusTanges a = (ArcusTanges) obj;
        return a.Oblicz() == Oblicz();
    }
}
