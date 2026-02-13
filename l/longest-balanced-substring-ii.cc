const int MAXN = 1e5;

class Solution {
  int solve_one(string& s) {
    int C[3]{}, N = s.size(), ans = 0;
    map<pair<int, int>, int> D;
    for (int t = 0; t < 3; ++t) {
      D.clear(); D[{0, 0}] = -1;
      memset(C, 0, sizeof(C));
      for (int i = 0; i < N; ++i) {
        int c = s[i] - 'a';
        ++C[c];
        pair<int, int> key = {C[(t + 1) % 3], C[(t + 2) % 3]};
        if (D.count(key)) ans = max(ans, i - D[key]);
        else D[key] = i;
      }
    }
    return ans;
  }

  int solve_two(string& s) {
    int C[3]{}, N = s.size(), ans = 0;
    map<int, int> D;
    for (int t = 0; t < 3; ++t) {
      D.clear(); D[0] = -1;
      memset(C, 0, sizeof(C));
      for (int i = 0; i < N; ++i) {
        int c = s[i] - 'a';
        if (c == t) {
          D.clear(); D[0] = i;
          memset(C, 0, sizeof(C));
        }
        else {
          ++C[c];
          int key = C[(t + 1) % 3] - C[(t + 2) % 3];
          if (D.count(key)) ans = max(ans, i - D[key]);
          else D[key] = i;
        }
      }
    }
    return ans;
  }

  int solve_three(string& s) {
    int C[3]{}, N = s.size(), ans = 0;
    map<pair<int, int>, int> D;
    D[{0, 0}] = -1;
    for (int i = 0; i < N; ++i) {
      int c = s[i] - 'a';
      ++C[c];
      pair<int, int> key = {C[0] - C[1], C[0] - C[2]};
      if (D.count(key)) ans = max(ans, i - D[key]);
      else D[key] = i;
    }
    return ans;
  }

public:
  int longestBalanced(string s) {
    return max({solve_one(s), solve_two(s), solve_three(s)});
  }
};
