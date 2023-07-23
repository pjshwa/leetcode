#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countPalindromePaths(vector<int>& parent, string s) {
    int N = parent.size();
    vector<pair<int, int>> adj[N];
    for (int i = 1; i < N; i++) {
      adj[parent[i]].push_back({i, s[i] - 'a'});
    }

    int V[N];
    function<void(int, int)> dfs = [&](int u, int val) {
      V[u] = val;
      for (auto [v, c] : adj[u]) {
        dfs(v, val ^ (1 << c));
      }
    };
    dfs(0, 0);

    unordered_map<int, int> M;
    for (int i = 0; i < N; i++) M[V[i]]++;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
      M[V[i]]--;

      ans += M[V[i]];
      for (int b = 0; b < 26; b++) {
        int nv = V[i] ^ (1 << b);
        if (M.count(nv)) ans += M[V[i] ^ (1 << b)];
      }

      M[V[i]]++;
    }
    return ans / 2;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  Solution sol;

  vector<int> parent; string s = "";
  int N = 1e5;
  for (int i = 0; i < N; i++) {
    parent.push_back(i / 2);
    s += 'a';
  }
  cout << sol.countPalindromePaths(parent, s) << endl;
}
