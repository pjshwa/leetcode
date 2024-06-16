class Solution {
public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    map<int, int> t; int vmax = 0;
    for (int e : nums) {
      t[e]++;
      vmax = max(vmax, t[e]);
    }

    vector<vector<int>> ans(vmax, vector<int>());
    for (auto& [k, v] : t) for (int i = 0; i < v; ++i) {
      ans[i].push_back(k);
    }
    return ans;
  }
};
