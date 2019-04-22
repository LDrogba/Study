package Obliczenia;

/** klasa definijaca wartosc bezwzgledna wyrazenia */

public class Bezwzgledna extends Operator_1_arg {

    /**
     * Konstruktor wyrazenia-Bezwgledna
     * @param w1 wyrazenie ktorego wartosc bezwzgledna bedzie wyliczona
     */
    public Bezwzgledna(Wyrazenie w1){
        super(w1);
    }

    @Override
    public double Oblicz() {
        if(w1.Oblicz() < 0)
            return w1.Oblicz()*-1;

        return w1.Oblicz();
    }

    @Override
    public String toString() {
        return ("|" + w1.toString() + "|");
    }

    @Override
    public boolean equals(Object obj) {
        Bezwzgledna a = (Bezwzgledna) obj;
        return a.Oblicz() == Oblicz();
    }
}
