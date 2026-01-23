#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  int minimumPairRemoval(vector<int>& nums) {
    int ans = 0, cnt = 0, N = nums.size();
    vector<int> L(N), R(N), parent(N);
    vector<ll> V(nums.begin(), nums.end());
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < N; ++i) L[i] = i - 1, R[i] = i + 1;

    auto oob = [&](int x) {
      return x < 0 || x >= N;
    };
    function<int(int)> Find = [&](int x) {
      if (oob(x)) return x;
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x == y) return;
      parent[y] = x;
      L[x] = min(L[x], L[y]); R[x] = max(R[x], R[y]);
      V[x] += V[y];
    };

    using T = tuple<ll, int, int, int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    for (int i = 0; i < N - 1; ++i) {
      int dec = (V[i] > V[i + 1]);
      pq.emplace(V[i] + V[i + 1], i, i + 1, L[i], R[i + 1], dec);
      cnt += dec;
    }

    while (cnt) {
      auto [s, i, j, li, rj, d] = pq.top(); pq.pop();

      int gi = Find(i), gj = Find(j);
      int gl = Find(L[gi]), gr = Find(R[gj]);
      if (L[gi] != li || R[gj] != rj) continue;

      cnt -= d; ++ans;

      if (!oob(gl) && V[gl] > V[gi]) --cnt;
      if (!oob(gr) && V[gj] > V[gr]) --cnt;

      Union(gi, gj); int g = Find(gi);
      V[g] = s;
      if (!oob(gl)) {
        if (V[gl] > V[g]) ++cnt;
        pq.emplace(V[gl] + V[g], gl, g, L[gl], R[g], V[gl] > V[g]);
      }
      if (!oob(gr)) {
        if (V[g] > V[gr]) ++cnt;
        pq.emplace(V[g] + V[gr], g, gr, L[g], R[gr], V[g] > V[gr]);
      }
    }

    return ans;
  }
};
