class Solution {
public:
  vector<int> findMissingElements(vector<int>& nums) {
    sort(nums.begin(), nums.end()); vector<int> ans;
    for (int i = 1; i < nums.size(); ++i) {
      int s = nums[i - 1], e = nums[i];
      if (s + 1 == e) continue;
      for (int j = s + 1; j < e; ++j) ans.push_back(j);
    }
    return ans;
  }
};
