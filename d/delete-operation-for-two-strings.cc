class Solution {
  int lcs[501][501];
public:
  int minDistance(string word1, string word2) {
    int sz1 = word1.size(), sz2 = word2.size();
    for (int i = 1; i <= sz1; i++) for (int j = 1; j <= sz2; j++) {
      if (word1[i - 1] == word2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
      else lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
    }
    return sz1 + sz2 - 2 * lcs[sz1][sz2];
  }
};
