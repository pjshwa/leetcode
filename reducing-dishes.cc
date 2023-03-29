class Solution {
public:
  int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end(), greater<int>());

    int P[n];
    P[0] = satisfaction[0];
    for (int i = 1; i < n; i++) P[i] = P[i - 1] + satisfaction[i];

    int ans = 0, pre = 0;
    for (int v = 0; v < n; v++) {
      pre += P[v];
      ans = max(ans, pre);
    }
    return ans;
  }
};
