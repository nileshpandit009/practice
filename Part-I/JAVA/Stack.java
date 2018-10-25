//implement stack using array
import java.util.Scanner;

class Stack
{
	static int cho = 1;
	static boolean flag;
	static int stack[] = new int[5];
	static int top = -1;
	public static void main(String args[])
	{
		int num, ch = 0;
		Stack st = new Stack();

		Scanner sc = new Scanner(System.in);

		while(true) {
		flag = false;
		System.out.println("Enter your choice\n1. Push\n2. Pop\n3. Display\n4. Exit");
		ch = sc.nextInt();

		switch (ch){
			case 1:
				while(cho != 0) {
					if (flag)
						break;
					System.out.println("\nEnter element to push into stack");
					num = sc.nextInt();
					flag = st.push(num);
					System.out.println("\nContinue? (0/1)");
					cho = sc.nextInt();
				}
			break;

			case 2:
				while(cho != 0) {
					flag = st.pop();
					if (flag)
						break;
					System.out.println("\nPOP another element? (0/1)");
					cho = sc.nextInt();
				}
			break;

			case 3:
				if (top < 0)
					System.out.println("\n\nStack Empty\n");
				else {
					System.out.println("\n\nElements of Stack are :");
					for (int i = top; i >= 0; i--)
						System.out.println(stack[i]);
				}
			break;

			case 4:
				System.exit(0);
		}
	}
	}

	boolean push(int tmp) {
		if (top < 4)
			stack[++top] = tmp;
		else {
			System.out.println("\n\nStack Overflow\n");
			return true;
		}
		return false;
	}

	boolean pop() {
		if (top < 0) {
			System.out.println("\n\nStack Underflow\n");
			return true;
		}
		else {
			System.out.println("\n\nPOPed element is " + stack[top] + "\n");
			stack[top--] = 0;
		}
		return false;
	}
}