package Obliczenia;
/** klasa definiajaca odwrotnosc*/
public class Odwrotnosc extends Operator_1_arg {

    /**
     * Konstruktor wyrazenia-Odwrotnosc
     * @param w1 - wyrazenie ktorego odwrotnosc bedziemy chcieli uzyskac
     */
    public Odwrotnosc(Wyrazenie w1){
        super(w1);
    }

    @Override
    public double Oblicz() {
        return 1/w1.Oblicz();
    }

    @Override
    public String toString() {
        return ( "(1/" + w1.toString() + ")" );
    }

    @Override
    public boolean equals(Object obj) {
        Odwrotnosc a = (Odwrotnosc) obj;
        return a.Oblicz() == Oblicz();
    }
}
