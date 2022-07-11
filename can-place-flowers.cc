class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int sz = flowerbed.size(), cnt = 0;
    for (int i = 0; i < sz; i++) {
      if (i > 0 && flowerbed[i - 1]) continue;
      if (i < sz - 1 && flowerbed[i + 1]) continue;
      if (flowerbed[i]) continue;
      flowerbed[i] = 1;
      cnt++;
    }
    return cnt >= n;
  }
};
