class Solution {
public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1, r = *max_element(quantities.begin(), quantities.end());
    while (l < r) {
      long long m = (l + r) / 2, cnt = 0;
      for (int q : quantities) cnt += (q + m - 1) / m;
      if (cnt > n) l = m + 1;
      else r = m;
    }
    return l;
  }
};
