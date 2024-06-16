class Codec:
  def encode(self, strs: List[str]) -> str:
    """Encodes a list of strings to a single string.
    """

    result = f"{len(strs)} "
    for s in strs: result += f"{len(s)} "
    result += ''.join(strs)
    return result
      

  def decode(self, s: str) -> List[str]:
    """Decodes a single string to a list of strings.
    """

    tokens = s.split(' ')
    list_size = int(tokens[0])
    token_sizes = map(int, tokens[1:list_size + 1])

    actual_str = ' '.join(tokens[list_size + 1:len(tokens)])
    result = []; left = 0
    for sz in token_sizes:
      result.append(actual_str[left:left + sz])
      left += sz

    return result
        


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
