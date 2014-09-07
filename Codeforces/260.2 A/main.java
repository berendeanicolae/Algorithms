import java.util.Scanner;
import java.util.Arrays;


public class Main {

	
	public static void main(String[] args) {

		class PC implements Comparable<PC>{
			public int a, b;
			
			public int compareTo(PC other){
				return Integer.compare(this.a, other.a);
			}
		};
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		PC[] pcs = new PC[n];
		
		for (int i=0; i<n; ++i){
			pcs[i] = new PC();
			pcs[i].a=sc.nextInt();
			pcs[i].b=sc.nextInt();
		}
		Arrays.sort(pcs);
		for (int i=1; i<n; ++i){
			if (pcs[i].b<pcs[i-1].b){
				System.out.printf("Happy Alex");
				sc.close();
				return;
			}
		}
		
		System.out.printf("Poor Alex");
		sc.close();
	}

}
