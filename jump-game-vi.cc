const int MAX = 1e5, INF = 1e9 + 7;
using pii = pair<int, int>;

class Solution {
  int d[MAX];
public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pii> pq;

    for (int i = 0; i < n; i++) {
      while (!pq.empty() && i - pq.top().second > k) pq.pop();
      int t = pq.empty() ? 0 : pq.top().first;
      d[i] = t + nums[i];
      pq.push({d[i], i});
    }

    return d[n - 1];
  }
};
