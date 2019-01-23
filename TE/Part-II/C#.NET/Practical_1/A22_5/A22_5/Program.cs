using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A22_5
{
    class Program
    {
        static void Main(string[] args)
        {
            int radius;
            Console.WriteLine("Area and Circumference of circle");
            Console.WriteLine("\n\nEnter radius of circle");
            radius = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("\nArea of circle = {0}", (3.14 * radius * radius));
            Console.WriteLine("\nArea of circle = {0}", (2 * 3.14 * radius));
            Console.ReadKey();
        }
    }
}
