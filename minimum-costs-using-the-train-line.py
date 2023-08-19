class Solution:
  def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
    n = len(regular)

    dp = [[None, None] for _ in range(n)]
    dp[0][0] = regular[0]
    dp[0][1] = min(regular[0], express[0]) + expressCost

    for i in range(1, n):
      dp[i][0] = min([
        dp[i - 1][0] + regular[i],
        dp[i - 1][1] + regular[i],
        dp[i - 1][1] + express[i]
      ])
      dp[i][1] = min([
        dp[i - 1][0] + min(regular[i], express[i]) + expressCost,
        dp[i - 1][1] + min(express[i], regular[i] + expressCost)
      ])

    ans = []
    for i in range(n): ans.append(min(dp[i]))
    return ans

