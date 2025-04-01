class Solution {
public:
  long long mostPoints(vector<vector<int>>& questions) {
    int N = questions.size();
    vector<long long> d(N);
    d[N - 1] = questions[N - 1][0];
    for (int i = N - 2; i >= 0; --i) {
      d[i] = d[i + 1];
      int score = questions[i][0], skip = questions[i][1];

      long long nxt = i + skip + 1 < N ? d[i + skip + 1] : 0;
      d[i] = max(d[i], nxt + score);
    }
    return d[0];
  }
};
