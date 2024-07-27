const int INF = 0x3f3f3f3f;

class Solution {
public:
  long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    int cdist[26][26]; memset(cdist, 0x3f, sizeof(cdist));
    for (int i = 0; i < 26; ++i) cdist[i][i] = 0;
    for (int i = 0; i < original.size(); ++i) {
      int s = original[i] - 'a', t = changed[i] - 'a';
      cdist[s][t] = min(cdist[s][t], cost[i]);
    }

    for (int k = 0; k < 26; ++k) for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) {
      cdist[i][j] = min(cdist[i][j], cdist[i][k] + cdist[k][j]);
    }

    long long ans = 0;
    for (int i = 0; i < source.size(); ++i) {
      int s = source[i] - 'a', t = target[i] - 'a';
      if (cdist[s][t] == INF) return -1;
      ans += cdist[s][t];
    }
    return ans;
  }
};
