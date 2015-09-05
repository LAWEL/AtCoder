import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val N, D, X, Y = sc.nextInt()
    def solve(val N:Int, val D:Int, val X:Int, val Y:Int): Double = {
      if(X % D != 0 || Y % D != 0) return 0


    }
    println(sovle(N, D, X, Y))
  }
}
