class Solution:
  def repeatedSubstringPattern(self, s: str) -> bool:
    n = len(s)
    for f in range(1, n):
      if not n % f == 0: continue

      chunks = set()
      for i in range(0, n, f): chunks.add(s[i:i + f])
      if len(chunks) == 1: return True

    return False
