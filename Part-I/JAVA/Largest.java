class Largest
{
	public static void main(String args[]) {
		int i , j , g1 , g2 , tmp;
		int arr[] = new int[args.length];
		i=j=g1=g2=tmp=0;
		for (i=0;i<args.length;i++)
			arr[i] = (Integer.parseInt(args[i]));
		g1 = g2 = arr[0];
		for (i=0;i<args.length;i++) {
			if (arr[i] > g1) {
				g2 = g1;
				g1 = arr[i];
			}
			else if (arr[i] > g2)
				g2 = arr[i];
		}

		System.out.println("\n1st Largest : " + g1 + "\n2nd Largest : " + g2);
	}
}