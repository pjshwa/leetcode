class Solution {
  bool isvowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  bool isconsonant(char c) {
    return !isvowel(c);
  }

public:
  bool isValid(string word) {
    int vcnt = 0, ccnt = 0;
    for (char& c : word) {
      if (isalpha(c)) {
        vcnt += isvowel(c);
        ccnt += isconsonant(c);
      }
      else if (!isdigit(c)) return false;
    }
    bool ok = word.size() >= 3 && vcnt > 0 && ccnt > 0;
    return ok;
  }
};
