
class Solution {
  int res[15];
public:
  int maximumGood(vector<vector<int>>& statements) {
    int n = statements.size();

    // If statements from good people have contradictions, then this combination is not possible
    int ans = 0;
    for (int state = 0; state < (1 << n); state++) {
      for (int i = 0; i < n; i++) {
        if (state & (1 << i)) res[i] = 1;
        else res[i] = 0;
      }

      bool able = true;
      for (int i = 0; i < n; i++) {
        if (state & (1 << i)) {
          for (int j = 0; j < n; j++) {
            if (statements[i][j] == 2) continue;
            if (res[j] != statements[i][j]) {
              able = false;
              break;
            }
          }
        }
        if (!able) break;
      }

      if (able) ans = max(ans, __builtin_popcount(state));
    }
    return ans;
  }
};
