import java.util.Scanner;

object Main extends App {
  val sc = new Scanner(System.in)
  var N = sc.nextInt()
  val NG = List.fill(3)(sc.nextInt())
  def calc(N:Int, NG:List[Int], c:Int=100): Boolean= {
    if(N <= 0) return true
    if(c == 0) return false
    val x = List.tabulate(3)(i => N - (i+1)).reverse.find(!NG.contains(_))
    if(x == None) return false
    else calc(x.get, NG, c-1)
  }
  println(if(!NG.contains(N) && calc(N, NG)) "YES" else "NO")
}
