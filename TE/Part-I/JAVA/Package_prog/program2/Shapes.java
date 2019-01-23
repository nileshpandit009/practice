import java.util.Scanner;
import basicshapes.*;

public class Shapes
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner (System.in);
		int r, l, b, h, s;
		r=l=b=h=s=0;
		Rectangle rt = new Rectangle();
		Circle cr = new Circle();
		Square sq = new	Square();
		Triangle tr = new Triangle();

		rt.rectangleArea();
		cr.circleArea();
		sq.squareArea();
		tr.triangleArea();
	}
}