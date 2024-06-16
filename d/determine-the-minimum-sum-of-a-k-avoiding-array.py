class Solution:
  def minimumSum(self, n: int, k: int) -> int:
    candidates = []
    for i in range(1, n + 1):
      if 2 * i > k: break
      candidates.append(i)

    for i in range(k, k + n):
      if len(candidates) == n: break
      candidates.append(i)

    return sum(candidates)
