#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 200, INF = 0x3f3f3f3f;

class Solution {
  unordered_map<string, int> fi; int fcount = 0;
  int cdist[MAXN][MAXN];

  // Trie node for efficient string matching
  struct TrieNode {
    int children[26] = {};
    int idx = -1; // string index if this is end of a word
  };
  vector<TrieNode> trie;

  int newNode() {
    trie.push_back(TrieNode());
    return trie.size() - 1;
  }

  void insert(const string& s, int stringIdx) {
    int node = 0;
    for (char c : s) {
      int ch = c - 'a';
      if (!trie[node].children[ch]) {
        trie[node].children[ch] = newNode();
      }
      node = trie[node].children[ch];
    }
    trie[node].idx = stringIdx;
  }

  int fidx(const string& f) {
    auto found = fi.find(f);
    if (fi.end() == found) {
      fi.insert({f, fcount});
      return fcount++;
    }
    else return found->second;
  }

public:
  long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
    memset(cdist, 0x3f, sizeof(cdist));
    for (int i = 0; i < original.size(); ++i) {
      int u = fidx(original[i]);
      int v = fidx(changed[i]);
      cdist[u][v] = min(cdist[u][v], cost[i]);
    }

    // Floyd-Warshall
    int L = fcount;
    for (int i = 0; i < L; ++i) cdist[i][i] = 0;
    for (int k = 0; k < L; ++k) for (int i = 0; i < L; ++i) for (int j = 0; j < L; ++j) {
      if (cdist[i][k] == INF || cdist[k][j] == INF) continue;
      cdist[i][j] = min(cdist[i][j], cdist[i][k] + cdist[k][j]);
    }

    // Build two tries: one for source substrings, one for target substrings
    // We use separate tries to find matching positions
    trie.clear();
    newNode(); // root for source trie (index 0)
    int srcTrieRoot = 0;
    newNode(); // root for target trie (index 1)
    int tgtTrieRoot = 1;

    // Insert all original strings into source trie, changed strings into target trie
    for (const auto& [s, idx] : fi) {
      // Check if this string appears in original (source side)
      insert(s, idx);
    }
    // Rebuild for separate tries
    trie.clear();
    newNode(); // source trie root
    newNode(); // target trie root

    for (int i = 0; i < original.size(); ++i) {
      // Insert original[i] into source trie
      int node = 0;
      for (char c : original[i]) {
        int ch = c - 'a';
        if (!trie[node].children[ch]) {
          trie[node].children[ch] = newNode();
        }
        node = trie[node].children[ch];
      }
      trie[node].idx = fi[original[i]];

      // Insert changed[i] into target trie
      node = 1;
      for (char c : changed[i]) {
        int ch = c - 'a';
        if (!trie[node].children[ch]) {
          trie[node].children[ch] = newNode();
        }
        node = trie[node].children[ch];
      }
      trie[node].idx = fi[changed[i]];
    }

    int N = source.size();
    vector<ll> dp(N + 1, 1e18); dp[0] = 0;

    for (int i = 0; i < N; ++i) {
      if (dp[i] >= 1e18) continue;

      // Option 1: if characters match, skip
      if (source[i] == target[i]) {
        dp[i + 1] = min(dp[i + 1], dp[i]);
      }

      // Option 2: try to match substrings using tries
      int srcNode = 0, tgtNode = 1;
      for (int j = i; j < N; ++j) {
        int srcCh = source[j] - 'a';
        int tgtCh = target[j] - 'a';

        srcNode = trie[srcNode].children[srcCh];
        tgtNode = trie[tgtNode].children[tgtCh];

        if (!srcNode || !tgtNode) break;

        int u = trie[srcNode].idx;
        int v = trie[tgtNode].idx;
        if (u >= 0 && v >= 0 && cdist[u][v] < INF) {
          dp[j + 1] = min(dp[j + 1], dp[i] + cdist[u][v]);
        }
      }
    }
    return dp[N] >= 1e18 ? -1 : dp[N];
  }
};
