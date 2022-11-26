using tii = tuple<int, int, int>;

class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<tii> A;
    for (int i = 0; i < n; i++) {
      A.push_back({startTime[i], endTime[i], profit[i]});
    }
    sort(A.begin(), A.end(), [](tii& a, tii& b) {
      return get<1>(a) < get<1>(b);
    });

    int prev = -1, ans = 0;
    map<int, int> d;
    for (auto [s, e, p] : A) {
      if (prev != -1) d[e] = max(d[e], d[prev]);
      prev = e;

      auto it = d.upper_bound(s);
      if (it == d.begin()) d[e] = max(d[e], p);
      else {
        it--;
        d[e] = max(d[e], it->second + p);
      }
      ans = max(ans, d[e]);
    }

    return ans;
  }
};
