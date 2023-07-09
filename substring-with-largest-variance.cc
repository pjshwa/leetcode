class Solution {
public:
  int largestVariance(string s) {
    int N = s.size(), ans = 0;

    map<int, int> T;
    for (char c : s) T[c - 'a']++;

    for (int low = 0; low < 26; low++) for (int high = 0; high < 26; high++) {
      if (low == high) continue;

      int high_cnt = 0, low_cnt = 0, rest_cnt = T[low];
      for (int i = 0; i < N; i++) {
        int c = s[i] - 'a';

        if (c == low) low_cnt++, rest_cnt--;
        if (c == high) high_cnt++;

        if (low_cnt > 0) ans = max(ans, high_cnt - low_cnt);
        if (high_cnt < low_cnt && rest_cnt > 0) high_cnt = low_cnt = 0;
      }
    }

    return ans;
  }
};
