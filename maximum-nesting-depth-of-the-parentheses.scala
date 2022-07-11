object Solution {
  def maxDepth(s: String): Int = {
    return s.filter("()" contains _).map(c => if (c == '(') 1 else -1).scan(0)(_ + _).max
  }
}
