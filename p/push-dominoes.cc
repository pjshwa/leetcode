const int INF = 0x3f3f3f3f;

class Solution {
public:
  string pushDominoes(string dominoes) {
    int N = dominoes.size();
    vector<int> lcnt(N, INF), rcnt(N, INF);
    for (int i = N - 1, flag = 0; i >= 0; --i) {
      if (dominoes[i] == 'L') lcnt[i] = 0, flag = 1;
      else if (dominoes[i] == 'R') flag = 0;
      else if (flag) lcnt[i] = lcnt[i + 1] + 1;
    }
    for (int i = 0, flag = 0; i < N; ++i) {
      if (dominoes[i] == 'R') rcnt[i] = 0, flag = 1;
      else if (dominoes[i] == 'L') flag = 0;
      else if (flag) rcnt[i] = rcnt[i - 1] + 1;
    }

    string ans(N, '.');
    for (int i = 0; i < N; ++i) {
      if (lcnt[i] < rcnt[i]) ans[i] = 'L';
      if (lcnt[i] > rcnt[i]) ans[i] = 'R';
    }
    return ans;
  }
};
