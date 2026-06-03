#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Solution {
  int f(vector<int>& s, vector<int>& d, int t) {
    int n = s.size(), ret = INT_MAX;
    for (int i = 0; i < n; ++i) {
      ret = min(ret, max(s[i], t) + d[i]);
    }
    return ret;
  }

public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int N = landStartTime.size(), M = waterStartTime.size(), t1 = INT_MAX, t2 = INT_MAX;
    for (int i = 0; i < N; ++i) t1 = min(t1, landStartTime[i] + landDuration[i]);
    for (int i = 0; i < M; ++i) t2 = min(t2, waterStartTime[i] + waterDuration[i]);
    return min(f(landStartTime, landDuration, t2), f(waterStartTime, waterDuration, t1));
  }
};
