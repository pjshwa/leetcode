class Solution {
  int st[26], pt[26];
  int ccnt;
public:
  vector<int> findAnagrams(string s, string p) {
    if (p.size() > s.size()) return {};

    memset(st, 0, sizeof(st));
    memset(pt, 0, sizeof(pt));
    ccnt = 0;

    vector<int> ans;
    int n = s.size(), m = p.size();
    for (int i = 0; i < m; i++) st[s[i] - 'a']++, pt[p[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
      if (st[i] == pt[i]) ccnt++;
    }
    if (ccnt == 26) ans.push_back(0);
    for (int i = m; i < n; i++) {
      int c = s[i] - 'a';
      if (st[c] == pt[c]) ccnt--;
      if (st[c] == pt[c] - 1) ccnt++;
      st[c]++;

      int d = s[i - m] - 'a';
      if (st[d] == pt[d] + 1) ccnt++;
      if (st[d] == pt[d]) ccnt--;
      st[d]--;

      if (ccnt == 26) ans.push_back(i - m + 1);
    }

    return ans;
  }
};
