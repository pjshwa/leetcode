class Solution {
public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    for (auto V : accounts) ans = max(ans, accumulate(V.begin(), V.end(), 0));
    return ans;
  }
};
