class Solution {
public:
  long long maximumTripletValue(vector<int>& nums) {
    int N = nums.size();

    long long ans = 0;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) for (int k = j + 1; k < N; ++k) {
      long long val = nums[i] - nums[j];
      val *= nums[k];
      ans = max(ans, val);
    }

    return ans;
  }
};
