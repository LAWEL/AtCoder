import java.util.Scanner

object Main extends App {
  val sc: Scanner = new Scanner(System.in)
  val arr = new Array[String](4)
  for(i <- 0 to 3) { 
    arr(i) = sc.nextLine().reverse
  }
  for(i <- 0 to 3) {
    println(arr(3 - i))
  }
}
