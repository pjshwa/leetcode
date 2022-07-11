class Solution {
  int parent[100'000];
  multiset<char> g2c[100'000];

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

    if (x != y) parent[y] = x;
  }

public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    for (int i = 0; i < n; i++) parent[i] = i;

    for (auto& pair : pairs) Union(pair[0], pair[1]);

    for (int i = 0; i < n; i++) g2c[Find(i)].insert(s[i]);

    string res = s;
    for (int i = 0; i < n; i++) {
      auto it = g2c[Find(i)].begin();
      res[i] = *it;
      g2c[Find(i)].erase(it);
    }

    return res;
  }
};
