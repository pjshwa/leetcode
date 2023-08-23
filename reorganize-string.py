from collections import deque

class Solution:
  def reorganizeString(self, s: str) -> str:
    cnt_map = {}
    for c in s:
      if c not in cnt_map: cnt_map[c] = 0
      cnt_map[c] += 1

    n = len(s)
    cnt_values = sorted([[v, k] for k, v in cnt_map.items()])
    if cnt_values[-1][0] > (n + 1) // 2: return ""

    char_dq = deque()
    for v, k in cnt_values:
      for _ in range(v): char_dq.append(k)

    result = [None for _ in range(n)]
    for i in range(0, n, 2): result[i] = char_dq.pop()
    for i in range(1, n, 2): result[i] = char_dq.pop()
    
    return ''.join(result)
