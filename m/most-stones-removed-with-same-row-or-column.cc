using ll = long long;
const ll MAX = 20000;

class Solution {
  vector<int> H[MAX + 1], V[MAX + 1];
  int parent[MAX + 1], usz[MAX + 1];

  int Find(int x) {
    if (x == parent[x]) return x;
    else {
      int p = Find(parent[x]);
      parent[x] = p;
      return p;
    }
  }

  void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) return;

    parent[y] = x;
    usz[x] += usz[y];
  }

public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    for (int i = 1; i <= n; i++) parent[i] = i, usz[i] = 1;

    for (int i = 1; i <= n; i++) {
      int x = stones[i - 1][0], y = stones[i - 1][1];

      if (!H[x].empty()) Union(i, H[x][0]);
      if (!V[y].empty()) Union(i, V[y][0]);

      H[x].push_back(i);
      V[y].push_back(i);
    }

    set<int> groups;
    for (int i = 1; i <= n; i++) groups.insert(Find(i));

    int ans = 0;
    for (int g : groups) ans += usz[g] - 1;

    return ans;
  }
};
