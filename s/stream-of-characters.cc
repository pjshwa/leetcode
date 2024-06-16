#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  bool valid;
  int child[26];
  TrieNode(){
    valid = false;
    for (int i = 0; i < 26; i++) child[i] = -1;
  }
};

class Trie {
private:
  int _newNode(){
    TrieNode tmp;
    trie.push_back(tmp);
    return trie.size() - 1;
  }
  void _add(string &str, int node, int idx) {
    if(idx == str.size()){
      trie[node].valid = true; return;
    }
    int c = str[idx] - 'a';
    if(trie[node].child[c] == -1) {
      int next = _newNode();
      trie[node].child[c] = next;
    }
    _add(str, trie[node].child[c], idx+1);
  }
  bool _exist(string &str) {
    int now = 0;
    for (int i = 0; i < str.size(); i++){
      int c = str[i] - 'a';
      if (trie[now].child[c] == -1) return false;
      now = trie[now].child[c];
    }
    return trie[now].valid;
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

class StreamChecker {
  string fsuf;
  Trie a;

public:
  StreamChecker(vector<string>& words) {
    fsuf = "";
    for (auto &w : words) {
      reverse(w.begin(), w.end());
      a.add(w);
    }
  }
  
  bool query(char letter) {
    fsuf += letter;

    int now = 0;
    for (int i = fsuf.size() - 1; i >= 0; i--) {
      int c = fsuf[i] - 'a';
      if (a.trie[now].child[c] == -1) return false;
      now = a.trie[now].child[c];
      if (a.trie[now].valid) return true;
    }
    return false;
  }
};
