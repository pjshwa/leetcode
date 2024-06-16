class Solution {
public:
  string smallestBeautifulString(string s, int k) {
    int n = s.size();

    vector<int> E(n);
    for (int i = 0; i < n; ++i) E[i] = s[i] - 'a';

    for (int i = n - 1; i >= 0; --i) {
      for (int c = E[i] + 1; c < k; ++c) {
        bool able = true;
        if (i > 0 && c == E[i - 1]) able = false;
        if (i > 1 && c == E[i - 2]) able = false;
        if (!able) continue;

        E[i] = c;
        for (int j = i + 1; j < n; ++j) {
          for (int c = 0; c < k; ++c) {
            bool able = true;
            if (j > 0 && c == E[j - 1]) able = false;
            if (j > 1 && c == E[j - 2]) able = false;
            if (able) {
              E[j] = c;
              break;
            }
          }
        }

        string ans = "";
        for (int j = 0; j < n; ++j) ans += E[j] + 'a';
        return ans;
      }
    }
    return "";
  }
};
