const int MOD = 1e9 + 7;
using ll = long long;

class Solution {
public:
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    for (auto& q : queries) {
      ll l = q[0], r = q[1], k = q[2], x = q[3];
      for (int i = l; i <= r; i += k) nums[i] = (nums[i] * x) % MOD;
    }
    int ans = 0;
    for (int x : nums) ans ^= x;
    return ans;
  }
};
