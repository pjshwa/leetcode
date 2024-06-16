using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pii> v;
    for (int i = 0; i < n; ++i) v.push_back({efficiency[i], speed[i]});
    sort(v.begin(), v.end(), greater<pii>());

    priority_queue<int, vector<int>, greater<int>> pq;
    ll cur = 0, ans = 0, ce;
    for (auto [e, s] : v) {
      ce = e;
      pq.push(s);
      cur += s;
      if (pq.size() > k) {
        cur -= pq.top();
        pq.pop();
      }

      ans = max(ans, cur * ce);
    }

    return ans % 1000000007;
  }
};
