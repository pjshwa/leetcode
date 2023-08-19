from typing import Optional, List, Union

class DSU:
  def __init__(self, n: int):
    self.parent: List[int] = [i for i in range(n)]
    self.ssz: List[int] = [1 for _ in range(n)]

  def find(self, x: int) -> int:
    if x != self.parent[x]: self.parent[x] = self.find(self.parent[x])
    return self.parent[x]

  def union(self, x: int, y: int):
    x, y = self.find(x), self.find(y)
    if x == y: return

    self.parent[y] = x
    self.ssz[x] += self.ssz[y]

    
class Solution:
  def getMSTWeight(self, n: int, edges: List[List[int]], bannedEdge: Optional[int], reservedEdge: Optional[int]) -> Union[int, float]:
    dsu = DSU(n)
    retValue = 0

    for (u, v, w, i) in edges:
      if not i == reservedEdge: continue
      dsu.union(u, v)
      retValue += w

    for (u, v, w, i) in edges:
      if i == bannedEdge: continue
      if dsu.find(u) != dsu.find(v):
        dsu.union(u, v)
        retValue += w

    return dsu.ssz[dsu.find(0)] == n and retValue or float('inf')

  def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
    criticalEdges, pseudoCriticalEdges = [], []
    edges = sorted([(edge[0], edge[1], edge[2], i) for i, edge in enumerate(edges)], key=lambda x: x[2])

    mstWeight = self.getMSTWeight(n, edges, None, None)

    for (u, v, w, i) in edges:
      if self.getMSTWeight(n, edges, i, None) > mstWeight:
        criticalEdges.append(i)
      elif self.getMSTWeight(n, edges, None, i) == mstWeight:
        pseudoCriticalEdges.append(i)

    return [criticalEdges, pseudoCriticalEdges]


if __name__ == '__main__':
  solver = Solution()
  cases = [
    (4, [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]),
    (5, [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]),
    (4, [[0,1,1],[0,3,1],[0,2,1],[1,2,1],[1,3,1],[2,3,1]])
  ]
  answers = [
    [[], [0, 1, 2, 3]],
    [[0, 1], [2, 3, 4, 5]],
    [[], [0, 1, 2, 3, 4, 5]]
  ]
  for case, answer in zip(cases, answers):
    output = solver.findCriticalAndPseudoCriticalEdges(*case)
    if output == answer: continue

    print(f'case: {case}, output: {output}, answer: {answer}')
    assert False

  print('OK')

