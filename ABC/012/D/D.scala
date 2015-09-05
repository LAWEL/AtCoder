import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val N, M = sc.nextInt()
    val G = Array.fill(N, N)(1 << 28)
    for(i <- 0 until M) {
      val a, b, t = sc.nextInt()
      G(a-1)(b-1) = t
      G(b-1)(a-1) = t
    }
    for(i <- 0 until N) G(i)(i) = 0
    for(k <- 0 until N; i <- 0 until N; j <- 0 until N) G(i)(j) = Math.min(G(i)(j), G(i)(k) + G(k)(j))
    println(List.tabulate(N)(i => G(i).max).min)
  }
}
