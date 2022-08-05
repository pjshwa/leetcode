using ll = long long;
const ll MOD = 1e10;

class Solution {
  ll d[1001];
public:
  int combinationSum4(vector<int>& nums, int target) {
    memset(d, 0, sizeof(d));

    d[0] = 1;
    for (int v = 1; v <= target; v++) for (int num : nums) {
      if (v >= num) d[v] = (d[v] + d[v - num]) % MOD;
    }

    return d[target];
  }
};
