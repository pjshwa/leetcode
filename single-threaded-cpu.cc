using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

class Solution {
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    ll ctime = 0, n = tasks.size();

    priority_queue<tii, vector<tii>, greater<tii>> wait;
    priority_queue<pii, vector<pii>, greater<pii>> ready;
    vector<int> order;

    for (int i = 0; i < n; i++) {
      auto task = tasks[i];
      wait.push({task[0], task[1], i});
    }

    // CPU
    while (1) {
      while (!wait.empty()) {
        auto [t, p, i] = wait.top();
        if (t > ctime) break;
        
        wait.pop();
        ready.push({p, i});
      }

      if (ready.empty()) {
        if (wait.empty()) break;
        auto [t, p, i] = wait.top();
        wait.pop();
        ready.push({p, i});
        ctime = t;
      }

      auto [t, i] = ready.top(); ready.pop();
      ctime += t;
      order.push_back(i);
    }

    return order;
  }
};
