const int MAXV = 1e9;

class Solution {
  bool check(int limit, vector<int>& bloomDay, int m, int k) {
    int cnt = 0, str = 0;
    for (int b : bloomDay) {
      if (b > limit) str = 0;
      else str++;

      if (str == k) cnt++, str = 0;
    }
    return cnt >= m;
  }

public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    int l = 1, r = MAXV + 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid, bloomDay, m, k)) r = mid;
      else l = mid + 1;
    }
    return l == MAXV + 1 ? -1 : l;
  }
};
