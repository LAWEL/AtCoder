import java.util.Scanner;


public class Main{
    public static void main(String[] args){

	Scanner scan = new Scanner(System.in);
	int N = scan.nextInt();

	Map<Integer, boolean> coin = new LinkedHashMap<Integer, boolean>();

	for(int i = 0; i < N; ++i){
	    coin.put(scan.nextInt(), true);
	}

	List<Integer> coinNumber = new ArrayList<Integer>();

	coinNumber = ()coin.entrySet();
	for(int i = 0; i < N-1; ++i){

	}
    }
}
