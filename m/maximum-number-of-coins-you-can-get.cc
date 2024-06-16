class Solution {
public:
  int maxCoins(vector<int>& piles) {
    int N = piles.size();
    sort(piles.begin(), piles.end(), greater<int>());

    int ans = 0, it = N / 3, i = 1;
    while (it--) {
      ans += piles[i];
      i += 2;
    }
    return ans;
  }
};
