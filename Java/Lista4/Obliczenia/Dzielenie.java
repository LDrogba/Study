package Obliczenia;

/** klasa definiajaca dzielenie*/
public class Dzielenie extends Operatory_2_arg{

    /**
     * Konstruktor wyrazenia-Dzielenie
     * @param w1 - 1 parametr dla dzielenia
     * @param u - 2 parametr dla dzielenia
     */
    public Dzielenie(Wyrazenie w1, Wyrazenie u){
        super(w1, u);
    }

    @Override
    public double Oblicz() {
        return w1.Oblicz() / w2.Oblicz();
    }

    @Override
    public String toString() {
        return (w1.toString() + "/" + w2.toString());
    }

    @Override
    public boolean equals(Object obj) {
        Dzielenie a = (Dzielenie) obj;
        return a.Oblicz() == Oblicz();
    }
}
