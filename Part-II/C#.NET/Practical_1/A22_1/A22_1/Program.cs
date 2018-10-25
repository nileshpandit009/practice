using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A22_1
{
    class Program
    {
        Int32 a, b;
        static void Main(string[] args)
        {
            int a, b, c;
            Console.WriteLine("hello world");
            a = Convert.ToInt32(Console.ReadLine());
            b = Convert.ToInt32(Console.ReadLine());
            c = a + b;
            Console.WriteLine("Addition = " + c);
            Console.ReadKey();
        }
    }
}
