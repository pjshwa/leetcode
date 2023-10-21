class Solution {
public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    pq.emplace(nums[0], 0);

    int N = nums.size(), ans = nums[0];
    for (int i = 1; i < N; ++i) {
      while (pq.top().second < i - k) pq.pop();
      int cur = max(nums[i], nums[i] + pq.top().first);
      ans = max(ans, cur);
      pq.emplace(cur, i);
    }

    return ans;
  }
};
