class Solution {
public:
  int shareCandies(vector<int>& candies, int k) {
    map<int, int> tal;
    auto inc = [&](int x, int d) {
      tal[x] += d;
      if (tal[x] == 0) tal.erase(x);
    };

    int N = candies.size();
    for (int i = k; i < N; ++i) inc(candies[i], 1);
    int ans = tal.size();

    for (int i = 0; i + k < N; ++i) {
      inc(candies[i + k], -1);
      inc(candies[i], 1);
      ans = max(ans, (int)tal.size());
    }
    return ans;
  }
};
