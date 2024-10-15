class Solution {
public:
  long long minimumSteps(string s) {
    long long ans = 0, cnt = 0, N = s.size();
    for (int i = 0; i < N; ++i) {
      if (s[i] == '0') ans += i - cnt++;
    }
    return ans;
  }
};
