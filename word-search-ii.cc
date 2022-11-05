const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

class TrieNode {
public:
  int child[26], valid;

  TrieNode() {
    memset(child, -1, sizeof(child));
    valid = 0;
  }
};

class Trie {
  string tmp;
private:

  int _newNode() {
    TrieNode tmp;
    trie.push_back(tmp);
    return trie.size() - 1;
  }

  void _add(string &str, int node, int idx) {
    if (idx == str.size()) {
      trie[node].valid = 1;
      return;
    }

    int c = str[idx] - 'a';
    if (trie[node].child[c] == -1) {
      int next = _newNode();
      trie[node].child[c] = next;
    }
    _add(str, trie[node].child[c], idx + 1);
  }

public:
  vector<TrieNode> trie;
  Trie() {
    _newNode();
  }

  void add(string &str) {
    _add(str, 0, 0);
  }
};

class Solution {
  string cur;
  bool vis[13][13];
  int n, m;
  vector<string> ans;
  Trie trie;

  void dfs(vector<vector<char>>& board, int t, int i, int j) {
    if (t == -1) return;

    vis[i][j] = true;
    if (trie.trie[t].valid) {
      ans.push_back(cur);
      trie.trie[t].valid = 0;
    }

    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k], y = j + dy[k];
      if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) continue;

      char c = board[x][y];
      cur.push_back(c);
      dfs(board, trie.trie[t].child[c - 'a'], x, y);
      cur.pop_back();
    }

    vis[i][j] = false;
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    memset(vis, 0, sizeof(vis));
    cur = ""; ans.clear();

    trie = Trie();
    for (auto &w : words) trie.add(w);
    n = board.size(), m = board[0].size();

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      char c = board[i][j];
      cur.push_back(c);
      dfs(board, trie.trie[0].child[c - 'a'], i, j);
      cur.pop_back();
    }
    return ans;
  }
};
