const int MAXV = 2000;

class Solution {
public:
  int countCompleteSubarrays(vector<int>& nums) {
    int N = nums.size(), cnt = 0, ans = 0, u = (new set<int>(nums.begin(), nums.end()))->size();
    vector<int> C(MAXV + 1, 0);
    auto inc = [&](int v, int d) {
      if (C[v] == 0) ++cnt;
      C[v] += d;
      if (C[v] == 0) --cnt;
    };
    for (int l = 0, r = 0; l < N; ++l) {
      while (r < N && cnt < u) inc(nums[r++], 1);
      if (cnt == u) ans += N - r + 1;
      inc(nums[l], -1);
    }
    return ans;
  }
};
