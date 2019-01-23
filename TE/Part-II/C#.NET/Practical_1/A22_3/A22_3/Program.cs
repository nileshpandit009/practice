using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A22_3
{
    class Program
    {
        static void Main(string[] args)
        {
            Int32 num, fact, i;
            Console.WriteLine("Factorial of a number");
            Console.WriteLine("\n\nEnter a number");
            num = Convert.ToInt32(Console.ReadLine());
            fact = num;
            for (i = num - 1; i > 0 ; i--)
                fact = fact * i;
            Console.WriteLine("\nFactorial = " + fact);
            Console.ReadKey();
        }
    }
}
