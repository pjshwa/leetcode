class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> d(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      d[i] = max(d[i - 1], (i >= 2 ? d[i - 2] : 0) + nums[i - 1]);
    }

    return d[n];
  }
};
