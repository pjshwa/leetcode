class Solution:
  def isAcronym(self, words: List[str], s: str) -> bool:
    acr = []
    for word in words: acr.append(word[0])
    return ''.join(acr) == s
