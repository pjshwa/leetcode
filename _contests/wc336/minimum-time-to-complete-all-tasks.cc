class Solution {
  int C[2001];
public:
  int findMinimumTime(vector<vector<int>>& tasks) {
    memset(C, 0, sizeof(C));
    sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
      if (a[1] == b[1]) return a[0] > b[0];
      return a[1] < b[1];
    });

    for (auto& vv : tasks) {
      int s = vv[0], e = vv[1], d = vv[2];

      int pre = 0;
      for (int i = s; i <= e; i++) pre += C[i];
      if (d <= pre) continue;

      int rem = d - pre;
      for (int i = e; i >= s; i--) {
        if (rem == 0) break;
        if (C[i]) continue;
        C[i] = 1;
        rem--;
      }
    }

    int ans = 0;
    for (int i = 0; i <= 2000; i++) ans += C[i];
    return ans;
  }
};
