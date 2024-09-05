class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int sum = mean * (m + n), diff = sum - accumulate(rolls.begin(), rolls.end(), 0);
    if (diff < n || diff > 6 * n) return {};

    vector<int> E(n, 1); diff -= n;
    for (int i = 0; i < n; ++i) {
      int d = min(5, diff);
      E[i] += d; diff -= d;
    }
    return E;
  }
};
