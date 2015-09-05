import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val N = sc.nextInt()
    printf("%02d:%02d:%02d\n", N / 60 / 60, N / 60 % 60, N % 60)
  }
}
