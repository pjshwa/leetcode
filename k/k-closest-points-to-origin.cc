using tii = tuple<int, int, int>;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    for (auto& p : points) {
      int x = p[0], y = p[1], d = x * x + y * y;
      pq.push({d, x, y});
    }
    
    vector<vector<int>> ans;
    while (k--) {
      auto [wi, x, y] = pq.top();
      pq.pop();
      ans.push_back({x, y});
    }
    return ans;
  }
};
