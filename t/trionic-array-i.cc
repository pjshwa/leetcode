class Solution {
  bool is_increasing(const vector<int>& arr, int s, int e) {
    for (int i = s; i < e; ++i) {
      if (arr[i] >= arr[i + 1]) return false;
    }
    return true;
  }

  bool is_decreasing(const vector<int>& arr, int s, int e) {
    for (int i = s; i < e; ++i) {
      if (arr[i] <= arr[i + 1]) return false;
    }
    return true;
  }

public:
  bool isTrionic(vector<int>& nums) {
    int N = nums.size();
    for (int p = 1; p < N; ++p) for (int q = p + 1; q < N - 1; ++q) {
      bool ok = is_increasing(nums, 0, p) &&
                is_decreasing(nums, p, q) &&
                is_increasing(nums, q, N - 1);
      if (ok) return true;
    }
    return false;
  }
};
