
class TrieNode {
public:
  bool valid;
  int child[26], val;

  TrieNode() {
    valid = false;
    val = -1;
    for (int i = 0; i < 26; i++) child[i] = -1;
  }
};

class Trie {
private:
  int _newNode() {
    TrieNode tmp;
    trie.push_back(tmp);
    return trie.size() - 1;
  }

  void _add(string &str, int node, int idx, int val) {
    if (idx == str.size()) {
      trie[node].valid = true;
      trie[node].val = val;
      return;
    }
    int c = str[idx] - 'a';
    if (trie[node].child[c] == -1) {
      int next = _newNode();
      trie[node].child[c] = next;
    }
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
};

class Solution {
  map<int, int> u, a;
  int dz;

  void inc(int v) {
    if (u[v] == a[v]) dz--;
    u[v]++;
    if (u[v] == a[v]) dz++;
  }

  void dec(int v) {
    if (u[v] == a[v]) dz--;
    u[v]--;
    if (u[v] == a[v]) dz++;
  }

public:
  vector<int> findSubstring(string S, vector<string>& words) {
    int n = S.size(), wz = words.size(), z = words[0].size();

    map<string, int> tally;
    for (int i = 0; i < wz; i++) tally[words[i]]++;

    int nwz = 0;
    Trie t;
    for (auto p : tally) {
      string s = p.first;
      t.add(s, nwz);
      a[nwz] += p.second;
      nwz++;
    }

    vector<int> ans;
    for (int s = 0; s < z; s++) {
      queue<int> q;
      u.clear(); dz = 0;

      for (int k = s; k < n; k += z) {
        int now = 0;
        for (int i = 0; i < z && k + i < n; i++) {
          int c = S[k + i] - 'a';
          if (t.trie[now].child[c] == -1) break;
          now = t.trie[now].child[c];
        }

        int val = t.trie[now].val;
        q.push(val);
        if (val != -1) inc(val);
        if (q.size() > wz) {
          int v = q.front();
          q.pop();
          if (v != -1) dec(v);
        }

        if (dz == nwz) ans.push_back(k - (wz - 1) * z);
      }
    }

    return ans;
  }
};
