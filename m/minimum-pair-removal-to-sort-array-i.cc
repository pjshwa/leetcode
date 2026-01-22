class Solution {
  bool is_non_decreasing(const vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1]) return false;
    }
    return true;
  }

public:
  int minimumPairRemoval(vector<int>& nums) {
    int ans = 0;
    while (!is_non_decreasing(nums)) {
      // cout << "Current array: ";
      // for (const auto& num : nums) cout << num << " ";
      // cout << endl;

      int n = nums.size(), sum = nums[0] + nums[1], ci = 0;
      for (int i = 1; i < n - 1; ++i) {
        int cur = nums[i] + nums[i + 1];
        if (cur < sum) sum = cur, ci = i;
      }
      nums.erase(nums.begin() + ci + 1);
      nums[ci] = sum;
      ++ans;
    }
    return ans;
  }
};
