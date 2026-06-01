class Solution {
public:
  int minimumCost(vector<int>& cost) {
    sort(cost.begin(), cost.end());
    int ans = accumulate(cost.begin(), cost.end(), 0);
    while (cost.size() >= 3) {
      cost.pop_back(); cost.pop_back();
      ans -= cost.back();
      cost.pop_back();
    }
    return ans;
  }
};
