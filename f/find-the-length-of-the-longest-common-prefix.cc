class TrieNode {
public:
  bool valid;
  int child[10];

  TrieNode() {
    valid = false;
    memset(child, -1, sizeof(child));
  }
};

class Trie {
private:
  int _newNode() {
    TrieNode tmp;
    trie.push_back(tmp);
    return trie.size() - 1;
  }

  void _add(string &str, int node, int idx) {
    if (idx == str.size()) {
      trie[node].valid = true;
      return;
    }
    int c = str[idx] - '0';
    if (trie[node].child[c] == -1) {
      int next = _newNode();
      trie[node].child[c] = next;
    }
    _add(str, trie[node].child[c], idx + 1);
  }

  int _getScore(string &str, int node, int idx) {
    if (idx == str.size()) return 0;
    int c = str[idx] - '0';
    if (trie[node].child[c] == -1) return 0;
    return 1 + _getScore(str, trie[node].child[c], idx + 1);
  }

public:
  vector<TrieNode> trie;
  Trie() {
    _newNode();
  }

  void add(string &str) {
    _add(str, 0, 0);
  }

  int getScore(string &str) {
    return _getScore(str, 0, 0);
  }
};

class Solution {
public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    auto trie = Trie();
    for (auto e : arr1) {
      string str = to_string(e);
      trie.add(str);
    }

    int ans = 0;
    for (auto e : arr2) {
      string str = to_string(e);
      ans = max(ans, trie.getScore(str));
    }
    return ans;
  }
};
