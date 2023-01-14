class Solution {
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = 26;
    int parent[n];
    iota(parent, parent + n, 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    for (int i = 0; i < s1.size(); i++) Union(s1[i] - 'a', s2[i] - 'a');

    string ans = "";
    for (int i = 0; i < baseStr.size(); i++) {
      for (char c = 'a'; c <= 'z'; c++) {
        if (Find(c - 'a') == Find(baseStr[i] - 'a')) {
          ans += c;
          break;
        }
      }
    }
    return ans;
  }
};
