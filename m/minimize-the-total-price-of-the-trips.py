from typing import List
from collections import deque

class Solution:
  def rec(self, v: int, p: int, o: int, adj: List[List[int]], price: List[int], dp: List[List[int]]) -> int:
    if dp[v][o] != -1: return dp[v][o]

    # select v
    ret_se = price[v] // 2
    for u in adj[v]:
      if u == p: continue
      ret_se += self.rec(u, v, 1, adj, price, dp)

    # no select v
    ret_ns = price[v]
    for u in adj[v]:
      if u == p: continue
      ret_ns += self.rec(u, v, 0, adj, price, dp)


    dp[v][o] = ret_ns
    if o == 0: dp[v][o] = min(dp[v][o], ret_se)
    return dp[v][o]


  def minimumTotalPrice(self, n: int, edges: List[List[int]], price: List[int], trips: List[List[int]]) -> int:
    adj = [[] for _ in range(n)]
    for (u, v) in edges:
      adj[u].append(v)
      adj[v].append(u)

    # give weights to vertices according to trips
    weights = [0 for _ in range(n)]
    for (s, e) in trips:
      prev = [-1 for _ in range(n)]
      vis = [False for _ in range(n)]

      q = deque()
      q.append(s); vis[s] = True
      while q:
        v = q.popleft()
        for u in adj[v]:
          if vis[u]: continue
          q.append(u)
          prev[u] = v
          vis[u] = True

      while e != -1:
        weights[e] += 1
        e = prev[e]

    for i in range(n): price[i] *= weights[i]

    # dp[v][o] = current vertex, parent selected
    dp = [[-1, -1] for _ in range(n)]
    return self.rec(0, -1, 0, adj, price, dp)
    


if __name__ == '__main__':
  solver = Solution()
  cases = [
    (4, [[0,1],[1,2],[1,3]], [2,2,10,6], [[0,3],[2,1],[2,3]]),
    (2, [[0,1]], [2,2], [[0,0]])
  ]
  answers = [
    23,
    1
  ]
  for case, answer in zip(cases, answers):
    output = solver.minimumTotalPrice(*case)
    if output == answer: continue

    print(f'case: {case}, output: {output}, answer: {answer}')
    assert False

  print('OK')

