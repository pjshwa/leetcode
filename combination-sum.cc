class Solution {
  vector<vector<int>> ans;
  vector<int> cur, nums;
  int csum = 0, n, t;

  void dfs(int i) {
    if (i == n) {
      if (csum == t) ans.push_back(cur);
      return;
    }

    int osum = csum;
    while (1) {
      if (csum > t) break;
      dfs(i + 1);
      cur.push_back(nums[i]);
      csum += nums[i];
    }
    while (csum > osum) {
      cur.pop_back();
      csum -= nums[i];
    }
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    nums = candidates;
    n = nums.size(), t = target;
    dfs(0);
    return ans;
  }
};
