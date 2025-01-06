class Solution {
public:
  vector<int> minOperations(string boxes) {
    int tot = 0, N = boxes.size();
    for (char c : boxes) tot += c - '0';

    vector<int> P(N + 1);
    for (int i = 1; i <= N; ++i) {
      P[i] = P[i - 1];
      if (boxes[i - 1] == '1') P[i] += i;
    }

    int lcnt = 0; vector<int> res;
    for (int i = 1; i <= N; ++i) {
      if (boxes[i - 1] == '1') ++lcnt;
      int rcnt = tot - lcnt;

      int lmove = lcnt * i - P[i];
      int rmove = P[N] - P[i] - rcnt * i;
      res.push_back(lmove + rmove);
    }
    return res;
  }
};
