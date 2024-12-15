class Solution {
public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    using T = tuple<double, int, int>;
    priority_queue<T> pq;
    for (auto& c : classes) {
      int p = c[0], t = c[1];
      pq.push({(p + 1) * 1.0 / (t + 1) - p * 1.0 / t, p, t});
    }

    while (extraStudents--) {
      auto [delta, p, t] = pq.top(); pq.pop();
      p += 1, t += 1;
      pq.push({(p + 1) * 1.0 / (t + 1) - p * 1.0 / t, p, t});
    }

    double ans = 0;
    while (!pq.empty()) {
      auto [delta, p, t] = pq.top(); pq.pop();
      ans += p * 1.0 / t;
    }
    return ans / classes.size();
  }
};
