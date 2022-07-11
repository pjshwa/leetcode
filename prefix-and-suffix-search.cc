class TrieNode {
public:
  int child[128], val;

  TrieNode() {
    for (int i = 0; i < 128; i++) child[i] = -1;
    val = -1;
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

  void _add(string &str, int node, int idx, int val) {
    if (idx == str.size()) return;

    int c = str[idx];
    if (trie[node].child[c] == -1) {
      int next = _newNode();
      trie[node].child[c] = next;
    }
    trie[trie[node].child[c]].val = val;
    _add(str, trie[node].child[c], idx + 1, val);
  }
public:
  vector<TrieNode> trie;
  Trie() {
    _newNode();
  }

  void add(string &str, int val) {
    _add(str, 0, 0, val);
  }

  void add(char str[], int val) {
    string tmp(str);
    _add(tmp, 0, 0, val);
  }

  int query(string &str) {
    int now = 0;
    for (int i = 0; i < str.size(); i++) {
      int c = str[i];
      if (trie[now].child[c] == -1) return -1;
      now = trie[now].child[c];
    }
    return trie[now].val;
  }
};

class WordFilter {
  Trie t;
public:
  WordFilter(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= words[i].size(); j++) {
        string wstr = words[i].substr(j) + "#" + words[i];
        t.add(wstr, i);
      }
    }
  }
  
  int f(string prefix, string suffix) {
    string qstr = suffix + "#" + prefix;
    return t.query(qstr);
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
