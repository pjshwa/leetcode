#define ll long long
#define pll pair<ll, ll>

const int MAX = 1e5;
const ll INF = 1e18;
ll cdist[MAX + 1];
vector<pll> graph[MAX + 1];

void dijk(int s) {
  fill(cdist, cdist + MAX + 1, INF);
  cdist[s] = 0;

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [wi, ui] = pq.top();
    pq.pop();

    if (wi > cdist[ui]) continue;

    for (auto &p : graph[ui]) {
      auto [vi, di] = p;
      if (cdist[vi] > di + wi) {
        cdist[vi] = di + wi;
        pq.push({cdist[vi], vi});
      }
    }
  }
}

class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      graph[i].clear();
      if (i + arr[i] < n) graph[i].push_back({i + arr[i], 1});
      if (i - arr[i] >= 0) graph[i].push_back({i - arr[i], 1});
    }
    dijk(start);
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0 && cdist[i] != INF) return true;
    }
    return false;
  }
};
