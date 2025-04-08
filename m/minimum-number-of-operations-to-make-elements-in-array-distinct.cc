class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    int N = nums.size(), C[101] = {0};
    int ans = (N + 2) / 3, f = 0;
    for (int i = 0; i < N % 3; ++i) {
      int k = N - 1 - i;
      if (++C[nums[k]] > 1) return ans;
      f = 1;
    }
    ans -= f;
    for (int i = N % 3; i < N; i += 3) {
      for (int j = 0; j < 3; ++j) {
        int k = N - 1 - i - j;
        if (++C[nums[k]] > 1) return ans;
      }
      --ans;
    }
    return ans;
  }
};
