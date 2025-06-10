class Solution {
public:
  int maxDifference(string s) {
    int C[26] = {0}, N = s.size();
    for (char c : s) ++C[c - 'a'];

    int oddMax = -N, evenMin = N;
    for (int i = 0; i < 26; ++i) {
      if (C[i] & 1) oddMax = max(oddMax, C[i]);
      else if (C[i]) evenMin = min(evenMin, C[i]);
    }
    return oddMax - evenMin;
  }
};
