import java.util.Scanner;

object Main extends App {
  val sc = new Scanner(System.in)
  val n = sc.nextInt()
  println(Array.fill(n)(sc.nextInt()).map(a =>
    a - ((1 to a).reverse.find(x => x % 2 != 0 && x % 3 != 2).get)
  ).sum)
}
