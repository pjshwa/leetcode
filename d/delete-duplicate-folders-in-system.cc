class TrieNode {
public:
  bool valid, deleted;
  map<string, int> child;
  string subtree;

  TrieNode() {
    valid = false;
    deleted = false;
  }
};

class Trie {
private:
  int _newNode() {
    TrieNode tmp;
    trie.push_back(tmp);
    return trie.size() - 1;
  }

  void _add(vector<string> &V, int node, int idx) {
    if (idx == V.size()) {
      trie[node].valid = true;
      return;
    }
    if (trie[node].child.count(V[idx]) == 0) {
      trie[node].child[V[idx]] = _newNode();
    }
    _add(V, trie[node].child[V[idx]], idx + 1);
  }

public:
  vector<TrieNode> trie;
  vector<string> paths;

  Trie() {
    _newNode();
  }

  void add(vector<string> &V) {
    _add(V, 0, 0);
  }

  string tally(map<string, int> &T, string key, int node) {
    string ret = "";
    for (auto& [v, i] : trie[node].child) {
      ret += "(" + tally(T, v, i) + ")";
    }
    if (ret.size() > 0) ++T[ret];
    trie[node].subtree = ret;
    return key + ret;
  }

  void collect(vector<vector<string>>& ans, int node) {
    if (trie[node].deleted) return;
    if (!paths.empty()) ans.push_back(paths);
    for (auto& [v, i] : trie[node].child) {
      paths.push_back(v);
      collect(ans, i);
      paths.pop_back();
    }
  }
};

class Solution {
public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    Trie trie;
    for (auto &path : paths) trie.add(path);

    map<string, int> T;
    trie.tally(T, "", 0);

    for (auto& t : trie.trie) {
      if (T[t.subtree] > 1) t.deleted = true;
    }

    vector<vector<string>> ans;
    trie.collect(ans, 0);
    return ans;
  }
};
