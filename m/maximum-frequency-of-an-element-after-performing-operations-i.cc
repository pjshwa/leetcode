const int MAXN = 1e5;

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int N = nums.size(); vector<int> tal(MAXN + k + 1, 0);
    for (int& e : nums) ++tal[e];

    int ans = 0, cur = 0;
    for (int i = 1; i <= k; ++i) cur += tal[i];
    for (int t = 1; t <= MAXN; ++t) {
      cur += tal[t + k];
      if (t - k - 1 >= 0) cur -= tal[t - k - 1];
      int need = cur - tal[t];
      ans = max(ans, tal[t] + min(need, numOperations));
    }
    return ans;
  }
};
