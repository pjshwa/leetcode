class Solution {
public:
  int minFlips(string s) {
    int N = s.size(), sum = 0;
    for (int i = 0; i < N; ++i) {
      sum += (s[i] - '0') ^ (i & 1);
    }

    int ans = min(sum, N - sum);
    if (N & 1) {
      for (int i = 0; i < N; ++i) {
        sum -= (s[i] - '0') ^ (i & 1);
        sum += (s[i] - '0') ^ ((i + 1) & 1);
        ans = min(ans, min(sum, N - sum));
      }
    }
    return ans;
  }
};
