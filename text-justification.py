class Solution:
  def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
    ans = []
    words.reverse()

    cur, clen = [], 0
    while words:
      wlen = len(words[-1])

      if not cur or clen + wlen + len(cur) <= maxWidth:
        cur.append(words.pop())
        clen += wlen
      else:
        z = len(cur)

        # only one word
        if z == 1:
          wlen = len(cur[-1])
          ans.append(cur[-1] + ' ' * (maxWidth - wlen))

        # assign gaps accordingly
        else:
          gap = (maxWidth - clen) // (z - 1)
          tlen = clen + gap * (z - 1)
          gaps = [gap for _ in range(z - 1)]

          res = []
          for i in range(z - 1):
            if tlen < maxWidth:
              gaps[i] += 1
              tlen += 1
            res.append(cur[i] + ' ' * gaps[i])

          res.append(cur[-1])
          ans.append(''.join(res))

        cur.clear()
        clen = 0

    # last line
    lword = ' '.join(cur)
    lword = lword + ' ' * (maxWidth - len(lword))
    ans.append(lword)

    return ans
