package basicshapes;
import java.util.Scanner;
public class Rectangle
{
	public void rectangleArea() {
		int l, b;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter length and breadth of Rectangle");
		l = sc.nextInt();
		b = sc.nextInt();
		System.out.println("Area of Rectangle : " + l * b);
	}
}