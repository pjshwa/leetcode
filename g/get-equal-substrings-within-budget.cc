class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int ans = 0, N = s.size();

    int r = 0, cost = 0;
    for (int l = 0; l < N; ++l) {
      while (r < N && cost + abs(s[r] - t[r]) <= maxCost) {
        cost += abs(s[r] - t[r]);
        ++r;
      }
      ans = max(ans, r - l);

      if (r == l) ++r;
      else cost -= abs(s[l] - t[l]);
    }
    return ans;
  }
};
