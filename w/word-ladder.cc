using pii = pair<int, int>;

class Solution {
  bool connected(string& a, string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
      diff += a[i] != b[i];
    }
    return diff == 1;
  }

  vector<int> graph[5001];
  bool vis[5001];

public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size(), ei = -1;

    queue<pii> q;
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < n; i++) {
      if (wordList[i] == endWord) ei = i;
      if (connected(wordList[i], beginWord)) {
        q.push({i, 1});
        vis[i] = true;
      }
    }

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      if (connected(wordList[i], wordList[j])) {
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }

    while (!q.empty()) {
      auto [v, d] = q.front();
      q.pop();

      if (v == ei) return d + 1;

      for (int u : graph[v]) {
        if (!vis[u]) {
          vis[u] = true;
          q.push({u, d + 1});
        }
      }
    }

    return 0;
  }
};
