class TrieNode {
public:
  int valid;
  map<string, int> child;

  TrieNode() {
    valid = 0;
  }
};

class Trie {
private:
  int _newNode() {
    TrieNode tmp;
    trie.push_back(tmp);
    return trie.size() - 1;
  }

  void _add(vector<string>& path, int node, int idx) {
    if (idx == path.size()) {
      trie[node].valid = 1;
      return;
    }

    string name = path[idx];
    if (trie[node].child.count(name) == 0) {
      int next = _newNode();
      trie[node].child[name] = next;
    }
    _add(path, trie[node].child[name], idx + 1);
  }

  void _traverse(int node, string path) {
    if (trie[node].valid) {
      ret.push_back(path);
      return;
    }

    for (auto& [name, next] : trie[node].child) {
      _traverse(next, path + "/" + name);
    }
  }

public:
  vector<TrieNode> trie;
  vector<string> ret;

  Trie() {
    _newNode();
  }

  void add(vector<string>& path) {
    _add(path, 0, 0);
  }

  void traverse() {
    _traverse(0, "");
  }
};

vector<string> split(const string &str, string delim) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(delim, start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));
    start = end + delim.size();
  }

  tokens.push_back(str.substr(start));
  return tokens;
}

class Solution {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    auto t = Trie();
    for (auto& name : folder) {
      auto tokens = split(name.substr(1), "/");
      t.add(tokens);
    }
    t.traverse();
    return t.ret;
  }
};
