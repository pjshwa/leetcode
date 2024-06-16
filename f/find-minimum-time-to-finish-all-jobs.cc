const int INF = 0x3f3f3f3f;

class Solution {
public:
  int minimumTimeRequired(vector<int>& jobs, int k) {
    int N = jobs.size();
    if (N == k) return *max_element(jobs.begin(), jobs.end());

    int dp[k][1 << N]; memset(dp, -1, sizeof dp);
    function<int(int, int)> rec = [&](int i, int state) {
      if (i == k) return state == 0 ? 0 : INF;
      if (dp[i][state] != -1) return dp[i][state];

      int ret = INF;

      vector<int> active;
      for (int j = 0; j < N; ++j) if (state & (1 << j)) active.push_back(j);
      int Z = active.size();

      // assign subset of jobs to worker i
      for (int s = 1; s < (1 << Z); ++s) {
        int cost = 0, nstate = state;
        for (int j = 0; j < Z; ++j) {
          if (s & (1 << j)) cost += jobs[active[j]], nstate ^= (1 << active[j]);
        }
        ret = min(ret, max(cost, rec(i + 1, nstate)));
      }

      return dp[i][state] = ret;
    };

    return rec(0, (1 << N) - 1);
  }
};
