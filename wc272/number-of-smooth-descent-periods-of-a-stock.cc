class Solution {
public:
  long long getDescentPeriods(vector<int>& prices) {
    long long ans = 0;
    long long streak = 1;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] + 1 == prices[i - 1]) streak++;
      else {
        ans += (streak * (streak + 1) / 2);
        streak = 1;
      }
    }
    ans += (streak * (streak + 1) / 2);
    return ans;
  }
};
