using ll = long long;

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int e : nums) pq.push(e);

    int ans = 0;
    while (pq.top() < k) {
      ll s = pq.top(); pq.pop();
      ll t = pq.top(); pq.pop();
      pq.push(min(s, t) * 2 + max(s, t));
      ++ans;
    }
    return ans;
  }
};
