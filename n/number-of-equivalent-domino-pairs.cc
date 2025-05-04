class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans = 0; vector<int> C(100, 0);
    for (auto& d : dominoes) {
      int a = min(d[0], d[1]), b = max(d[0], d[1]);
      ++C[a * 10 + b];
    }
    for (int e : C) ans += e * (e - 1) / 2;
    return ans;
  }
};
