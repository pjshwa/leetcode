class Solution:
  def titleToNumber(self, columnTitle: str) -> int:
    sz = len(columnTitle)
    ans = 0
    for i in range(sz):
      ans += (26 ** (sz - i - 1))
      ans += (ord(columnTitle[i]) - 65) * (26 ** (sz - i - 1))
    return ans
