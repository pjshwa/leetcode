using pii = pair<int, int>;

class Solution {
public:
  int maxTwoEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end()); int maxp = 0, ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (auto& vv : events) {
      int s = vv[0], e = vv[1], v = vv[2];
      while (!pq.empty() && pq.top().first < s) {
        maxp = max(maxp, pq.top().second);
        pq.pop();
      }
      ans = max(ans, maxp + v);
      pq.emplace(e, v);
    }
    return ans;
  }
};
