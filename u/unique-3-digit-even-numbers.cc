class Solution {
public:
  int totalNumbers(vector<int>& digits) {
    int N = digits.size(); set<int> U;
    for (int i = 0; i < N; ++i) {
      if (digits[i] == 0) continue;
      for (int j = 0; j < N; ++j) {
        if (i == j) continue;
        for (int k = 0; k < N; ++k) {
          if (k == i || k == j || digits[k] % 2 != 0) continue;
          U.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
        }
      }
    }
    return U.size();
  }
};
