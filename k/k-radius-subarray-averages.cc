class Solution {
public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(n, -1);

    long long run = 0;
    for (int i = 0; i < min(2 * k, n); i++) run += nums[i];

    for (int i = k; i < n; i++) {
      if (i + k >= n) break;

      run += nums[i + k];
      ans[i] = run / (2 * k + 1);
      run -= nums[i - k];
    }
    return ans;
  }
};
