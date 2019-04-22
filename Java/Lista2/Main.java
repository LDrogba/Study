package geometria;


//FUNKCJA POMOCNICZA DO SPRAWDZANIA CZY JEST MOZLIWE STWORZENIE TROJKATA O PODANYCH PUNKTACH
class Poprawny_trojkat{

    Punkt a, b, c;

    public Poprawny_trojkat(Punkt a1, Punkt b1, Punkt c1){
        a = a1;
        b = b1;
        c = c1;
    }

    public boolean Czy_jest_poprawny(){
        double o1, o2, o3;
        o1 = Math.sqrt(Math.pow(a.Get_x() - b.Get_x(), 2) + Math.pow(a.Get_y() - b.Get_y(), 2));
        o2 = Math.sqrt(Math.pow(a.Get_x() - b.Get_x(), 2) + Math.pow(c.Get_y() - c.Get_y(), 2));
        o3 = Math.sqrt(Math.pow(b.Get_x() - b.Get_x(), 2) + Math.pow(c.Get_y() - c.Get_y(), 2));

        if ( o1 < o2 + o3 )
            if ( o2 < o2 + o3 )
                if ( o3 < o1 + o2)
                    return true;
        return false;
    }

}

class Punkt{
    private double x;
    private double y;

    public double Get_x(){
        return x;
    }
    public double Get_y(){
        return y;
    }



    public Punkt(double a, double b) {
        x = a;
        y = b;
    }

    public void Przesun(Wektor w){
        x = x + w.dx;
        y = y + w.dy;
    }

    public void Obroc(Punkt p, double k){
        double tmp_x, tmp_y;
        tmp_x = ((x - p.Get_x())*Math.cos(k) - (y - p.Get_y()) * Math.sin(k)) + p.Get_x();
        tmp_y = ((x - p.Get_x())*Math.sin(k) + (y - p.Get_y()) * Math.cos(k)) + p.Get_y();

        x = tmp_x;
        y = tmp_y;
    }


}

class Odcinek{
    Punkt p1;
    Punkt p2;

    public Odcinek(Punkt a, Punkt b){
        if (a.Get_x() != b.Get_x() || a.Get_y() != b.Get_y()) {
            p1 = a;
            p2 = b;
        }
        throw new NumberFormatException();
    }


    public void Przesun (Wektor w){
        p1.Przesun(w);
        p2.Przesun(w);
    }

    public void Obroc(Punkt p, double k){
        p1.Obroc(p, k);
        p2.Obroc(p, k);
    }
}

class Trojkat{
    Punkt a;
    Punkt b;
    Punkt c;

    public Trojkat(Punkt a1, Punkt b1, Punkt c1){
        Poprawny_trojkat Pop = new Poprawny_trojkat(a, b, c);
        if (Pop.Czy_jest_poprawny()){
            a = a1;
            b = b1;
            c = c1;
        }
        throw new NumberFormatException();
    }

}

class Wektor{
    final public double dx;
    final public double dy;

    public Wektor(double x, double y){
        dx = x;
        dy = y;
    }
    public static Wektor Zloz_wektor(Wektor w1, Wektor w2){
        return new Wektor(w1.dx + w2.dx, w1.dy + w2.dy);
    }
}

class Prosta{
    final public double A;
    final public double B;
    final public double C;

    public Prosta(double a, double b, double c){
        A = a;
        B = b;
        C = c;
    }

    public static Prosta Przesun_prosta_o_wektor(Prosta p, Wektor w){
        return new Prosta(p.A + w.dx * p.B, p.B, p.C + w.dy * p.B);
    }

    public static boolean Czy_rownolegle(Prosta p1, Prosta p2){
        return (p1.A/p1.B == p2.A/p2.B);
    }

    public static boolean Czy_prostopadle(Prosta p1, Prosta p2){
        return (p1.A/p1.B * p2.A/p2.B == -1);
    }

    public static Punkt Punkt_przeciecia(Prosta p1, Prosta p2){
        double a1, a2, c1, c2, x, y;
        a1 = p1.A / p1.B;
        a2 = p2.A / p2.B;
        c1 = p1.C / p1.B;
        c2 = p2.C / p2.B;

        x = (c1+c2) / a1+a2;

        y = a1 * x + c1;

        return new Punkt(x, y);
    }
}

public class Main {

    public static void main(String[] args) {
	// write your code here
        Wektor w1 = new Wektor(5, 3);
        Punkt p1 = new Punkt(1,1);
        System.out.print("Punkt" + p1.Get_x() + p1.Get_y() + "przesuniety o Wektor " + w1.dx + ", " + w1.dy);
        p1.Przesun(w1);
        System.out.println(p1.Get_x() + p1.Get_y());
    }
}
