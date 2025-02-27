const int MAXN = 1000;

class Solution {
  unordered_map<int, int> by_val;
  int dp[MAXN][MAXN], arr[MAXN];

  int rec(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    int val = arr[j] - arr[i], ret;
    if (by_val.count(val) && by_val[val] < i) {
      ret = 1 + rec(by_val[val], i);
    }
    else ret = 2;
    return dp[i][j] = ret;
  }

public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int N = arr.size();
    for (int i = 0; i < N; ++i) {
      by_val[arr[i]] = i;
      this->arr[i] = arr[i];
    }

    memset(dp, -1, sizeof(dp)); int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) ans = max(ans, rec(i, j));
    return ans >= 3 ? ans : 0;
  }
};
