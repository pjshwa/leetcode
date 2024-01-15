class Solution {
public:
  int calculateTime(string keyboard, string word) {
    int D[26][26];
    for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) {
      int ci = keyboard[i] - 'a', cj = keyboard[j] - 'a';
      D[ci][cj] = abs(i - j);
    }

    int ans = 0, last = keyboard[0] - 'a';
    for (char c : word) {
      ans += D[last][c - 'a'];
      last = c - 'a';
    }
    return ans;
  }
};
