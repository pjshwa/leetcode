class Solution {
public:
  vector<int> applyOperations(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    }

    vector<int> ans;
    for (int e : nums) if (e) ans.push_back(e);
    while (ans.size() < N) ans.push_back(0);
    return ans;
  }
};
