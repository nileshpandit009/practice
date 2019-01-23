package basicshapes;
import java.util.Scanner;
public class Triangle
{
	public void triangleArea() {
		int b, h;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter base and height of Triangle");
		b = sc.nextInt();
		h = sc.nextInt();
		System.out.println("Area of Triangle : " + (double)0.5 * b * h);
	}
}