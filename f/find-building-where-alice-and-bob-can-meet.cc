class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int H = heights.size(), Q = queries.size();
    vector<tuple<int, int, int>> qv;

    auto movable = [&](int s, int e) {
      return (s == e) || (s < e && heights[s] < heights[e]);
    };
    for (int i = 0; i < Q; ++i) {
      int a = queries[i][0], b = queries[i][1];
      if (a > b) swap(a, b);
      qv.push_back({b, a, i});
    }
    sort(qv.begin(), qv.end(), greater<>());

    int hi = H - 1; vector<int> ans(Q, -1);
    vector<pair<int, int>> T;
    for (auto& [e, s, i] : qv) {
      while (hi > e) {
        int t = heights[hi];
        while (!T.empty() && T.back().first <= t) T.pop_back();
        T.emplace_back(t, hi); --hi;
      }
      if (movable(s, e)) {
        ans[i] = e;
        continue;
      }

      int l = 0, r = T.size(), target = max(heights[s], heights[e]);
      while (l < r) {
        int m = (l + r) / 2;
        if (T[m].first <= target) r = m;
        else l = m + 1;
      }
      if (l > 0 && T[l - 1].first > target) ans[i] = T[l - 1].second;
    }
    return ans;
  }
};
