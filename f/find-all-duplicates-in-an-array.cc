class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans; set<int> vis;
    for (int i = 0; i < nums.size(); i++) {
      if (vis.count(nums[i])) ans.push_back(nums[i]);
      else vis.insert(nums[i]);
    }
    return ans;
  }
};
