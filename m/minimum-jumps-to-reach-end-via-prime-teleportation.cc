#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6, INF = 0x3f3f3f3f;
int lp[MAXN + 1], inv[MAXN + 1];
vector<int> pr;

class Solution {
  void init() {
    if (lp[2] == 2) return;

    // Sieve of Eratosthenes O(n)
    for (ll i = 2; i <= MAXN; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        inv[i] = pr.size();
        pr.push_back(i);
      }
      for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAXN; j++)
        lp[i * pr[j]] = pr[j];
    }
  }

  bool is_prime(int n) {
    if (n < 2) return false;
    return lp[n] == n;
  }

public:
  int minJumps(vector<int>& nums) {
    init();
    int N = nums.size(), Z = pr.size();
    vector<int> adj[N + Z];
    for (int i = 0; i < N - 1; ++i) {
      adj[i].push_back(i + 1);
      adj[i + 1].push_back(i);
    }

    for (int i = 0; i < N; ++i) {
      int x = nums[i];
      while (x > 1) {
        int p = lp[x];
        adj[N + inv[p]].push_back(i);
        while (x % p == 0) x /= p;
      }
    }

    vector<int> cdist(N + Z, INF); cdist[0] = 0;
    deque<int> q({0});
    while (!q.empty()) {
      int u = q.front(); q.pop_front();
      for (int v : adj[u]) {
        if (cdist[v] > cdist[u] + 1) {
          cdist[v] = cdist[u] + 1;
          q.push_back(v);
        }
      }
      if (u < N && is_prime(nums[u])) {
        int t = N + inv[nums[u]];
        if (cdist[t] > cdist[u]) {
          cdist[t] = cdist[u];
          q.push_front(t);
        }
      }
    }
    return cdist[N - 1];
  }
};
