class Solution {
public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int N = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans; vector<int> cur;
    for (int i = 0; i < N; i++) {
      cur.push_back(nums[i]);
      if (i % 3 == 2) ans.push_back(cur), cur.clear();
    }

    for (auto& cur : ans) {
      int f = cur.front(), b = cur.back();
      if (b - f > k) return {};
    }
    return ans;
  }
};
