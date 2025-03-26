class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int ai = 0, wi = 0, aZ = abbr.size(), wZ = word.size();
    while (ai < aZ) {
      if (wi >= wZ) return false;
      if (isdigit(abbr[ai])) {
        if (abbr[ai] == '0') return false;
        int num = 0;
        while (ai < aZ && isdigit(abbr[ai])) {
          num = num * 10 + abbr[ai] - '0';
          ++ai;
        }
        if (num > wZ - wi) return false;
        wi += num;
      } else {
        if (word[wi] != abbr[ai]) return false;
        ++wi, ++ai;
      }
    }
    return wi == wZ;
  }
};
  