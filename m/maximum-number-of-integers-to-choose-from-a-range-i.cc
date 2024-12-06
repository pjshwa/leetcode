class Solution {
public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    sort(banned.begin(), banned.end());
    int bi = 0, Z = banned.size(), sum = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
      int ok = 1;
      while (bi < Z && i == banned[bi]) ++bi, ok = 0;
      if (ok) {
        sum += i;
        if (sum > maxSum) break;
        ++cnt;
      }
    }
    return cnt;
  }
};
