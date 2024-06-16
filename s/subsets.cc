class Solution {
  vector<int> nums, cur;
  vector<vector<int>> ans;
  int n;

  void dfs(int i) {
    if (i == n) {
      ans.push_back(cur);
      return;
    }

    cur.push_back(nums[i]);
    dfs(i + 1);
    cur.pop_back();
    dfs(i + 1);
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    this->nums = nums;
    n = nums.size();
    dfs(0);
    return ans;
  }
};
