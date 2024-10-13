using tii = tuple<int, int, int>;

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int G = nums.size();
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    int ans = INT_MAX, maxv = INT_MIN, ansl, ansr;
    for (int i = 0; i < G; ++i) {
      pq.push({nums[i][0], i, 0});
      maxv = max(maxv, nums[i][0]);
    }
    while (1) {
      auto [minv, g, i] = pq.top(); pq.pop();
      if (maxv - minv < ans) {
        ans = maxv - minv;
        ansl = minv;
        ansr = maxv;
      }
      if (++i == nums[g].size()) break;
      int x = nums[g][i];
      pq.push({x, g, i}); maxv = max(maxv, x);
    }
    return {ansl, ansr};
  }
};
