#include <bits/stdc++.h>
using namespace std;

struct Segment {
  int s, e;
  Segment(int a, int b) : s(a), e(b) {};
  Segment() {};
  bool operator<(const Segment &rhs) const {
    return e - s > rhs.e - rhs.s;
  }
};

class Solution {
public:
  vector<int> minInterval(vector<vector<int>> intervals, vector<int> queries) {
    int iz = intervals.size(), qz = queries.size();
    vector<pair<int, int>> nqs;
    for (int i = 0; i < qz; i++) nqs.push_back({queries[i], i});
    sort(nqs.begin(), nqs.end());
    sort(intervals.begin(), intervals.end());

    vector<int> ans;
    ans.resize(qz);

    int ii = 0;
    priority_queue<Segment> sv;
    for (auto[query, oi] : nqs) {
      while (ii < iz && intervals[ii][0] <= query) {
        sv.push({intervals[ii][0], intervals[ii][1]});
        ii++;
      }
      while (!sv.empty() && sv.top().e < query) sv.pop();
      ans[oi] = sv.empty() ? -1 : sv.top().e - sv.top().s + 1;
    }

    return ans;
  }
};


int main() {
  Solution s;
  auto ans1 = s.minInterval({{1, 4}, {2, 4}, {3, 6}, {4, 4}}, {2, 3, 4, 5});
  for (int a : ans1) cout << a << ' ';
  cout << '\n';

  auto ans2 = s.minInterval({{2, 3}, {2, 5}, {1, 8}, {20, 25}}, {2, 19, 5, 22});
  for (int a : ans2) cout << a << ' ';
  cout << '\n';
}
