struct TrieNode {
  TrieNode* C[26]{};
  bool valid = false;
};

struct Trie {
  TrieNode* root;
  Trie() {
    root = new TrieNode();
  }

  void insert(string word) {
    TrieNode* p = root;
    for (char c : word) {
      if (!p->C[c - 'a']) {
        p->C[c - 'a'] = new TrieNode();
      }
      p = p->C[c - 'a'];
    }
    p->valid = true;
  }
};

class WordDictionary {
  Trie trie;

  bool search_util(string& word, int i, TrieNode* p) {
    if (i == word.size()) return p->valid;

    char c = word[i];
    bool ret = false;
    for (int l = 0; l < 26; l++) {
      if (c != '.' && l != c - 'a') continue;
      if (!p->C[l]) continue;
      ret |= search_util(word, i + 1, p->C[l]);
    }
    return ret;
  }

public:
  WordDictionary() {}
  
  void addWord(string word) {
    trie.insert(word);
  }
  
  bool search(string word) {
    return search_util(word, 0, trie.root);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
