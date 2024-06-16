class Solution {
public:
  int countPalindromicSubsequence(string s) {
    bool U[26][26]; memset(U, 0, sizeof U);

    vector<int> L(26), R(26);
    for (char c : s) R[c - 'a'] += 1;

    for (char c : s) {
      int ci = c - 'a';
      R[ci] -= 1;

      for (int i = 0; i < 26; ++i) {
        if (L[i] > 0 && R[i] > 0) U[ci][i] = 1;
      }

      L[ci] += 1;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) ans += U[i][j];
    return ans;
  }
};
