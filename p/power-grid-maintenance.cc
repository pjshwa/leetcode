const int MAXN = 1e5, INF = 0x3f3f3f3f;

class Solution {
  int parent[MAXN + 1], C[MAXN + 1], O[MAXN + 1];

public:
  vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    iota(parent, parent + c + 1, 0);
    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    for (auto& conn : connections) {
      int u = conn[0], v = conn[1];
      parent[Find(u)] = Find(v);
    }

    fill(O, O + c + 1, 1);
    vector<pair<int, int>> nQ;
    for (auto& qry : queries) {
      int op = qry[0], u = qry[1];
      if (op == 2) {
        if (O[u] == 0) continue;
        O[u] = 0;
      }
      nQ.emplace_back(op, u);
    }

    memset(C, 0x3f, sizeof(C));
    for (int i = 1; i <= c; ++i) {
      if (!O[i]) continue;
      C[Find(i)] = min(C[Find(i)], i);
    }

    reverse(nQ.begin(), nQ.end());
    vector<int> res;
    for (auto& [op, u] : nQ) {
      if (op == 2) {
        C[Find(u)] = min(C[Find(u)], u);
        O[u] = 1;
      }
      else if (O[u]) res.push_back(u);
      else {
        int val = C[Find(u)];
        res.push_back(val == INF ? -1 : val);
      }
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
