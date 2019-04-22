package Obliczenia;

/** klasa abstarkycjna definiujaca dodawanie dwoch wyrazen */

public class Dodawanie extends Operatory_2_arg {
    /**
     * Konstruktor wyrazenia-Dodawanie
     * @param w1 - 1 parametr dla dodawania
     * @param u - 2 parametr dla dodawania
     */
    public Dodawanie(Wyrazenie w1, Wyrazenie u){
        super(w1, u);
    }

    @Override
    public double Oblicz() {
        return w1.Oblicz() + w2.Oblicz();
    }

    @Override
    public String toString() {
        return ("(" + w1.toString() + "+" + w2.toString() + ")");
    }

    @Override
    public boolean equals(Object obj) {
        Dodawanie a = (Dodawanie) obj;
        return a.Oblicz() == Oblicz();
    }
}
