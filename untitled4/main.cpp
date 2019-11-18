object Solution {
    import scala.collection.mutable

    def gcd(bunny1: Long, bunny2: Long): Long = {
      if(bunny2 == 0) bunny1 else gcd(bunny2, bunny1 % bunny2)
    }

    def main(args: Array[String]) {
      val n = readLine()
      val bunnies = readLine().split(' ').map(_.toLong)
      val tmp = mutable.ArrayBuffer[Long](1)
      for (i <- 0 until bunnies.length) {
        tmp(0) = tmp(0) / gcd(arr(0), bunnies(i)) * bunnies(i)
      }
      println(tmp(0))
    }
}