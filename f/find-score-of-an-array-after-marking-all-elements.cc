using pii = pair<int, int>;

class Solution {
public:
  long long findScore(vector<int>& nums) {
    int N = nums.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < N; i++) pq.push({nums[i], i});

    long long ans = 0; vector<bool> vis(N, false);
    while (!pq.empty()) {
      auto [v, i] = pq.top(); pq.pop();
      if (vis[i]) continue;

      ans += v;
      for (int di : {1, 0, -1}) {
        int ni = i + di;
        if (ni < 0 || ni >= N || vis[ni]) continue;
        vis[ni] = true;
      }
    }
    return ans;
  }
};
