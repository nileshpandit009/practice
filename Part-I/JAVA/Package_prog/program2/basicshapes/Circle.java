package basicshapes;
import java.util.Scanner;
public class Circle
{
	public void circleArea() {
		int r;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Radius of Circle");
		r = sc.nextInt();
		System.out.println("Area of Circle : " + (double)3.14 * r * r);
	}
}