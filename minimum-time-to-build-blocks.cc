const int MAXV = 1024, INF = 0x3f3f3f3f;

class Solution {
  int dp[MAXV][MAXV + 1];
  vector<int> blocks;
  int split_cost;

  int rec(int idx, int wk_cnt) {
    if (dp[idx][wk_cnt] != -1) return dp[idx][wk_cnt];

    // base cases
    if (idx == blocks.size()) return 0;
    if (wk_cnt == 0) return INF;

    int ret = max(rec(idx + 1, wk_cnt - 1), blocks[idx]);
    if (2 * wk_cnt <= MAXV) ret = min(ret, rec(idx, 2 * wk_cnt) + split_cost);

    return dp[idx][wk_cnt] = ret;
  }

public:
  int minBuildTime(vector<int>& blocks, int split) {
    sort(blocks.begin(), blocks.end(), greater<>());
    this->blocks = blocks;
    this->split_cost = split;

    memset(dp, -1, sizeof dp);
    return rec(0, 1);
  }
};
