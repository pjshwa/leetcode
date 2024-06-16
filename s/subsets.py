class Solution:
  def subsets(self, nums: List[int]) -> List[List[int]]:
    ans = []
    for e in nums:
      ans += [i + [e] for i in ans]
      ans.append([e])
    ans.append([])
    return ans
