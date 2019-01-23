using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A22_4
{
    class Program
    {
        static void Main(string[] args)
        {
            int num, k = 0;
            int i = 0;
            Console.WriteLine("Check whether number is prime or not");
            Console.WriteLine("\n\nEnter a number");
            num = Convert.ToInt32(Console.ReadLine());
            for (i = 1; i <= num; i++) {
                if (num % i == 0)
                    k++;
            }
            if (k == 2)
                Console.WriteLine("\nThe number " + num + " is Prime");
            else
                Console.WriteLine("\nThe number " + num + " is Not Prime");
            Console.ReadKey();
        }
    }
}
