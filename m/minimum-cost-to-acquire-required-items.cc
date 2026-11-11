using ll = long long;

class Solution {
public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    ll bcost = min(costBoth, cost1 + cost2), bneed = min(need1, need2);
    ll ans = bcost * bneed; need1 -= bneed; need2 -= bneed;
    ans += min(cost1, costBoth) * (ll)need1 + min(cost2, costBoth) * (ll)need2;
    return ans;
  }
};
