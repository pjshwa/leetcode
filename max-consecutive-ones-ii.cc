class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int N = nums.size(), f = 0;

    int L[N + 5], R[N + 5];
    L[0] = R[N + 1] = 0;
    for (int i = 1; i <= N; ++i) {
      if (nums[i - 1]) L[i] = L[i - 1] + 1;
      else L[i] = 0;
    }
    for (int i = N; i >= 1; --i) {
      if (nums[i - 1]) R[i] = R[i + 1] + 1;
      else R[i] = 0;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (nums[i - 1]) continue;

      f = 1;
      ans = max(ans, L[i - 1] + R[i + 1] + 1);
    }

    if (f) return ans;
    else return N;
  }
};
