public class translation {

    private static String translacja(long liczba) {
        String[] jednosci = {"", "jeden ", "dwa ", "trzy ", "cztery ",
                "pięć ", "sześć ", "siedem ", "osiem ", "dziewięć ",};

        String[] nastki = {"", "jedenaście ", "dwanaście ", "trzynaście ",
                "czternaście ", "piętnaście ", "szesnaście ", "siedemnaście ",
                "osiemnaście ", "dziewiętnaście ",};

        String[] dziesiatki = {"", "dziesięć ", "dwadzieścia ",
                "trzydzieści ", "czterdzieści ", "pięćdziesiąt ",
                "sześćdziesiąt ", "siedemdziesiąt ", "osiemdziesiąt ",
                "dziewięćdziesiąt ",};

        String[] setki = {"", "sto ", "dwieście ", "trzysta ", "czterysta ",
                "pięćset ", "sześćset ", "siedemset ", "osiemset ",
                "dziewięćset ",};

        String[][] przedzial = {{"", "", ""},
                {"tysiąc ", "tysiące ", "tysięcy "},
                {"milion ", "miliony ", "milionów "},
                {"miliard ", "miliardy "},};

        long j = 0; // jednosci
        long n = 0; // nastki
        long d = 0; // dziesiatki
        long s = 0; // setki
        long p = 0; // przedzial
        long k = 0; // koncowki
        String slownie = "";
        String znak = "";

        if (liczba < 0) {
            znak = "minus ";
            liczba = -liczba; // bezwgledna wartosc poniewaz, jesli będziemy
// operowac na liczbie z minusem tablica bedzie
// przyjmowala wartosci ujemne i zwroci nam blad
        }
        else if (liczba == 0) {
            znak = "zero";
            return znak;
        }

        while (liczba != 0) {
            s = liczba % 1000 / 100;
            d = liczba % 100 / 10;
            j = liczba % 10;

            if (d == 1 & j > 0) // if zajmujacy sie nastkami
            {
                n = j;
                d = 0;
                j = 0;
            } else {
                n = 0;
            }

// <---- KONCOWKI

            if (j == 1 & s + d + n == 0) {
                k = 0;

                if (s + d == 0 && p > 0) // jeśli nie będzie dziesiątek ani setek, wtedy otrzymamy sam przedzial
                { // przykładowo 1000 - wyświetli nam się "tysiac", a bez tego ifa bedzie "jeden tysiac"
                    j = 0;
                    slownie = przedzial[(int) p][(int) k] + slownie;
                }
            } else if (j == 2) {
                k = 1;
            } else if (j == 3) {
                k = 1;
            } else if (j == 4) {
                k = 1;
            } else {
                k = 2;
            }

// KONIEC KONCOWEK

            if (s + d + n + j > 0) {
                slownie = setki[(int) s] + dziesiatki[(int) d] + nastki[(int) n]
                        + jednosci[(int) j] + przedzial[(int) p][(int) k] + slownie;
            }

            liczba = liczba / 1000;
            p++;
        }

        slownie = znak + slownie;
        return slownie;

    }

    public static void main(String[] args){
        try {
            for (String arg : args) {
                long x = Long.parseLong(arg);
                if (x > 2147483647 || x < -2147483648)
                    throw new NumberFormatException();
                else
                    System.out.println(translation.translacja(x));
            }
        }catch (NumberFormatException e){
            System.err.println("Przekroczono wartosc INT");
        }
    }
}
