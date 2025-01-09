class Solution {
public:
  int equalDigitFrequency(string s) {
    int N = s.size();
    unordered_set<string> U;

    for (int i = 0; i < N; ++i) {
      int tal[10] = {}; string S = "";
      for (int j = i; j < N; ++j) {
        ++tal[s[j] - '0']; S += s[j];

        int ok = 1, u = -1;
        for (int c = 0; c < 10; ++c) {
          if (tal[c] == 0) continue;
          if (u == -1) u = tal[c];
          else if (u != tal[c]) {
            ok = 0;
            break;
          }
        }
        if (ok) U.insert(S);
      }
    }

    return U.size();
  }
};
