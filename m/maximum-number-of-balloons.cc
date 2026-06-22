class Solution {
public:
  int maxNumberOfBalloons(string text) {
    int C[26]{};
    for (char c : text) ++C[c - 'a'];
    return min({C[0], C[1], C[11] / 2, C[13], C[14] / 2});
  }
};
