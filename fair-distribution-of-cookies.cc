class Solution {
  int C[8], N, K, ans = 0x3f3f3f3f;
  vector<int> cookies;

  void dfs(int i) {
    if (i == N) {
      int cur = 0;
      for (int j = 0; j < K; j++) {
        cur = max(cur, C[j]);
      }
      ans = min(ans, cur);
    }
    else {
      for (int j = 0; j < K; j++) {
        C[j] += cookies[i];
        dfs(i + 1);
        C[j] -= cookies[i];
      }
    }
  }

public:
  int distributeCookies(vector<int>& cookies, int k) {
    N = cookies.size(), K = k;
    this->cookies = cookies;
    dfs(0);
    return ans;
  }
};
