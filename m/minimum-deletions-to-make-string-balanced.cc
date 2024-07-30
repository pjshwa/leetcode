class Solution {
public:
  int minimumDeletions(string s) {
    int N = s.size();
    int P[N + 1]; memset(P, 0, sizeof(P));
    for (int i = 1; i <= N; ++i) {
      P[i] = P[i - 1] + (s[i - 1] == 'a');
    }

    int ans = N;
    for (int i = 0; i <= N; ++i) {
      int lb = i - P[i], ra = P[N] - P[i];
      ans = min(ans, lb + ra);
    }
    return ans;
  }
};
