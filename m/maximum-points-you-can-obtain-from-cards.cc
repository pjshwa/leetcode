class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int ans = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
    int n = cardPoints.size(), cur = ans;
    for (int i = 0; i < k; i++) {
      cur -= cardPoints[k - 1 - i];
      cur += cardPoints[n - 1 - i];
      ans = max(ans, cur);
    }
    return ans;
  }
};
