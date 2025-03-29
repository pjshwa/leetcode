class Solution {
public:
  int shortestWay(string source, string target) {
    int N = source.size(), M = target.size();
    source += source;
    vector<vector<int>> next(N, vector<int>(26));
    vector<int> pos(26, -1);
    for (int i = 2 * N - 1; i >= N; --i) pos[source[i] - 'a'] = i - N;
    for (int i = N - 1; i >= 0; --i) {
      for (int j = 0; j < 26; ++j) next[i][j] = pos[j];
      pos[source[i] - 'a'] = i;
    }

    int ans = 1, j = 0;
    while (j < N && source[j] != target[0]) ++j;
    if (j == N) return -1;

    for (int i = 1; i < M; ++i) {
      int pos_j = next[j][target[i] - 'a'];
      if (pos_j == -1) return -1;
      if (pos_j <= j) ++ans;
      j = pos_j;
    }
    return ans;
  }
};
