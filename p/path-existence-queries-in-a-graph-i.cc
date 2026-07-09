#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    vector<int> parent(n); iota(parent.begin(), parent.end(), 0);
    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };
    for (int i = 1; i < n; ++i) {
      if (abs(nums[i] - nums[i - 1]) <= maxDiff) Union(i, i - 1);
    }

    vector<bool> ans;
    for (auto& q : queries) ans.push_back(Find(q[0]) == Find(q[1]));
    return ans;
  }
};
