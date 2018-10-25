package basicshapes;
import java.util.Scanner;
public class Square
{
	public void squareArea() {
		int s;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Side of Square");
		s = sc.nextInt();
		System.out.println("Area of Square : " + s * s);
	}
}