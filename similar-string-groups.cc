class Solution {
  int n, z;
  bool adj(string& a, string& b) {
    int di1 = -1, di2 = -1, cnt = 0;
    for (int i = 0; i < z; i++) {
      if (a[i] == b[i]) continue;

      cnt++;
      if (di1 == -1) di1 = i;
      else if (di2 == -1) di2 = i;
      else return false;
    }
    return cnt == 0 || (cnt == 2 && a[di1] == b[di2] && a[di2] == b[di1]);
  }

public:
  int numSimilarGroups(vector<string>& strs) {
    n = strs.size(), z = strs[0].size();
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

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      if (adj(strs[i], strs[j])) Union(i, j);
    }

    set<int> U;
    for (int i = 0; i < n; i++) U.insert(Find(i));
    return U.size();
  }
};
