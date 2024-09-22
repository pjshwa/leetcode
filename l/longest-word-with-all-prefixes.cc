const int MAXN = 1e5;

class Solution {
  map<string, int> fi; int fcount = 0;
  string fi_inv[MAXN]; vector<int> adj[MAXN];

  int fidx(string f) {
    auto found = fi.find(f);
    if (fi.end() == found) {
      fi.insert({f, fcount});
      fi_inv[fcount] = f;
      return fcount++;
    }
    else return found->second;
  }

public:
  string longestWord(vector<string>& words) {
    for (auto& w : words) fidx(w);

    int N = fcount, outdegree[N], vis[N];
    memset(outdegree, 0, sizeof(outdegree));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; ++i) {
      auto w = fi_inv[i];
      for (char c = 'a'; c <= 'z'; ++c) {
        w.push_back(c);
        if (fi.find(w) != fi.end()) {
          adj[i].push_back(fi[w]);
          ++outdegree[i];
        }
        w.pop_back();
      }
    }

    queue<int> Q;
    for (int i = 0; i < N; ++i) {
      auto word = fi_inv[i];
      if (word.size() == 1) {
        Q.push(i); vis[i] = 1;
      }
    }
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (int v : adj[u]) {
        if (vis[v]) continue;
        Q.push(v); vis[v] = 1;
      }
    }

    string ans = ""; 
    for (int i = 0; i < N; ++i) {
      if (!vis[i] || outdegree[i]) continue;
      auto word = fi_inv[i];
      if (word.size() > ans.size() || (word.size() == ans.size() && word < ans)) {
        ans = word;
      }
    }
    return ans;
  }
};
