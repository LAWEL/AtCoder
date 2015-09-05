import java.util.Scanner

object Main extends App {
  val EPS = 1e-8
  val sc = new Scanner(System.in)
  val tx_a, ty_a, tx_b, ty_b, T, V, n = sc.nextInt()
  var ans = "NO"
  for(i <- 0 until n){
    val x, y = sc.nextInt()
    if((Math.sqrt((tx_a - x) * (tx_a - x) + (ty_a - y) * (ty_a - y)) +
      Math.sqrt((tx_b - x) * (tx_b - x) + (ty_b - y) * (ty_b - y))) / V < T + EPS)
      ans = "YES"
  }
  println(ans)
}
