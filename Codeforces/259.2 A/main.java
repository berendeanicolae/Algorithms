import java.util.Scanner;
import java.util.Arrays;


public class Main {

	
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		
		for (int i=1; i<=n; ++i){
			int c=i<=n/2 ? (2*i-1) : (2*(n-i)+1);
			
			for (int j=1; j<=(n-c)/2; ++j){
				System.out.print("*");
			}
			for (int j=1; j<=c; ++j){
				System.out.print("D");
			}
			for (int j=1; j<=(n-c)/2; ++j){
				System.out.print("*");
			}
			System.out.println("");
		}
	}

}
