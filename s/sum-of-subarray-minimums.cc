using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

class Solution {
public:
  int sumSubarrayMins(vector<int>& arr) {
    int N = arr.size();
    int parent[N], usz[N], vis[N];

    iota(parent, parent + N, 0);
    fill(vis, vis + N, 0);
    fill(usz, usz + N, 1);

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

    priority_queue<pii> pq;
    for (int i = 0; i < N; ++i) pq.emplace(arr[i], i);

    ll ans = 0;
    while (!pq.empty()) {
      auto [x, i] = pq.top(); pq.pop();
      vis[i] = 1;

      ll cur = 1;
      for (int j : {i - 1, i + 1}) {
        if (j < 0 || j >= N || !vis[j]) continue;
        cur = (cur * (1 + usz[Find(j)])) % MOD;
        Union(i, j);
      }
      ans = (ans + cur * x) % MOD;
    }
    return ans;
  }
};
