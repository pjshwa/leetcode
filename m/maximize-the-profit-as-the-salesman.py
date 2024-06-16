class Solution:
  def maximizeTheProfit(self, n: int, offers: List[List[int]]) -> int:
    offers.sort(key = lambda x: -x[1])
    dp = [0 for _ in range(n)]

    for i in range(n):
      if i > 0: dp[i] = dp[i - 1]
      while offers and offers[-1][1] == i:
        l, r, amt = offers.pop()
        if l == 0: dp[r] = max(dp[r], amt)
        else: dp[r] = max(dp[r], amt + dp[l - 1])

    return dp[n - 1]
