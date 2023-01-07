class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    vector<int> P(n);
    for (int i = 0; i < n; ++i) {
      P[i] = gas[i] - cost[i];
      if (i > 0) P[i] += P[i - 1];
    }
    if (P[n - 1] < 0) return -1;

    int mval = P[0], mpos = 0;
    for (int i = 1; i < n; ++i) {
      if (P[i] < mval) mval = P[i], mpos = i;
    }
    return (mpos + 1) % n;
  }
};
