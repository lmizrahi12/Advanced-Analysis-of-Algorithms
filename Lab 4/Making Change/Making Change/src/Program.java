import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Program {
	public static void main(String[] args) {
		int denominations[];
		int amount;
		int n;
		int change[];
		
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter number of denominations: ");
			n = in.nextInt();
		
		denominations = new int[n];
		change = new int[n];
		
		System.out.println("Enter denominations from smallest to largest");
			for (int i = 0; i < n; i++) {
				denominations[i] = in.nextInt();
			}
		
		System.out.println("Enter amount to give change for: ");
			amount = in.nextInt();
		
		int tmpAmount = amount;
		System.out.println("temp amount: " + tmpAmount);
		for(int i = denominations.length - 1; i > -1;i--){
			change[i] = tmpAmount/denominations[i];
			tmpAmount = tmpAmount - ( change[i] * denominations[i] );
			System.out.println("temp amount: " + tmpAmount);
		}
		
		System.out.println(amount + " = ");
		for(int i = denominations.length - 1; i > -1;i--){
			System.out.println(change[i] + " " + denominations[i] + "'s");
		}
		
	}
	
}

/*
1
2
5
10
20
50
100

83
*/

