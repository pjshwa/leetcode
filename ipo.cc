using pii = pair<int, int>;

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    priority_queue<pii> pq;
    priority_queue<pii, vector<pii>, greater<pii>> wait;
    for (int i = 0; i < n; i++) wait.push({capital[i], profits[i]});

    while (k--) {
      while (!wait.empty()) {
        auto [c, p] = wait.top();
        if (c > w) break;
        pq.push({p, c});
        wait.pop();
      }

      if (pq.empty()) break;
      auto [p, c] = pq.top(); pq.pop();
      w += p;
    }
    return w;
  }
};
