class Solution {
  int T[6][6][6], pw[6] = {1, 6, 36, 216, 1296, 7776}, pv[6], nv[6];
  bool canTransition(int ps, int ns, int l) {
    for (int i = 0; i < l; ++i) {
      pv[i] = (ps / pw[i]) % 6;
      if (i < l - 1) nv[i] = (ns / pw[i]) % 6;
    }
    for (int i = 0; i < l - 1; ++i) {
      if (T[pv[i + 1]][pv[i]][nv[i]] == 0) return false;
    }
    return true;
  }

  int to_state(string& s) {
    int state = 0;
    for (char c : s) state = state * 6 + (c - 'A');
    return state;
  }

public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    memset(T, 0, sizeof(T));
    for (auto& s : allowed) {
      T[s[0] - 'A'][s[1] - 'A'][s[2] - 'A'] = 1;
    }

    int z = bottom.size() - 1, ostate = to_state(bottom);
    vector<vector<int>> dp(z, vector<int>(pw[z], 0));
    for (int state = 0; state < pw[z]; ++state) {
      dp[0][state] = canTransition(ostate, state, z + 1);
    }

    for (int i = 1; i < z; ++i) {
      for (int pstate = 0; pstate < pw[z - i + 1]; ++pstate) {
        if (!dp[i - 1][pstate]) continue;
        for (int nstate = 0; nstate < pw[z - i]; ++nstate) {
          if (canTransition(pstate, nstate, z - i + 1)) {
            dp[i][nstate] = 1;
          }
        }
      }
    }

    for (int i = 0; i < 6; ++i) {
      if (dp[z - 1][i]) return true;
    }
    return false;
  }
};
