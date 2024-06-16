class Solution {
  int ac[26], bc[26];
  int ccnt = 0;

  void inc(int c) {
    if (ac[c] == bc[c]) ccnt--;
    bc[c]++;
    if (ac[c] == bc[c]) ccnt++;
  }

  void dec(int c) {
    if (ac[c] == bc[c]) ccnt--;
    bc[c]--;
    if (ac[c] == bc[c]) ccnt++;
  }

public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    memset(ac, 0, sizeof(ac));
    memset(bc, 0, sizeof(bc));

    for (char c : s1) ac[c - 'a']++;

    int m = s1.size();
    for (int i = 0; i < m; i++) bc[s2[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
      if (ac[i] == bc[i]) ccnt++;
    }

    if (ccnt == 26) return true;

    int n = s2.size();
    for (int i = m; i < n; i++) {
      dec(s2[i - m] - 'a');
      inc(s2[i] - 'a');
      if (ccnt == 26) return true;
    }

    return false;
  }
};
