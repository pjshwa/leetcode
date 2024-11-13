using pii = pair<int, int>;

class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    vector<pii> queries_idx;
    for (int q : queries) queries_idx.push_back({q, queries_idx.size()});
    sort(queries_idx.begin(), queries_idx.end());
    sort(items.begin(), items.end());

    int N = items.size(), i = 0;
    priority_queue<int> pq;
    vector<int> ans(queries.size());
    for (auto [q, qi] : queries_idx) {
      while (i < N && items[i][0] <= q) pq.push(items[i++][1]);
      if (!pq.empty()) ans[qi] = pq.top();
    }
    return ans;
  }
};
