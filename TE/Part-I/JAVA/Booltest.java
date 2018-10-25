import java.util.Scanner;
class Booltest
{
	public static void main (String args[])
	{
		boolean a;
		Scanner sc = new Scanner(System.in);
		System.out.print("\n\nEnter bool\n");
		a = sc.nextBoolean();
		System.out.println("\n\nBool value is : " + a);
	}
}