import java.util.Scanner;

public class Main{
    public static void main(String[] args){

	Scanner scan = new Scanner(System.in);

	int begin = scan.nextInt();
	int end = scan.nextInt();

	System.out.println(end - begin + 1);
    }
}
