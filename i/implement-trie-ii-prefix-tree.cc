struct TrieNode {
  int count, exact_count, child[26];

  TrieNode() {
    count = exact_count = 0;
    memset(child, -1, sizeof(child));
  }
};

class Trie {
  vector<TrieNode> trie;
  TrieNode root;

public:
  Trie() {
    root = TrieNode();
    trie.push_back(root);
  }
  
  void insert(string word) {
    int node = 0;
    for (char c : word) {
      if (trie[node].child[c - 'a'] == -1) {
        trie[node].child[c - 'a'] = trie.size();
        trie.push_back(TrieNode());
      }
      node = trie[node].child[c - 'a'];
      trie[node].count++;
    }
    trie[node].exact_count++;
  }

  int countWordsEqualTo(string word) {
    int node = 0;
    for (char c : word) {
      if (trie[node].child[c - 'a'] == -1) return 0;
      node = trie[node].child[c - 'a'];
    }
    return trie[node].exact_count;
  }

  int countWordsStartingWith(string prefix) {
    int node = 0;
    for (char c : prefix) {
      if (trie[node].child[c - 'a'] == -1) return 0;
      node = trie[node].child[c - 'a'];
    }
    return trie[node].count;
  }

  void erase(string word) {
    int node = 0;
    for (char c : word) {
      node = trie[node].child[c - 'a'];
      trie[node].count--;
    }
    trie[node].exact_count--;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
 