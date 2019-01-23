class Cmd
{
	public static void main(String args[]) {
	int i;
	double sum = 0;
	for (i=0;i<args.length;i++)
		sum = sum + (Double.parseDouble(args[i]));
	System.out.println("Sum is : " + sum);
	}
}