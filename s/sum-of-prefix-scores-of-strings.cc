class TrieNode {
public:
  int child[26], val;

  TrieNode() {
    val = 0;
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
    ++trie[node].val;
    if (idx == str.size()) return;

    int c = str[idx] - 'a';
    if (trie[node].child[c] == -1) {
      int next = _newNode();
      trie[node].child[c] = next;
    }
    _add(str, trie[node].child[c], idx + 1);
  }

  int _getScore(string &str, int node, int idx) {
    int ret = trie[node].val;
    if (idx == str.size()) return ret;

    int c = str[idx] - 'a';
    if (trie[node].child[c] != -1) {
      ret += _getScore(str, trie[node].child[c], idx + 1);
    }
    return ret;
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
  vector<int> sumPrefixScores(vector<string>& words) {
    Trie trie;
    for (auto &word : words) {
      trie.add(word);
    }

    vector<int> ret; int N = words.size();
    for (auto &word : words) {
      ret.push_back(trie.getScore(word) - N);
    }
    return ret;
  }
};
