import java.util.Scanner;

object Main {
  def main(args: Array[String]){
    val sc = new Scanner(System.in);
    val a = sc.nextInt()
    val b = sc.nextInt()
    println(b - a + 1)
  }
}
