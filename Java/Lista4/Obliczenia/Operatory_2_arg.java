package Obliczenia;
/** klasa abstarkcyjna definiajaca wyrazenia dwuargumentowe*/
public abstract class Operatory_2_arg  extends  Operator_1_arg{
    /**
     * wyrazenie na ktore bedziemy chcieli dzialac operatorem
     */
    protected Wyrazenie w2;

    /**
     * Konstruktor dla wyrazen dwuargumentowych
     * @param w wyrazenie 1
     * @param u wyrazenie 2
     */
    public Operatory_2_arg(Wyrazenie w, Wyrazenie u) {
        super(w);
        w2 = u;
    }
}
