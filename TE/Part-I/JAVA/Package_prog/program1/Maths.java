import Arithmetic.*;
import java.util.Scanner;

public class Maths
{
	public static void main(String args[])
	{
		int x, y;
		Scanner sc = new Scanner(System.in);

		Addition a = new Addition();
		Subtraction s = new Subtraction();
		Multiplication m = new Multiplication();
		Division d = new Division();

		System.out.println("Enter two numbers");
		x = sc.nextInt();
		y = sc.nextInt();

		a.add(x, y);
		s.sub(x, y);
		m.mul(x, y);
		d.div(x, y);
	}
}