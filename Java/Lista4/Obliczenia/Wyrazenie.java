package Obliczenia;
/** klasa absttakcyjna zawierajaca dwie statyczne metody suma i iloczyn */

public abstract class Wyrazenie implements Obliczalny {
    /** metoda dodajaca wyrazenia */
    public static double suma (Wyrazenie... wyr) throws Exception {
        double sum = 0;
        for(Wyrazenie w : wyr)
            sum += w.Oblicz();
        return sum;
    }

    /** metoda mnożąca wyrażenia */
    public static double iloczyn (Wyrazenie... wyr) throws Exception {
        double mn = 1;
        for(Wyrazenie w : wyr)
            mn *= w.Oblicz();
        return  mn;
    }
}
