import Obliczenia.*;
import struktury.*;

public class Main{

    public static void main(String[] args) throws Exception{

        Wyrazenie w1 = new Odejmowanie(
                new Stala("Pi"),
                new Dodawanie(
                        new Liczba(2),
                        new Mnozenie(
                                new Zmienna("x"),
                                new Liczba(7))
                )
        );
        Wyrazenie w2 = new Dzielenie(
                new Dodawanie(
                        new Liczba(3),
                        new Liczba(5)),
                new Dodawanie(
                        new Liczba(2),
                        new Mnozenie(
                                new Zmienna("x"),
                                new Liczba(7))));

        Wyrazenie w3 = new Odejmowanie(
                new Dodawanie(
                        new Liczba(2),
                        new Mnozenie(
                                new Zmienna("x"),
                                new Liczba(7))),
                new Dodawanie(
                        new Mnozenie(
                                new Zmienna("x"),
                                new Liczba(3)),
                        new Liczba(5)));

        Wyrazenie w4 = new Dzielenie(
                new Cosinus(
                        new Mnozenie(
                                new Dodawanie(
                                        new Zmienna("x"),
                                        new Liczba(1)),
                                new Zmienna("x"))),
                new Potegowanie(
                        new Zmienna("x"),
                        new Potegowanie(
                                new Zmienna("x"),
                                new Liczba(2))));

        Wyrazenie test1 = new Dodawanie(
                new Liczba(3),
                new Liczba(5)
        );

        Wyrazenie test2 = new Dodawanie(
                new Liczba(7),
                new Mnozenie(
                        new Zmienna("x"),
                        new Liczba(5)
                )
        );

        Wyrazenie test3 = new Dzielenie(
                            new Odejmowanie(
                                    new Mnozenie(
                                        new Liczba(3),
                                        new Liczba(11)),
                                    new Liczba(1)),
                            new  Dodawanie(
                                new Liczba(7),
                                new Liczba(5)));



        Zmienna x = new Zmienna("x");
        x.Set_war(1);
        Zmienna y = new Zmienna("y");
        y.Set_war(2);

        System.out.print(test1.toString() + "=");
        System.out.println(test1.Oblicz());
        System.out.print(test2.toString() + "=");
        System.out.println(test2.Oblicz());
        System.out.print(test3.toString() + "=");
        System.out.println(test3.Oblicz());

        System.out.print(w1.toString() + "=");
        System.out.println(w1.Oblicz());
        System.out.print(w2.toString() + "=");
        System.out.println(w2.Oblicz());
        System.out.print(w3.toString() + "=");
        System.out.println(w3.Oblicz());
        System.out.print(w4.toString() + "=");
        System.out.println(w4.Oblicz());

    }
}
