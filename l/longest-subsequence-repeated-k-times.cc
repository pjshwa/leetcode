class Solution {
  bool check(string &s, string &t, int k) {
    int j = 0, n = s.size(), m = t.size(), cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[j]) {
        ++j;
        if (j == m) j = 0, ++cnt;
      }
    }

    return cnt >= k;
  }

public:
  string longestSubsequenceRepeatedK(string s, int k) {
    map<char, int> tal;
    for (auto c : s) tal[c]++;

    vector<char> P;
    for (auto [c, v] : tal) {
      for (int i = 0; i < v / k; i++) P.push_back(c);
    }
    if (P.empty()) return "";

    int Z = P.size();
    int p[Z]; iota(p, p + Z, 0);

    for (int i = Z; i >= 1; --i) {
      string ans;

      do {
        string t;
        for (int j = 0; j < i; ++j) t.push_back(P[p[j]]);

        if (check(s, t, k)) {
          if (ans.empty() || ans < t) ans = t;
        }

      } while (next_permutation(p, p + Z));

      if (!ans.empty()) return ans;
    }

    return "";
  }
};
