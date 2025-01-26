class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    map<int, int> lev_m; int lev = 0, N = nums.size();
    auto nums_s = nums; sort(nums_s.begin(), nums_s.end());

    lev_m[nums_s[0]] = lev;
    for (int i = 1; i < N; ++i) {
      if (nums_s[i] - nums_s[i - 1] > limit) ++lev;
      lev_m[nums_s[i]] = lev;
    }

    vector<int> by_lev[N];
    for (int e : nums) by_lev[lev_m[e]].push_back(e);
    for (int i = 0; i < N; ++i) {
      sort(by_lev[i].begin(), by_lev[i].end());
      reverse(by_lev[i].begin(), by_lev[i].end());
    }

    vector<int> ans(N, -1);
    for (int i = 0; i < N; ++i) {
      int lev = lev_m[nums[i]];
      ans[i] = by_lev[lev].back();
      by_lev[lev].pop_back();
    }
    return ans;
  }
};
