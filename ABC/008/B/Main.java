import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Main{
    public static void main(String[] args){

	Scanner scan = new Scanner(System.in);
	int max = 0;
	int N = scan.nextInt();
	String maxName = "";

	Map<String, Integer> person = new HashMap<String, Integer>();

	for(int i = 0; i < N; ++i){
	    String com = scan.next();

	    if(person.containsKey(com)){
		person.put(com, person.get(com)+1);
	    }
	    else{
		person.put(com, 1);
	    }
	    if(max < person.get(com)){
		max = person.get(com);
		maxName = com;
	    }
	}
	System.out.println(maxName);
    }
}
