/*
 * Name : Nilesh V Pandit.
 * Roll no. : TE A-25.
 */

import java.util.*;

class BankAccount
{
	static int max = 5;

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		BankAccount ba[] = new BankAccount[max];
		Map<Integer, String> map = new HashMap<Integer, String>();

		int ch = 0, cho = 0, acc_index = -1;
		long balance;
		String name, acc_no;

		System.out.println("\nEnter your choice");
		System.out.println("1. Create Account\n2. Delete Account\n3. View Account\n");
		ch = sc.nextInt();
		switch(ch) {
			case 1:
				map.put(++acc_index, ("JB" + acc_index));
				System.out.println(map.values());
/*				System.out.println("Enter you Name");
				ba[acc_index].name = sc.next();
				ba[acc_index].acc_no = map.get(acc_index);
				ba[acc_index].balance = 0;
				System.out.println("\n\nAccount has been created successfully\n");
				System.out.println("\nAccount Details : ");
				System.out.println("Name : " + ba[acc_index].name + "\nAccount Number : " + ba[acc_index].acc_no);
				System.out.println("Balance : " + ba[acc_index].balance);
			break;
/*			case 3:
				System.out.println("Enter your account number");
				acc_no = sc.nextInt();
				System.out.println("\nEnter your choice");
				System.out.println("1. Withdraw\n2. Deposite\n3. View Account info\n");
				cho = sc.nextInt();

				switch(cho) {
					case 1:
					break;
				}
*/
			break;
		}
	}
}