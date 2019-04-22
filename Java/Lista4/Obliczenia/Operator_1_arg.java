package Obliczenia;
/** klasa abstarkycjna definiujaca wyrazenia 1 argumentowe */
public abstract class Operator_1_arg extends Wyrazenie{
    /**
     * Wyrazenie na ktore bedziemy chcieli dzialac
     */
    protected Wyrazenie w1;

    /**
     * Konstruktor dla wyrazen jednoargumentowych
     * @param w wyrazenie
     */
    public Operator_1_arg(Wyrazenie w){ w1 = w;}
}
