using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A22_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Int32 num, i;
            Int32 f1 = 0, f2 = 1, f;
            Console.WriteLine("Fibonacci Series");
            Console.WriteLine("\n\nEnter a number");
            num = Convert.ToInt32(Console.ReadLine());
            Console.Write(f1 + " " + f2 + " ");
            for (i = 0; i < num; i++) {
                f = f1 + f2;
                f1 = f2;
                f2 = f;
                Console.Write(f + " ");
            }
            Console.ReadKey();
        }
    }
}
