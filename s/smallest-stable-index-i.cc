class Solution {
public:
  int firstStableIndex(vector<int>& nums, int k) {
    int N = nums.size(); vector<int> Lx(N), Rm(N);
    Lx[0] = nums[0];
    for (int i = 1; i < N; ++i) Lx[i] = max(Lx[i - 1], nums[i]);
    Rm[N - 1] = nums[N - 1];
    for (int i = N - 2; i >= 0; --i) Rm[i] = min(Rm[i + 1], nums[i]);

    for (int i = 0; i < N; ++i) {
      int score = Lx[i] - Rm[i];
      if (score <= k) return i;
    }
    return -1;
  }
};
