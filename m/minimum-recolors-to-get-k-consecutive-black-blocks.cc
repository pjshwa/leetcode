class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int ans = 0, N = blocks.size();
    for (int i = 0; i < k; ++i) ans += blocks[i] == 'W';

    int cur = ans;
    for (int i = k; i < N; ++i) {
      cur += blocks[i] == 'W';
      cur -= blocks[i - k] == 'W';
      ans = min(ans, cur);
    }
    return ans;
  }
};
