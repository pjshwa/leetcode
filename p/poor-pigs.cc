class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int e = minutesToTest / minutesToDie, v = 1;
    int ans = 0;
    while (v < buckets) {
      v *= (e + 1);
      ans++;
    }
    return ans;
  }
};
