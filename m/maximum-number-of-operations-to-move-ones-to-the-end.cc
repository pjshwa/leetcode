class Solution {
public:
  int maxOperations(string s) {
    int N = s.size(), oc = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
      if (s[i] == '1') ++oc;
      else if (i == N - 1 || s[i + 1] == '1') ans += oc;
    }
    return ans;
  }
};
