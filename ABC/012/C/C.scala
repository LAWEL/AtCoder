import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val N = sc.nextInt()
    for(i <- 1 to 9; j <- 1 to 9 if i * j == 45 * 45 - N) println(i + " x " + j)
  }
}
