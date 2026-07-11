#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5;

class Solution {
public:
  vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    auto nums_s = nums;
    sort(nums_s.begin(), nums_s.end());
    nums_s.erase(unique(nums_s.begin(), nums_s.end()), nums_s.end());
    n = nums_s.size();

    vector<vector<int>> E(n, vector<int>(20, 0)); int r = 0;
    for (int i = 0; i < n; ++i) {
      while (r < n && nums_s[r] - nums_s[i] <= maxDiff) ++r;
      E[i][0] = r - 1;
    }
    for (int j = 0; j < 19; j++) for (int i = 0; i < n; i++) E[i][j + 1] = E[E[i][j]][j];

    vector<int> nums_s_inv(MAXN + 1);
    for (int i = 0; i < n; ++i) nums_s_inv[nums_s[i]] = i;

    vector<int> ans;
    for (auto& q : queries) {
      int u = q[0], v = q[1];
      if (u == v) {
        ans.push_back(0);
        continue;
      }
      int s = nums_s_inv[nums[u]], e = nums_s_inv[nums[v]];
      if (s > e) swap(s, e);

      int cnt = 1;
      for (int k = 19; k >= 0; --k) {
        if (E[s][k] < e) {
          s = E[s][k];
          cnt += (1 << k);
        }
      }
      if (E[s][0] < e) cnt = -1;
      ans.push_back(cnt);
    }

    return ans;
  }
};
