import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val scan: Scanner = new Scanner(System.in)
    val N: Int = scan.nextInt()
    val Arr = for(i <- 1 to N) yield scan.nextInt()
    println(Arr.min)
  }
}
