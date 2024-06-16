using ll = long long;
const int MAX = 1e6;

class Solution {
  int dcost[MAX + 1];

public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    ll lcost = 0, rcost = 0, n = nums.size(), ans = 0;

    memset(dcost, 0, sizeof(dcost));
    for (int i = 0; i < n; i++) {
      dcost[nums[i]] += cost[i];
      rcost += cost[i];
      ans += (ll)nums[i] * cost[i];
    }

    ll cur = ans;
    for (int i = 1; i <= MAX; i++) {
      cur += lcost; cur -= rcost;
      ans = min(ans, cur);
      rcost -= dcost[i]; lcost += dcost[i];
    }
    return ans;
  }
};
