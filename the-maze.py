from collections import deque

DX = [0, 1, 0, -1]
DY = [1, 0, -1, 0]

class Solution:
  def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
    n, m = len(maze), len(maze[0])
    si, sj = start; ei, ej = destination
    sv, ev = si * m + sj, ei * m + ej

    adj = [[] for _ in range(n * m)]
    for i in range(n):
      for j in range(m):
        if maze[i][j] == 1: continue

        for k in range(4):
          ni, nj = i, j
          di, dj = None, None
          while True:
            ni, nj = ni + DX[k], nj + DY[k]
            if ni < 0 or ni >= n or nj < 0 or nj >= m or maze[ni][nj] == 1:
              di, dj = ni - DX[k], nj - DY[k]
              break

          adj[i * m + j].append(di * m + dj)

    vis = [False for _ in range(n * m)]; q = deque()
    q.append(sv); vis[sv] = True

    while q:
      v = q.popleft()
      for u in adj[v]:
        if vis[u]: continue
        q.append(u); vis[u] = True

    return vis[ev]
