class Solution {
public:
  long long continuousSubarrays(vector<int>& nums) {
    long long ans = 0, N = nums.size();

    priority_queue<pair<int, int>> pq_max;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_min;

    int r = 0;
    for (int l = 0; l < N; l++) {
      if (pq_max.empty()) {
        pq_max.push({nums[l], l});
        pq_min.push({nums[l], l});
        r++;
      }
      while (r < N) {
        int e = nums[r];
        int new_max = max(e, pq_max.top().first), new_min = min(e, pq_min.top().first);
        if (new_max - new_min > 2) break;

        pq_max.push({e, r});
        pq_min.push({e, r});
        r++;
      }

      ans += r - l;
      while (!pq_max.empty() && pq_max.top().second <= l) pq_max.pop();
      while (!pq_min.empty() && pq_min.top().second <= l) pq_min.pop();
    }

    return ans;
  }
};
