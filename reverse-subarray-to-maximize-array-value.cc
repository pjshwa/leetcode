using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
  int maxValueAfterReverse(vector<int>& nums) {
    int N = nums.size();

    ll sum = 0;
    for (int i = 0; i < N - 1; ++i) {
      sum += abs(nums[i] - nums[i + 1]);
    }

    ll ans = sum;
    for (int i = 1; i < N - 1; ++i) {
      ll cur1 = sum - abs(nums[i] - nums[i + 1]) + abs(nums[0] - nums[i + 1]);
      ll cur2 = sum - abs(nums[i] - nums[i - 1]) + abs(nums[N - 1] - nums[i - 1]);
      ans = max({ans, cur1, cur2});
    }

    // stores min(A_r + A_{r + 1})
    priority_queue<pii, vector<pii>, greater<pii>> pq1;

    // stores min(A_r - A_{r + 1})
    priority_queue<pii, vector<pii>, greater<pii>> pq2;

    // stores max(A_r + A_{r + 1})
    priority_queue<pii> pq3;

    // stores max(A_r - A_{r + 1})
    priority_queue<pii> pq4;

    for (int i = 1; i < N - 1; ++i) {
      int cost = abs(nums[i] - nums[i + 1]);

      pq1.emplace(nums[i] + nums[i + 1] + cost, i);
      pq2.emplace(nums[i] - nums[i + 1] + cost, i);
      pq3.emplace(nums[i] + nums[i + 1] - cost, i);
      pq4.emplace(nums[i] - nums[i + 1] - cost, i);
    }

    for (int l = 1; l < N - 1; ++l) {
      while (!pq1.empty() && pq1.top().second <= l) pq1.pop();
      while (!pq2.empty() && pq2.top().second <= l) pq2.pop();
      while (!pq3.empty() && pq3.top().second <= l) pq3.pop();
      while (!pq4.empty() && pq4.top().second <= l) pq4.pop();

      vector<int> candidates;
      if (!pq1.empty()) candidates.push_back(pq1.top().second);
      if (!pq2.empty()) candidates.push_back(pq2.top().second);
      if (!pq3.empty()) candidates.push_back(pq3.top().second);
      if (!pq4.empty()) candidates.push_back(pq4.top().second);

      for (int r : candidates) {
        ll cur = sum - abs(nums[l] - nums[l - 1]) - abs(nums[r] - nums[r + 1]);
        cur += abs(nums[r] - nums[l - 1]) + abs(nums[l] - nums[r + 1]);
        ans = max(ans, cur);
      }
    }

    return ans;
  }
};
