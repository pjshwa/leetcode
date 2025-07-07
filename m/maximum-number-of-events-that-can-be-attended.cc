const int MAXD = 1e5;

class Solution {
public:
  int maxEvents(vector<vector<int>>& events) {
    int N = events.size();
    sort(events.begin(), events.end());

    int ei = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int d = 1; d <= MAXD; ++d) {
      while (ei < N && events[ei][0] == d) pq.push(events[ei++][1]);
      while (!pq.empty() && pq.top() < d) pq.pop();
      if (!pq.empty()) ++ans, pq.pop();
    }
    return ans;
  }
};
