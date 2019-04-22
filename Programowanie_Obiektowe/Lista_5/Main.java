package com.drogba;
import  java.io.*;
import  java.util.List;
import  java.util.ArrayList;
public class Main {

    public static void main(String[] args) {
	// write your code here
        stos S = new stos();
        S.Push(1);
        S.Push(2);
        S.Write();
        Integer k = S.Take(1);
        S.Take(3);
        S.Write();
    }
}

class stos
{
    List<Integer> stosik = new ArrayList<Integer>();
    public void Push(Integer i)
    {
        stosik.add(i);
        stosik.sort();
    }
    public int Take(Integer i) throws StackOverflowException
    {
        if(stosik.contains(i))
        {
            stosik.remove(i);
            System.out.println("pobrano: " + i);

            return i;
        }
        else
        {
            System.out.println("brak obiektu: " + i);
            return 0;
        }
    }
    public void Write()
    {
        System.out.println("Wszystkie elementy stosu: ");
        for (int i: stosik)
        {
            System.out.println(i);
        }
    }
}