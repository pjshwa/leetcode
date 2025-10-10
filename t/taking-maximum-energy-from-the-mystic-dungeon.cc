class Solution {
public:
  int maximumEnergy(vector<int>& energy, int k) {
    int N = energy.size(), ans = -0x3f3f3f3f;
    for (int i = 0; i < k; ++i) {
      int sum = 0;
      for (int j = 0;; ++j) {
        int ni = N - 1 - i - j * k;
        if (ni < 0) break;
        sum += energy[ni];
        ans = max(ans, sum);
      }
    }
    return ans;
  }
};
