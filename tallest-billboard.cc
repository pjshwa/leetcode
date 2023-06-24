class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    int N = rods.size();
    int acc1 = 0, acc2 = 0;

    map<int, int> max_by_diff;
    function<void(int)> dfs1 = [&](int i) {
      if (i == N / 2) {
        max_by_diff[acc1 - acc2] = max(max_by_diff[acc1 - acc2], acc1);
        return;
      }
      dfs1(i + 1);
      acc1 += rods[i];
      dfs1(i + 1);
      acc1 -= rods[i];
      acc2 += rods[i];
      dfs1(i + 1);
      acc2 -= rods[i];
    };
    dfs1(0);

    int ans = 0;
    function<void(int)> dfs2 = [&](int i) {
      if (i == N) {
        if (max_by_diff.count(acc2 - acc1)) {
          ans = max(ans, acc1 + max_by_diff[acc2 - acc1]);
        }
        return;
      }
      dfs2(i + 1);
      acc1 += rods[i];
      dfs2(i + 1);
      acc1 -= rods[i];
      acc2 += rods[i];
      dfs2(i + 1);
      acc2 -= rods[i];
    };
    dfs2(N / 2);

    return ans;
  }
};
