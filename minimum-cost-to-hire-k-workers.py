import heapq

class Solution:
  def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
    with_rates = []; n = len(quality)
    for i in range(n): with_rates.append((wage[i] / quality[i], quality[i]))
    with_rates.sort()

    heap = []

    # min quality sum
    cur_acc = 0
    for i in range(k):
      _, qual = with_rates[i]
      cur_acc += qual
      heapq.heappush(heap, -qual)

    ans = with_rates[k - 1][0] * cur_acc
    for i in range(k, n):
      new_rate, qual = with_rates[i]

      # negative value is popped
      cur_acc += heapq.heappop(heap)

      cur_acc += qual
      heapq.heappush(heap, -qual)

      ans = min(ans, new_rate * cur_acc)

    return ans
