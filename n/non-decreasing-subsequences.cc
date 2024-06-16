class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> ans;
    for (int s = 1; s < (1 << n); s++) {
      int z = __builtin_popcount(s);
      if (z < 2) continue;

      vector<int> seq;
      for (int i = 0; i < n; i++) {
        if (s & (1 << i)) seq.push_back(nums[i]);
      }

      bool ok = true;
      for (int i = 1; i < z; i++) {
        if (seq[i] < seq[i - 1]) {
          ok = false;
          break;
        }
      }

      if (ok) ans.push_back(seq);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};
