import  java.io.*;
import java.lang.reflect.Array;
import  java.util.List;
import  java.util.ArrayList;
import  java.util.Arrays;
import  java.lang.Thread;

class TabSortThread extends  Thread
{
    Thread thr;
    String name;
    int begin;
    int end;
    int []tab;

    public TabSortThread(int [] tab, int begin, int end, String name)
    {
        this.end = end;
        this.begin = begin;
        this.tab = tab;
        this.name = name;
    }

    public void run()
    {
        System.out.println("RUN" + " " +name);
        Arrays.sort(tab, begin, end+1);
        System.out.println(name);
        System.out.println("STOP" + " " + name);
    }

    public void start() {
        if (thr == null) {
            thr = new Thread(this, name);
            thr.start();
        }
    }

    public boolean IsAlive()
    {
        return thr.isAlive();
    }
}

class SortowanieWielowatkowe
{

    int[] tab_to_sort;
    TabSortThread half1;
    TabSortThread half2;

    public SortowanieWielowatkowe(int[] Tab)
    {
        tab_to_sort = Tab;
        half1 =  new TabSortThread(Tab, 0, Tab.length/2-1, "half_1");
        half2 =  new TabSortThread(Tab, Tab.length/2, Tab.length-1, "half_2");
    }

    void Merge(TabSortThread tab1, TabSortThread tab2)
    {
        int l = 0, r = tab_to_sort.length/2;
        int [] sorted = new int[tab_to_sort.length];

        for(int i=0; i< tab_to_sort.length; i++)
        {
            if(l == tab_to_sort.length/2){
                sorted[i] = tab2.tab[r];
                r++;
            }
            else if( r == tab_to_sort.length){
                sorted[i] = tab1.tab[l];
                l++;
            }
            else if(tab1.tab[l] <= tab2.tab[r]) {
                sorted[i] = tab1.tab[l];
                l++;
            }
            else{
                sorted[i] = tab2.tab[r];
                r++;
            }
        }

        for (int i=0; i<tab_to_sort.length; i++)
            tab_to_sort[i] = sorted[i];
    }

    void Sort(TabSortThread t1, TabSortThread t2)
    {
        t1.start();
        t2.start();
        while(t1.IsAlive() || t2.IsAlive());
        Merge(t1,t2);
    }
}


public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] tablica = {0,3,2,4,5,3};

        System.out.println("Nieposortowana");

        for (int i: tablica) {
            System.out.println(i);
        }

        SortowanieWielowatkowe k = new SortowanieWielowatkowe(tablica);

        k.Sort(k.half1, k.half2);

        System.out.println("Posortowana: ");

        for (int i: tablica) {
            System.out.println(i);
        }
    }
}
