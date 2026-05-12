class Solution {
public:
  int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
      return a[0] - a[1] < b[0] - b[1];
    });
    int ans = 0, add = 0;
    for (auto& t : tasks) ans += t[0];
    int e = ans;
    for (auto& t : tasks) {
      if (e < t[1]) add += t[1] - e, e = t[1];
      e -= t[0];
    }
    return ans + add;
  }
};
