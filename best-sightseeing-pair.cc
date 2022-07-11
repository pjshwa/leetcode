class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    priority_queue<int> pq;
    pq.push(values[0]);

    int n = values.size(), ans = 0, dt = 0;
    for (int i = 1; i < n; i++) {
      dt--;
      ans = max(ans, pq.top() + values[i] + dt);
      pq.push(values[i] - dt);
    }

    return ans;
  }
};
