const int MAXN = 1e5;

class Solution {
public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    int N = source.size();
    vector<int> parent(N);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    for (auto& p : allowedSwaps) Union(p[0], p[1]);
    vector<multiset<int>> G1(N), G2(N);
    for (int i = 0; i < N; ++i) {
      G1[Find(i)].insert(source[i]);
      G2[Find(i)].insert(target[i]);
    }

    auto erase = [&](multiset<int>& G, int e) {
      auto it = G.find(e);
      if (it != G.end()) G.erase(it);
    };

    int ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int e : G1[i]) {
        if (G2[i].count(e)) erase(G2[i], e);
        else ++ans;
      }
    }
    return ans;
  }
};
