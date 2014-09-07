import java.util.Scanner;

public class Main {

	
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt(), sol=0;
		int first=sc.nextInt(), last=first;
		
		for (int i=1; i<n; ++i){
			int current = sc.nextInt();
			if (current<last){
				if (sol!=0){
					sc.close();
					System.out.printf("-1");
					return;
				}
				sol = n-i;
			}
			last = current;
		}
		sc.close();
		if (sol!=0 && first<last)
			System.out.printf("-1");
		else
			System.out.printf("%d", sol);
	}

}
