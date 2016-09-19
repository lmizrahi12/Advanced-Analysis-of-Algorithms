import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;

public class Program {
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		ArrayList<Activity> Activities = new ArrayList<Activity>();
		
		System.out.println("Enter activities with their start and finish times  '<start_time> <end_time>'");
		System.out.println("Enter 'END' to stop:");
		
			String input = in.nextLine();
			while(!input.equals("END")){
				String[] str = input.split(" ");
				Activity tmp = new Activity(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
				Activities.add(tmp);
				input = in.nextLine();
			}
		
		Collections.sort(Activities);
		
		for (int i = 0; i < Activities.size();i++) {
			Activity activity = (Activity)Activities.get(i);
			System.out.println("A" + (i+1) + ": " + activity.start + " , " + activity.end);
		}
		
		Activity activity = Activities.get(0);
		int max = 1;
		for (int i = 1; i < Activities.size();i++) {
			Activity tmpActivity = (Activity)Activities.get(i);
			if(tmpActivity.start >= activity.end){
				max++;
				activity = tmpActivity;
			}
		}
		System.out.println(max);
		
	}
}

/*
0 5
3 7
5 9
4 10
END

0 5
3 7
5 9
6 9
4 9
4 10
END
*/