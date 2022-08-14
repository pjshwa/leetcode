class Solution {
  int cdist[500];
  vector<int> graph[500];
  vector<vector<string>> ans;
  vector<string> cur;
  string beginWord;

  bool adj(string& a, string& b) {
    int n = a.size(), diff = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        diff++;
        if (diff > 1) return false;
      }
    }
    return true;
  }

  void trace(int v, vector<string>& wordList) {
    if (cdist[v] == 1) {
      cur.push_back(beginWord);
      reverse(cur.begin(), cur.end());
      ans.push_back(cur);
      reverse(cur.begin(), cur.end());
      cur.pop_back();
      return;
    }

    for (int u : graph[v]) {
      if (cdist[u] + 1 == cdist[v]) {
        cur.push_back(wordList[u]);
        trace(u, wordList);
        cur.pop_back();
      }
    }

  }

public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();
    this->beginWord = beginWord;
    memset(cdist, -1, sizeof(cdist));

    queue<int> q;
    int ei = -1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (adj(wordList[i], wordList[j])) {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }

      if (adj(wordList[i], beginWord)) {
        q.push(i);
        cdist[i] = 1;
      }
      if (wordList[i] == endWord) ei = i;
    }
    if (ei == -1) return {};

    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : graph[u]) {
        if (cdist[v] == -1) {
          cdist[v] = cdist[u] + 1;
          q.push(v);
        }
      }
    }

    cur.push_back(endWord);
    trace(ei, wordList);
    return ans;
  }
};
