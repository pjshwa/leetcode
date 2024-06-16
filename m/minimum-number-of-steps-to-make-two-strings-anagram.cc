class Solution {
public:
  int minSteps(string s, string t) {
    int C[26]{};
    for (auto c : s) C[c - 'a']++;
    for (auto c : t) C[c - 'a']--;

    int a = 0, b = 0;
    for (int i = 0; i < 26; i++) {
      if (C[i] > 0) a += C[i];
      if (C[i] < 0) b -= C[i];
    }
    return max(a, b);
  }
};
