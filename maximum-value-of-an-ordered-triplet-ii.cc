class Solution {
public:
  long long maximumTripletValue(vector<int>& nums) {
    int N = nums.size();

    priority_queue<pair<int, int>> pq_L, pq_R;
    for (int i = 2; i < N; ++i) pq_R.emplace(nums[i], i);
    pq_L.emplace(nums[0], 0);

    long long ans = 0;
    for (int i = 1; i < N - 1; ++i) {
      while (pq_R.top().second <= i) pq_R.pop();

      long long val_L = pq_L.top().first, val_R = pq_R.top().first;
      ans = max(ans, (val_L - nums[i]) * val_R);

      pq_L.emplace(nums[i], i);
    }

    return ans;
  }
};
