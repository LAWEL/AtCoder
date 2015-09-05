import java.util.Scanner

object Main{
  def main(args: Array[String]) {
    val scan: Scanner = new Scanner(System.in)
    val a: Int = scan.nextInt()
    val b: Int = scan.nextInt()
    println(b / a)
  }
}
