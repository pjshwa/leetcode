class Solution {
  string s1, s2;
  int d[31][31][31];

  bool is_anagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
  }

  bool r(int li, int ri, int len) {
    if (len == 1) return s1[li] == s2[ri];
    if (d[li][ri][len] != -1) return d[li][ri][len] == 1;

    bool ret = false;
    for (int l = 1; l <= len - 1; l++) {
      if (is_anagram(s1.substr(li, l), s2.substr(ri, l))) {
        ret |= r(li, ri, l) && r(li + l, ri + l, len - l);
      }
      if (is_anagram(s1.substr(li, l), s2.substr(ri + len - l, l))) {
        ret |= r(li, ri + len - l, l) && r(li + l, ri, len - l);
      }
    }
    return d[li][ri][len] = ret;
  }

public:
  bool isScramble(string s1, string s2) {
    this->s1 = s1; this->s2 = s2;
    int n = s1.size();
    memset(d, -1, sizeof(d));
    return r(0, 0, n);
  }
};
