class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    int N = nums.size(), acc = 0;
    map<int, int> P; P[0] = -1;
    for (int i = 0; i < N; ++i) {
      acc += nums[i];
      P[acc] = i;
    }
    int ans = INT_MAX; acc = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (P.find(x - acc) != P.end()) {
        ans = min(ans, N - i + P[x - acc]);
      }
      acc += nums[i];
    }
    return ans > N ? -1 : ans;
  }
};
