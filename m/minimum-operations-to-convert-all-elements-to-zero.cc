class Solution {
public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    vector<int> parent(n); iota(parent.begin(), parent.end(), 0);
    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    vector<int> unique_vals = nums;
    sort(unique_vals.begin(), unique_vals.end());
    unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
    reverse(unique_vals.begin(), unique_vals.end());

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) pq.emplace(nums[i], i);

    int ans = 0;
    vector<int> indices, visited(n);
    for (int val : unique_vals) {
      if (val == 0) break;
      while (!pq.empty() && pq.top().first == val) {
        int idx = pq.top().second; pq.pop();
        indices.push_back(idx);
      }
      for (int idx : indices) visited[idx] = 1;
      for (int idx : indices) {
        if (idx > 0 && visited[idx - 1]) Union(idx, idx - 1);
        if (idx + 1 < n && visited[idx + 1]) Union(idx, idx + 1);
      }

      set<int> uniq_g;
      for (int idx : indices) uniq_g.insert(Find(idx));
      ans += uniq_g.size();
      indices.clear();
    }
    return ans;
  }
};
