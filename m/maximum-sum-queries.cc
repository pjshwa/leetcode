using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

class Solution {
public:
  vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
    vector<pii> A; int N = nums1.size();
    for (int i = 0; i < N; ++i) A.push_back({nums1[i], nums2[i]});
    sort(A.begin(), A.end(), greater<>());

    int Q = queries.size();
    vector<int> ans(Q, -1);

    vector<tuple<int, int, int>> Qv;
    for (int i = 0; i < Q; ++i) {
      auto& q = queries[i];
      Qv.push_back({q[0], q[1], i});
    }
    sort(Qv.begin(), Qv.end(), greater<>());

    int j = 0; set<pii> S;
    for (auto& [x, y, i] : Qv) {
      while (j < N && A[j].first >= x) {
        auto& [e1, e2] = A[j]; int sum = e1 + e2;
        auto [it, _] = S.insert({-e2, -sum}); ++j;

        auto it2 = it; ++it2;
        while (it2 != S.end() && it2->second > it->second) {
          it2 = S.erase(it2);
        }
      }

      auto it = S.lower_bound({y, -INF});
      if (it != S.end()) {
        ans[i] = -(it->second);
      }
    }
    return ans;
  }
};
