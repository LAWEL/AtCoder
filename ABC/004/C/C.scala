import java.util.Scanner

object Main extends App {
  val sc = new Scanner(System.in)
  var n = sc.nextInt()
  val arr = new Array[Int](6)
  for(i <- 0 to 5) {
    arr(i) = i + 1
  }
  n %= 30
  for(i <- 0 to n - 1) {
    val a = i % 5
    val b = a + 1
    val tmp = arr(b)
    arr(b) = arr(a)
    arr(a) = tmp
  }
  arr.foreach(print)
  println()
}
