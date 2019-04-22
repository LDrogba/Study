using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test1
{
    #region ZADANIE_4
    abstract class LazyList
    {
        protected List<int> data = new List<int>();

        public int Element(int Index)
        {
            while (data.Count <= Index)
                AddElement();

            return data[Index];
        }

        private void AddElement()
        {
            if (data.Count == 0)
                AddFirstElement();
            else
                AddNthElement();
        }

        protected abstract void AddFirstElement();

        protected abstract void AddNthElement();
    }

    class LazyListPrime : LazyList
    {
        protected override void AddFirstElement()
        {
            data.Add(2);
        }

        protected override void AddNthElement()
        {
            int candidate = data[data.Count - 1] + 1;

            while (true)
            {
                bool prime = true;
                foreach (int var in data)
                {
                    if (candidate % var == 0)
                    {
                        prime = false;
                        break;
                    }
                }

                if (prime)
                {
                    data.Add(candidate);
                    return;
                }

                if (candidate == Int32.MaxValue)
                    throw new Exception("Access beyond prime list size");

                candidate++;
            }
        }
    }

    class Zad4
    {
        public static void Test_1(string[] args)
        {
            LazyListPrime ll = new LazyListPrime();

            Console.WriteLine("ZADANIE 4 - TEST 1");

            try
            {
                for (int i = 0; i < 20; i++)
                    Console.WriteLine("test 1 : " + ll.Element(i));

                Console.WriteLine("test 2 : " + ll.Element(10));
            }
            catch (Exception e)
            {
                Console.WriteLine("Error: " + e.Message);
            }

            //Console.ReadLine();
        }
    }
    #endregion

    #region ZADANIE_1
    class IntStream
    {
        private int last = -1;

        public int next()
        {
            if (!eos())
                last++;

            return last;
        }

        public bool eos()
        {
            return last == Int32.MaxValue;
        }

        public void reset()
        {
            last = -1;
        }
    }

    /// <summary>
    /// Strumien liczb pierwszych
    /// </summary>
    class PrimeStream
    {
        int next_prime = 2;

        public int next()
        {
            int v = next_prime;
            next_prime = FindNextPrime();
            return v;
        }

        public bool eos()
        {
            return next_prime == Int32.MaxValue;
        }

        public void reset()
        {
            next_prime = 2;
        }

        private int FindNextPrime()
        {
            if (eos())
                return next_prime;

            int candidate = next_prime + 1;
            if (candidate % 2 == 0)
                candidate++;

            while (candidate < Int32.MaxValue)
            {
                bool prime = true;

                for (int d = 3; d <= Math.Sqrt(candidate); d += 2)
                {
                    if (candidate % d == 0)
                    {
                        prime = false;
                        break;
                    }
                }

                if (prime)
                    return candidate;

                if (candidate <= Int32.MaxValue - 2)
                    candidate += 2;
            }

            return Int32.MaxValue;
        }
    }

    class RandomStream
    {
        Random rnd = new Random();

        public int next()
        {
            return rnd.Next();
        }

        public bool eos()
        {
            return false;
        }

        public void reset()
        {
        }
    }

    class RandomWordStream
    {
        PrimeStream primeStream = new PrimeStream();

        class WordGen
        {
            static RandomStream rndStream = new RandomStream();

            public static string Generate(int len)
            {
                string val = "";

                for (int i = 0; i < len; i++)
                    val += Convert.ToChar('a' + rndStream.next() % 26);

                return val;
            }
        }

        public string next()
        {
            int wordLen = primeStream.next();
            return WordGen.Generate(wordLen);
        }

        public bool eos()
        {
            return primeStream.eos();
        }

        public void reset()
        {
            primeStream.reset();
        }
    }

    class Zad1
    {
        public static void Test_1(string[] args)
        {
            Console.WriteLine("ZADANIE 1 - TEST 1");

            PrimeStream ps = new PrimeStream();
            RandomWordStream rndWordStream = new RandomWordStream();

            for (int i = 0; i < 14; i++)
                Console.WriteLine(ps.next() + " : " + rndWordStream.next());

            ps.reset();

#if LONG_TEST
	    while(!ps.eos())
	    {
		Console.WriteLine( ps.next() );
	    }
#endif
        }
    }

    class Program
    {
        public static int Main(string[] Args)
        {
            Zad1.Test_1(Args);

            Zad4.Test_1(Args);

            Console.ReadLine();

            return 0;
        }
    }
    #endregion
}
