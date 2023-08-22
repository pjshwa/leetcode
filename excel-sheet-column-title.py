class Solution:
  def convertToTitle(self, columnNumber: int) -> str:
    columnNumber -= 1
    pw, dg = 26, 1
    while columnNumber >= pw:
      columnNumber -= pw
      dg += 1
      pw *= 26

    ret = []
    while columnNumber:
      ret.append(chr(columnNumber % 26 + 65))
      columnNumber //= 26

    while len(ret) < dg: ret.append('A')
    return ''.join(reversed(ret))
