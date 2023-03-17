struct TrieNode {
  TrieNode* C[26]{};
  bool valid = false;
};

class Trie {
  TrieNode *root;

public:
  Trie() {
    root = new TrieNode();
  }
  
  void insert(string word) {
    TrieNode *p = root;
    for (char c : word) {
      if (!p->C[c - 'a']) {
        p->C[c - 'a'] = new TrieNode();
      }
      p = p->C[c - 'a'];
    }
    p->valid = true;
  }

  bool search(string word) {
    TrieNode *p = root;
    for (char c : word) {
      if (!p->C[c - 'a']) {
        return false;
      }
      p = p->C[c - 'a'];
    }
    return p->valid;
  }
  
  bool startsWith(string prefix) {
    TrieNode *p = root;
    for (char c : prefix) {
      if (!p->C[c - 'a']) {
        return false;
      }
      p = p->C[c - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
