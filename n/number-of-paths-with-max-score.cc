#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int dx[3] = {1, 0, 1};
const int dy[3] = {0, 1, 1};

class Solution {
public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    int N = board.size();
    vector<vector<int>> dp(N, vector<int>(N, -1)); dp[N - 1][N - 1] = 0;
    auto oob = [&](int x, int y) { return x < 0 || x >= N || y < 0 || y >= N; };

    for (int i = N - 1; i >= 0; --i) for (int j = N - 1; j >= 0; --j) {
      if (board[i][j] == 'X') continue;
      int add = (board[i][j] == 'S' || board[i][j] == 'E') ? 0 : (board[i][j] - '0');
      for (int k = 0; k < 3; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (!oob(ni, nj) && dp[ni][nj] != -1) dp[i][j] = max(dp[i][j], dp[ni][nj] + add);
      }
    }
    if (dp[0][0] == -1) return {0, 0};

    vector<vector<int>> cnt(N, vector<int>(N, 0)); cnt[0][0] = 1;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      if (board[i][j] == 'X') continue;
      int add = (board[i][j] == 'S' || board[i][j] == 'E') ? 0 : (board[i][j] - '0');
      for (int k = 0; k < 3; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (!oob(ni, nj) && dp[ni][nj] != -1 && dp[ni][nj] + add == dp[i][j]) {
          cnt[ni][nj] = (cnt[ni][nj] + cnt[i][j]) % MOD;
        }
      }
    }

    return {dp[0][0], cnt[N - 1][N - 1]};
  }
};
