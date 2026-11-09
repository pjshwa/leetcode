using pii = pair<int,int>;

class Solution {
public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> P(k); int N = arrival.size();
    set<int> free; for (int i = 0; i < k; ++i) free.insert(i);
    priority_queue<pii, vector<pii>, greater<pii>> busy;

    for (int i = 0; i < N; ++i) {
      int s = arrival[i], t = load[i];
      while (!busy.empty() && busy.top().first <= s) {
        auto [_, j] = busy.top(); busy.pop();
        free.insert(j);
      }
      if (free.empty()) continue;
      auto it = free.lower_bound(i % k);
      if (it == free.end()) it = free.begin();
      int j = *it; free.erase(it);
      ++P[j]; busy.push({s + t, j});
    }

    int maxp = *max_element(P.begin(), P.end());
    vector<int> ans;
    for (int i = 0; i < k; ++i) if (P[i] == maxp) ans.push_back(i);
    return ans;
  }
};
