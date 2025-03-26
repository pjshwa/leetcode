using ll = long long;

class Solution {
public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int N = nums.size(); vector<ll> P(N + 1);
    for (auto& q : queries) ++P[q[0]], --P[q[1] + 1];
    for (int i = 1; i <= N; ++i) P[i] += P[i - 1];
    for (int i = 0; i < N; ++i) {
      if (P[i] < nums[i]) return false;
    }
    return true;
  }
};
