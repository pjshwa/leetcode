#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
  vector<int> maxValue(vector<int>& nums) {
    int N = nums.size();
    vector<int> parent(N), G = nums;
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y, G[y] = max(G[x], G[y]);
    };

    stack<pii> st;
    for (int i = 0; i < N; ++i) {
      while (!st.empty() && st.top().first > nums[i]) {
        Union(i, st.top().second);
        st.pop();
      }
      st.push({G[Find(i)], i});
    }

    vector<int> ans;
    for (int i = 0; i < N; ++i) ans.push_back(G[Find(i)]);
    return ans;
  }
};
