package com.drogba;
import  java.io.*;
import java.util.*;

abstract class LazyList {
    protected List<Integer> Data = new ArrayList<Integer>();

    public int Element(int index) throws  Exception{
        while(Data.size()<= index)
            AddElement();

        return Data.get(index);
    }

    private void AddElement() throws Exception{
        if(Data.size() == 0)
            AddFirstElement();
        else
            AddNthElement();
    }

    abstract void AddFirstElement();
    abstract void AddNthElement() throws  Exception;
}

class LazyListPrime extends LazyList implements Serializable{

    @Override
    void AddFirstElement() {
        Data.add(2);
    }

    @Override
    void AddNthElement() throws Exception {
        int candidate = Data.get(Data.size() - 1) + 1;

        while (true) {
            boolean prime = true;
            for (int var : Data)
            {
                if (candidate % var == 0)
                {
                    prime = false;
                    break;
                }
            }

            if (prime)
            {
                Data.add(candidate);
                return;
            }

            if (candidate == Integer.MAX_VALUE)
                throw new Exception("Access beyond prime list size");

            candidate++;
        }

    }
}

class Zad4 {
    public static void Test_1(String[] args) {
        LazyListPrime ll = new LazyListPrime();

        System.out.println("ZADANIE 4 - TEST 1");

        try {
            for (int i = 0; i < 20; i++)
                System.out.println(i + ": " + ll.Element(i));

            System.out.println(10 + ": " + ll.Element(10));
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        try {
            FileOutputStream fileOut =
                    new FileOutputStream("lista6_zad1.ser");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(ll);
            out.close();
            fileOut.close();
            System.out.printf("Serialized data is saved in lista6_zad1.ser");
        } catch (IOException i) {
            i.printStackTrace();
        }

        LazyListPrime ll2 = null;

        try {
            FileInputStream fileIn = new FileInputStream("lista6_zad1.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);
            ll2 = (LazyListPrime) in.readObject();
            in.close();
            fileIn.close();
        } catch (IOException i) {
            i.printStackTrace();
            return;
        } catch (ClassNotFoundException c) {
            System.out.println("LazyListPrime class not found");
            c.printStackTrace();
            return;
        }

        try {
            for (int i = 0; i < 20; i++)
                System.out.println(i + ": " + ll2.Element(i));

            System.out.println(10 + ": " + ll2.Element(10));
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

    }
}


public class Main {

    public static void main(String[] args) {
	// write your code here
    Zad4.Test_1(args);
    }
}
