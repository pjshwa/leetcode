class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    int m = stamp.size(), n = target.size();
    vector<pair<set<int>, set<int>>> v(n);
    vector<int> vis(n), ans;

    queue<int> q;
    for (int i = 0; i < n - m + 1; i++) {
      for (int j = 0; j < m; j++) {
        if (stamp[j] == target[i + j]) v[i].first.insert(i + j);
        else v[i].second.insert(i + j);
      }
      if (v[i].second.empty()) {
        ans.push_back(i);
        for (int j = 0; j < m; j++) {
          if (vis[i + j]) continue;

          vis[i + j] = 1;
          q.push(i + j);
        }
      }
    }

    while (!q.empty()) {
      int i = q.front(); q.pop();

      for (int j = max(0, i - m + 1); j <= i; j++) {
        if (!v[j].second.count(i)) continue;

        v[j].second.erase(i);
        if (!v[j].second.empty()) continue;

        ans.push_back(j);
        for (int k : v[j].first) {
          if (vis[k]) continue;

          vis[k] = 1;
          q.push(k);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (!vis[i]) return {};
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
