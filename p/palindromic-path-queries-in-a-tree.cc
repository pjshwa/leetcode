#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
    vector<vector<int>> adj(n);
    for (const auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int LOG = 1;
    while ((1LL << LOG) <= n) ++LOG;

    vector<vector<int>> up(LOG, vector<int>(n));
    vector<int> depth(n), mask(n), parent(n, -1);
    vector<int> tin(n), tout(n), subtreeSize(n, 1);
    vector<int> order, stack = {0};
    parent[0] = 0;
    mask[0] = 1 << (s[0] - 'a');

    // Iterative DFS keeps every subtree contiguous without recursion depth limits.
    while (!stack.empty()) {
      int u = stack.back();
      stack.pop_back();
      tin[u] = order.size();
      order.push_back(u);
      up[0][u] = parent[u];

      for (int v : adj[u]) {
        if (parent[v] != -1) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        mask[v] = mask[u] ^ (1 << (s[v] - 'a'));
        stack.push_back(v);
      }
    }

    for (int i = n - 1; i >= 0; --i) {
      int u = order[i];
      tout[u] = tin[u] + subtreeSize[u];
      if (u != 0) subtreeSize[parent[u]] += subtreeSize[u];
    }

    // XOR difference array: range updates and point queries via Fenwick tree.
    vector<int> bit(n + 1);
    auto add = [&](int index, int delta) {
      for (int i = index + 1; i <= n; i += i & -i) bit[i] ^= delta;
    };
    auto prefixXor = [&](int index) {
      int value = 0;
      for (int i = index + 1; i > 0; i -= i & -i) value ^= bit[i];
      return value;
    };

    for (int k = 1; k < LOG; ++k) {
      for (int u = 0; u < n; ++u) {
        up[k][u] = up[k - 1][up[k - 1][u]];
      }
    }

    auto lca = [&](int u, int v) {
      if (depth[u] < depth[v]) swap(u, v);

      int diff = depth[u] - depth[v];
      for (int k = 0; k < LOG; ++k) {
        if (diff & (1 << k)) u = up[k][u];
      }
      if (u == v) return u;

      for (int k = LOG - 1; k >= 0; --k) {
        if (up[k][u] != up[k][v]) {
          u = up[k][u];
          v = up[k][v];
        }
      }
      return up[0][u];
    };

    vector<bool> answer;
    for (const string& query : queries) {
      stringstream ss(query);
      string type;
      ss >> type;
      if (type == "update") {
        int u;
        char c;
        ss >> u >> c;
        int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
        add(tin[u], delta);
        add(tout[u], delta);
        s[u] = c;
        continue;
      }

      int u, v;
      ss >> u >> v;
      int ancestor = lca(u, v);
      int pathMask = mask[u] ^ prefixXor(tin[u])
                   ^ mask[v] ^ prefixXor(tin[v])
                   ^ (1 << (s[ancestor] - 'a'));
      answer.push_back((pathMask & (pathMask - 1)) == 0);
    }
    return answer;
  }
};
