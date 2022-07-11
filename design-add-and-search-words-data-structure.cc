#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  bool valid;
  int child[26];

  TrieNode() {
    valid = false;
    for (int i = 0; i < 26; i++) child[i] = -1;
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
      trie[node].valid = true; return;
    }
    int c = str[idx] - 'a';
    if (trie[node].child[c] == -1) {
      int next = _newNode();
      trie[node].child[c] = next;
    }
    _add(str, trie[node].child[c], idx + 1);
  }

  bool _exist_rec(int si, int ti) {
    if (si == tmp.size()) return trie[ti].valid;

    if (tmp[si] == '.') {
      for (int i = 0; i < 26; i++) {
        if (trie[ti].child[i] == -1) continue;
        if (_exist_rec(si + 1, trie[ti].child[i])) return true;
      }
    }
    else {
      int c = tmp[si] - 'a';
      if (trie[ti].child[c] == -1) return false;
      return _exist_rec(si + 1, trie[ti].child[c]);
    }
    return false;
  }

  bool _exist(string &str) {
    tmp = str;
    return _exist_rec(0, 0);
  }
public:
  vector<TrieNode> trie;
  Trie() {
    _newNode();
  }
  void add(string &str) {
    _add(str, 0, 0);
  }
  void add(char str[]) {
    string tmp(str);
    _add(tmp, 0, 0);
  }
  bool exist(string &str) {
    return _exist(str);
  }
  bool exist(char str[]) {
    string tmp(str);
    return _exist(tmp);
  }
};

class WordDictionary {
  Trie a;
public:
  void addWord(string word) {
    a.add(word);
  }

  bool search(string word) {
    return a.exist(word);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
  auto w = WordDictionary();
  for (int i = 0; i < 100; i++) {
    string s = "";
    for (int j = 0; j < 100; j++) {
      s += 'a' + rand() % 26;
    }
    w.addWord(s);
  }
  string q = "";
  for (int i = 0; i < 99; i++) q += '.';
  for (int i = 0; i < 100; i++) {
    cout << i << endl;
    w.search(q);
  }
}
