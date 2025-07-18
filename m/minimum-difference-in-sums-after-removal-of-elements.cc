using ll = long long;

class Solution {
public:
  long long minimumDifference(vector<int>& nums) {
    ll N = nums.size() / 3, sum;
    vector<ll> R(3 * N, 0);

    priority_queue<ll, vector<ll>, greater<ll>> pqr; sum = 0;
    for (int i = 3 * N - 1; i >= 2 * N; --i) {
      pqr.push(nums[i]), sum += nums[i];
      R[i] = sum;
    }
    for (int i = 2 * N - 1; i >= N; --i) {
      if (pqr.top() < nums[i]) {
        sum += nums[i] - pqr.top();
        pqr.pop();
        pqr.push(nums[i]);
      }
      R[i] = sum;
    }

    priority_queue<ll> pql; sum = 0;
    for (int i = 0; i < N; ++i) {
      pql.push(nums[i]), sum += nums[i];
    }
    ll ans = sum - R[N];
    for (int i = N; i < 2 * N; ++i) {
      if (pql.top() > nums[i]) {
        sum += nums[i] - pql.top();
        pql.pop();
        pql.push(nums[i]);
      }
      ans = min(ans, sum - R[i + 1]);
    }
    return ans;
  }
};
