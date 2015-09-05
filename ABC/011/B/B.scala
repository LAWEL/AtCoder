object Main extends App {
  val x :: xs = readLine.toLowerCase.toList
  println(x.toUpper + xs.mkString)
}
