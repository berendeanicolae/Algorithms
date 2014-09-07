import java.util.Scanner;
import java.util.Arrays;


public class Main {

	
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		String n = sc.next();
		int mod, sum=0;
		
		n = n.substring(n.length()>1 ? n.length()-2 : n.length()-1, n.length());
		mod = Integer.valueOf(n);
		switch (mod%4){
			case 0:
				sum = 1 + 6 + 1 + 6;
				break;
			case 1:
				sum = 1 + 2 + 3 + 4;
				break;
			case 2:
				sum = 1 + 4 + 9 + 6;
				break;
			case 3:
				sum = 1 + 8 + 7 + 4;
				break;
		}
		System.out.printf("%d",sum%5);
		sc.close();
	}

}
