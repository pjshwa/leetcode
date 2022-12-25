class Solution {
public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++) nums[i] += nums[i - 1];

    vector<int> ans;
    for (int q : queries) {
      auto it = upper_bound(nums.begin(), nums.end(), q);
      ans.push_back(it - nums.begin());
    }
    return ans;
  }
};
