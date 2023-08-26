class Solution {
public:
  int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    int d[n]; fill(d, d + n, 1);

    // By sorting, if there is a pair P,
    // All pairs than CAN go before P comes before P
    sort(pairs.begin(), pairs.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (pairs[i][0] > pairs[j][1]) {
          d[i] = max(d[i], d[j] + 1);
        }
      }
      ans = max(ans, d[i]);
    }

    return ans;
  }
};
