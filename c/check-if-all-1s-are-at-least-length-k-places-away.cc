class Solution {
public:
  bool kLengthApart(vector<int>& nums, int k) {
    int N = nums.size();
    vector<int> P(N + 1, 0);
    for (int i = 1; i <= N; ++i) P[i] = P[i - 1] + nums[i - 1];
    for (int i = k + 1; i <= N; ++i) {
      if (P[i] - P[i - k - 1] > 1) return false;
    }
    return true;
  }
};
