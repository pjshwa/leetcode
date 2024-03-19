class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    map<char, int> tal;
    for (char& c : tasks) ++tal[c];

    priority_queue<int> pq;
    for (auto& p : tal) pq.push(p.second);

    queue<pair<int, int>> q;
    int ans = 0;
    while (!pq.empty() || !q.empty()) {
      while (!q.empty() && ans - q.front().first > n) {
        pq.push(q.front().second);
        q.pop();
      }
      if (!pq.empty()) {
        int t = pq.top(); pq.pop();
        if (t > 1) q.push({ans, t - 1});
      }
      ++ans;
    }

    return ans;
  }
};
