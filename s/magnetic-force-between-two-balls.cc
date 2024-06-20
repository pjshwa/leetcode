class Solution {
public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int l = 1, r = position.back(), N = position.size();
    while (l < r) {
      int mid = (l + r) / 2;

      int ll = position[0], cnt = 1;
      for (int i = 1; i < N; i++) {
        if (position[i] - ll >= mid) {
          cnt++;
          ll = position[i];
        }
      }

      if (cnt >= m) l = mid + 1;
      else r = mid;
    }
    return l - 1;
  }
};
