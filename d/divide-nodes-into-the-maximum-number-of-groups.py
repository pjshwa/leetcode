from collections import deque
from collections import defaultdict

class DSU:
  def __init__(self, n):
    self.parent = [i for i in range(n)]
    self.ssz = [1 for _ in range(n)]

  def find(self, x):
    if x != self.parent[x]: self.parent[x] = self.find(self.parent[x])
    return self.parent[x]

  def union(self, x, y):
    x, y = self.find(x), self.find(y)
    if x == y: return
    self.parent[y] = x
    self.ssz[x] += self.ssz[y]


class Solution:
  def isBipartite(self, n: int, adj: List[List[int]]) -> bool:
    dq = deque(); vis = [0 for _ in range(n)]
    dq.append((0, 1)); vis[0] = 1

    while dq:
      vtx, col = dq.popleft()
      for u in adj[vtx]:
        if vis[u]:
          if vis[u] == col: return False
        else:
          dq.append((u, 3 - col))
          vis[u] = 3 - col

    return True

  def maxDistanceFrom(self, s: int, n: int, adj: List[List[int]]) -> int:
    dq = deque(); vis = [False for _ in range(n)]
    dq.append((s, 1)); vis[s] = True

    mdis = 1
    while dq:
      vtx, dis = dq.popleft()
      mdis = max(mdis, dis)

      for u in adj[vtx]:
        if not vis[u]:
          dq.append((u, dis + 1))
          vis[u] = True

    return mdis

  def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
    adj = [[] for _ in range(n)]
    con = DSU(n)

    for u, v in edges:
      u -= 1; v -= 1
      adj[u].append(v); adj[v].append(u)
      con.union(u, v)

    # grouping is not possible if graph is not bipartite
    if not self.isBipartite(n, adj): return -1

    # otherwise, max grouping = max distance from one node to another + 1
    dists_by_group = {}
    for i in range(n):
      group = con.find(i)
      dists_by_group[group] = max(
        dists_by_group.get(group, 0),
        self.maxDistanceFrom(i, n, adj)
      )

    return sum(dists_by_group.values())

