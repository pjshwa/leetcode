class Solution {
public:
  int maxLength(vector<int>& ribbons, int k) {
    int l = 1, r = *max_element(ribbons.begin(), ribbons.end()) + 1;
    while (l < r) {
      int m = (l + r) / 2, cnt = 0;
      for (int e : ribbons) cnt += e / m;
      if (cnt < k) r = m;
      else l = m + 1;
    }
    return l - 1;
  }
};
