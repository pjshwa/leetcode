from collections import deque

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
  def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
    by_group = {}
    for i in range(n):
      if group[i] == -1: continue
      if group[i] not in by_group: by_group[group[i]] = []
      by_group[group[i]].append(i)

    # will perform 2 topological sorts
    # 1st for within groups
    # 2nd for between groups

    dsu = DSU(n)
    for g, indices in by_group.items():
      size = len(indices)
      for i in range(1, size): dsu.union(indices[i - 1], indices[i])

    order_within = {}
    adj = [[] for _ in range(n)]
    indegree = [0 for _ in range(n)]

    for i in range(n):
      for v in beforeItems[i]:
        if not dsu.find(v) == dsu.find(i): continue
        adj[v].append(i)
        indegree[i] += 1

    q = deque()
    for i in range(n):
      if group[i] == -1: continue
      if indegree[i] == 0: q.append(i)

    while q:
      v = q.popleft()
      if group[v] not in order_within: order_within[group[v]] = []
      order_within[group[v]].append(v)

      for u in adj[v]:
        indegree[u] -= 1
        if indegree[u] == 0: q.append(u)

    # check if ordering within groups is possible
    for g, indices in by_group.items():
      if not len(indices) == len(order_within.get(g, [])): return []

    adj = [set() for _ in range(n)]
    indegree = [0 for _ in range(n)]
    for i in range(n):
      for v in beforeItems[i]:
        u, v = dsu.find(i), dsu.find(v)
        if u == v or u in adj[v]: continue
        adj[v].add(u)
        indegree[u] += 1

    groups = set()
    for i in range(n): groups.add(dsu.find(i))

    result = []
    q = deque()
    for u in groups:
      if indegree[u] == 0: q.append(u)

    while q:
      v = q.popleft()

      if group[v] == -1: result.append(v)
      else:
        for e in order_within[group[v]]: result.append(e)

      for u in adj[v]:
        indegree[u] -= 1
        if indegree[u] == 0: q.append(u)

    if len(result) == n: return result
    else: return []
