class Solution {
public:
  bool canPermutePalindrome(string s) {
    int C[26]{};
    for (char& c : s) C[c - 'a'] ^= 1;

    int cnt = 0;
    for (int i = 0; i < 26; ++i) cnt += C[i];
    return cnt <= 1;
  }
};
