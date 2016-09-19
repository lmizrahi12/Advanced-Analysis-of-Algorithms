import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Program {
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		
		ArrayList<Integer> times = new ArrayList<Integer>();
		
		System.out.println("Enter waiting times. Enter -1 to stop:");
			int time = in.nextInt();
			while(time != -1){
				times.add(time);
				time = in.nextInt();
			}
		
		Collections.sort(times);
		
		int sum = 0;
		for(int i = 0;i < times.size();i++){
			sum += ( times.size() - i - 1 ) * times.get(i);
		}
		
		System.out.print("Min waiting time: " + sum);
	}
}

