class Solution {
public:
  int minOperations(vector<int>& nums) {
    int N = nums.size();
    auto is_sorted = [&](int i, int f) {
      if (f) {
        for (int j = 0; j < N - 1; ++j) {
          if (nums[(i + j) % N] > nums[(i + j + 1) % N]) return false;
        }
      } else {
        for (int j = 0; j < N - 1; ++j) {
          if (nums[(i + j) % N] < nums[(i + j + 1) % N]) return false;
        }
      }
      return true;
    };

    for (int i = 0; i < N; ++i) {
      if (nums[i] == 0 && is_sorted(i, 0)) return min(i, N - i + 2);
      if (nums[i] == N - 1 && is_sorted(i, 1)) return min(i + 1, N - i + 1);
    }
    return -1;
  }
};
