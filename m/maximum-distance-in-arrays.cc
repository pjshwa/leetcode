using pii = pair<int, int>;

class Solution {
public:
  int maxDistance(vector<vector<int>>& arrays) {
    priority_queue<pii> pq_max;
    int ans = 0, Z = arrays.size();
    for (int i = 0; i < Z; ++i) pq_max.push({arrays[i].back(), i});
    for (int i = 0; i < Z; ++i) {
      while (pq_max.top().second == i) pq_max.pop();
      ans = max(ans, pq_max.top().first - arrays[i].front());
      pq_max.push({arrays[i].back(), i});
    }
    return ans;
  }
};
