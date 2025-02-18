class Solution {
public:
  string smallestNumber(string pattern) {
    int N = pattern.size() + 1;
    int p[N]; iota(p, p + N, 0);

    string ans;
    do {
      int ok = 1;
      for (int i = 1; i < N; ++i) {
        if (p[i] > p[i - 1] && pattern[i - 1] == 'D') ok = 0;
        if (p[i] < p[i - 1] && pattern[i - 1] == 'I') ok = 0;
      }
      if (ok) {
        ans = "";
        for (int i = 0; i < N; ++i) ans += '1' + p[i];
        break;
      }
    } while (next_permutation(p, p + N));

    return ans;
  }
};
