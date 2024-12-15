using pii = pair<int, int>;
const int MAXN = 1e5;

class Solution {
public:
  vector<int> maximumLengthOfRanges(vector<int>& nums) {
    int n = nums.size();
    int parent[n], usz[n];
    iota(parent, parent + n, 0);
    fill(usz, usz + n, 1);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x == y) return;
      if (usz[x] < usz[y]) swap(x, y);
      parent[y] = x; usz[x] += usz[y];
    };

    vector<int> by_val(MAXN + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; ++i) pq.emplace(nums[i], i);

    while (!pq.empty()) {
      auto [v, i] = pq.top(); pq.pop();
      for (int j : {i - 1, i + 1}) {
        if (j < 0 || j >= n || nums[j] > v) continue;
        Union(i, j);
      }
      by_val[v] = max(by_val[v], usz[Find(i)]);
    }

    vector<int> ans;
    for (int e : nums) ans.push_back(by_val[e]);
    return ans;
  }
};
