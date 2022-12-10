class Solution {
  bool check(vector<int>& stones, int d) {
    int n = stones.size();
    if (d >= stones[n - 1]) return true;

    vector<bool> vis(n, false);

    int lx = 0;
    for (int i = 0; i < n - 1; i++) {
      if (stones[i] - lx > d) return false;

      if (stones[i + 1] - lx > d) {
        vis[i] = 1;
        lx = stones[i];
      }
    }
    if (stones[n - 1] - lx > d) return false;

    lx = stones[n - 1];
    for (int i = n - 1; i >= 0; i--) {
      if (vis[i]) continue;
      if (lx - stones[i] > d) return false;
      lx = stones[i];
    }

    return true;
  }

public:
  int maxJump(vector<int>& stones) {
    int n = stones.size();
    int left = 1, right = 1e9 + 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (check(stones, mid)) right = mid;
      else left = mid + 1;
    }

    return left;
  }
};
