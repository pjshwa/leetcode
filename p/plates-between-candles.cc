class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int N = s.size();
    int Rmost[N + 10], Lmost[N + 10], P[N + 10];
    Rmost[N + 1] = N, Lmost[0] = 1;

    P[0] = 0;
    for (int i = 1; i <= N; ++i) {
      P[i] = P[i - 1] + (s[i - 1] == '*');
    }

    for (int i = N; i >= 1; --i) {
      Rmost[i] = Rmost[i + 1];
      if (s[i - 1] == '|') Rmost[i] = i;
    }
    for (int i = 1; i <= N; ++i) {
      Lmost[i] = Lmost[i - 1];
      if (s[i - 1] == '|') Lmost[i] = i;
    }

    vector<int> ans;
    for (auto& Q : queries) {
      int l = Q[0] + 1, r = Q[1] + 1;
      l = Rmost[l]; r = Lmost[r];
      ans.push_back(max(0, P[r] - P[l - 1]));
    }
    return ans;
  }
};
