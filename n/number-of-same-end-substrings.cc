class Solution {
public:
  vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
    int N = s.size();
    vector<vector<int>> P(26, vector<int>(N + 1));
    for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < 26; ++j) P[j][i] = P[j][i - 1] + (s[i - 1] - 'a' == j);
    }

    vector<int> res;
    for (auto& qv : queries) {
      int l = qv[0] + 1, r = qv[1] + 1;
      int ans = r - l + 1;
      for (int j = 0; j < 26; ++j) {
        int cnt = P[j][r] - P[j][l - 1];
        ans += cnt * (cnt - 1) / 2;
      }
      res.push_back(ans);
    }
    return res;
  }
};
