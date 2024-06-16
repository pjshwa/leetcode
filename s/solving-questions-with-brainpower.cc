class Solution {
public:
  long long mostPoints(vector<vector<int>>& questions) {
    int N = questions.size();

    long long d[N]; memset(d, -1, sizeof(d));
    function<long long(int)> r = [&](int i) {
      if (i >= N) return 0LL;
      if (d[i] != -1) return d[i];

      long long ret = r(i + 1), score = questions[i][0], skip = questions[i][1];
      ret = max(ret, r(i + skip + 1) + score);
      return d[i] = ret;
    };
    return r(0);
  }
};
