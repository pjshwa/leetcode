class Solution {
public:
  long long maxSum(vector<int>& nums, int m, int k) {
    long long ans = 0;

    map<int, int> tal; long long acc = 0;
    for (int i = 0; i < k; ++i) {
      tal[nums[i]]++;
      acc += nums[i];
    }
    if (tal.size() >= m) ans = max(ans, acc);

    for (int i = k; i < nums.size(); ++i) {
      tal[nums[i]]++;
      acc += nums[i];
      tal[nums[i - k]]--;
      acc -= nums[i - k];

      if (tal[nums[i - k]] == 0) tal.erase(nums[i - k]);
      if (tal.size() >= m) ans = max(ans, acc);
    }

    return ans;
  }
};
