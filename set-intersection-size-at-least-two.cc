class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>>& intervals) {
    map<int, int> by_x;
    for (auto& interval : intervals) {
      int x = interval[0], y = interval[1];
      if (by_x.count(x) == 0) by_x[x] = y;
      else by_x[x] = min(by_x[x], y);
    }

    vector<pair<int, int>> V;
    for (auto& [x, y] : by_x) V.push_back({x, y});

    int Z = V.size();
    for (int i = Z - 2; i >= 0; --i) {
      if (V[i].second >= V[i + 1].second) V[i].second = V[i + 1].second;
    }

    int ans = 0;
    deque<int> Q;
    for (auto& [x, y] : V) {
      while (!Q.empty() && Q.front() < x) Q.pop_front();
      if (Q.empty()) {
        Q.push_back(y - 1); Q.push_back(y);
        ans += 2;
      }
      else if (Q.size() == 1) {
        if (Q.back() == y) Q.push_front(y - 1);
        else Q.push_back(y);
        ans += 1;
      }
    }
    return ans;
  }
};
