class Solution:
  def longestEqualSubarray(self, nums: List[int], k: int) -> int:
    by_value = {}
    for i, e in enumerate(nums):
      if not e in by_value: by_value[e] = []
      by_value[e].append(i)

    ans = 0
    for _, nums_by_v in by_value.items():
      z, l = len(nums_by_v), 0
      for r in range(z):
        while True:
          need = nums_by_v[r] - nums_by_v[l] - 1 - (r - l - 1)
          if need <= k: break
          l += 1
        
        ans = max(ans, r - l + 1)

    return ans
