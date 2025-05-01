class Solution {
  bool check(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    priority_queue<int> tq; multiset<int> ws;
    for (int i = 0; i < k; ++i) tq.push(tasks[i]);
    for (int i = 0; i < k; ++i) ws.insert(workers[i]);

    while (!tq.empty()) {
      int t = tq.top(); tq.pop();
      auto it1 = ws.lower_bound(t);
      if (it1 != ws.end()) ws.erase(it1);
      else if (pills > 0) {
        auto it2 = ws.lower_bound(t - strength);
        if (it2 != ws.end()) --pills, ws.erase(it2);
      }
    }
    return ws.empty();
  }

public:
  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end(), greater<int>());

    int l = 1, r = min(tasks.size(), workers.size()) + 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (check(m, tasks, workers, pills, strength)) l = m + 1;
      else r = m;
    }
    return l - 1;
  }
};
