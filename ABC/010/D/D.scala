import java.util.Scanner
import scala.collection.JavaConversions._
import java.util.ArrayList
import scala.math._

case class Edge(var to:Int, var cap:Int, var rev:Int)

object Main {
  val V: Int = 201
  val INF: Int = 100000000
  val G: Array[ArrayList[Edge]] = Array.fill(V)(new ArrayList[Edge])
  val used: Array[Boolean] = Array.fill(V)(false)

  def addEdge(from:Int, to:Int, cap:Int) {
    G(from).add(Edge(to, cap, G(to).size()))
    G(to).add(Edge(from, 0, G(from).size() - 1))
  }

  def dfs(v:Int, t:Int, f:Int): Int = {
    if(v == t) return f
    used(v) = true
    for(e <- G(v)){
      if(!used(e.to) && e.cap > 0){
        val d = dfs(e.to, t, min(f, e.cap))
        if(d > 0){
          e.cap -= d
          G(e.to)(e.rev).cap += d
          return d
        }
      }
    }
    return 0;
  }

  def maxFlow(s:Int, t:Int):Int = {
    var flow = 0
    while(true){
      for(i <- 0 until V){
        used(i) = false
      }
      val f = dfs(s, t, INF)
      if(f == 0) return flow
      flow += f
    }
    return 0
  }

  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val N, G, E = sc.nextInt()
    val ps = Array.fill(G)(sc.nextInt())
    for(i <- 0 until E){
      val a, b = sc.nextInt()
      addEdge(a, b, 1)
      addEdge(b, a, 1)
    }
    for(i <- 0 until N){
      addEdge(i, N + i, 1)
    }
    for(p <- ps){
      addEdge(N + p, 2 * N, INF)
    }
    println(maxFlow(0, 2 * N))
  }
}
 
