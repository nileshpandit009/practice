import java.util.Scanner;
import java.io.*;

class StudentMarks {
	int m1, m2, m3;
	String name;
	public void getMarks() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter name :");
		name = sc.next();
		System.out.println("Enter your marks : ");
		System.out.println("Enter marks for subject 1 : ");
		m1 = sc.nextInt();
		System.out.println("Enter marks for subject 2 : ");
		m2 = sc.nextInt();
		System.out.println("Enter marks for subject 3 : ");
		m3 = sc.nextInt();
		sc.close();
	}
	
	public void showMarks() {
		System.out.println("Name : " + name);
		System.out.println("Marks are :");
		System.out.println("\nSubject 1 : " + m1 + "\nSubject 2 : " + m2 + "\nSubject 3 : " + m3);
	}
}

class TotalMarks extends StudentMarks {
	int total = 0;
	
	public void calcTotal(){
		getMarks();
		total = m1 + m2 + m3;
	}
	public void showTotal(){
		showMarks();
		System.out.println("Total marks : " + total);
	}
}

public class Multilevel extends TotalMarks {

	/*
	 * Name : Nilesh Pandit
	 * Roll no. : TE A-25
	 */
	public static void main(String[] args) {
		int i = 0, max = 5, count = 0;
		boolean end = false;
		while (end){
			TotalMarks[] tmm = new TotalMarks[max];
			try {
				for(i=0;i<tmm.length;i++) {
					System.out.println("Enter new record ? (true/false)");
					Scanner sc = new Scanner(System.in);
					end = sc.nextBoolean();
					if(end == false){
						++count;
						tmm[i].calcTotal();
						tmm[i].showTotal();
					}
					else
						break;
				}
			}
			catch(ArrayIndexOutOfBoundsException e){
				max = tmm.length + 5;
				TotalMarks[] tmp = new TotalMarks[max];
				System.arraycopy(tmm, 0, tmp, 0, tmm.length);
				for(i=0;i<tmm.length;i++)
					tmm[i] = null;
				System.gc();
			}
		
		}
	}

}