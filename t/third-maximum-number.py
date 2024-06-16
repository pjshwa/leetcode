class Solution:
  def thirdMax(self, nums: List[int]) -> int:
    nums = list(set(nums))
    size = len(nums)
    if size < 3: return max(nums)
    else: return sorted(nums)[-3]
