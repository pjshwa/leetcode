using pii = pair<int, int>;

class Solution {
public:
  int maxWidthRamp(vector<int>& nums) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < nums.size(); ++i) pq.push({nums[i], i});

    int mini = nums.size(), ans = 0;
    while (!pq.empty()) {
      auto [x, i] = pq.top(); pq.pop();
      ans = max(ans, i - mini);
      mini = min(mini, i);
    }
    return ans;
  }
};
